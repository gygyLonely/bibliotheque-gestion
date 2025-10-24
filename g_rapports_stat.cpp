#include "g_rapports_stat.h"
#include "ui_g_rapports_stat.h"
#include <QDebug>
#include <QDialog>
#include <QList>
#include <QFile>
#include <QTextStream>


g_rapports_stat::g_rapports_stat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::g_rapports_stat)
{
    ui->setupUi(this);
    // Connecter les boutons
    connect(ui->pushButton, &QPushButton::clicked, this, &g_rapports_stat::on_btn_stats_lecteurs_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &g_rapports_stat::on_btn_stats_livres_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &g_rapports_stat::on_btn_stats_prets_clicked);
    // connect(ui->pushButton_4, &QPushButton::clicked, this, &g_rapports_stat::on_btn_stats_general_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &g_rapports_stat::on_btn_retour_clicked);

    // Afficher les stats générales au démarrage
    on_btn_stats_general_clicked();
}

// COPIER ces fonctions depuis g_prets_window.cpp
QList<QStringList> g_rapports_stat::chargerLecteurs()
{
    QList<QStringList> lecteurs;
    QFile fichier("lecteurs.dat");
    if (fichier.open(QIODevice::ReadOnly)) {
        QTextStream flux(&fichier);
        while (!flux.atEnd()) {
            QString ligne = flux.readLine();
            QStringList parts = ligne.split("|");
            if (parts.size() == 2) {
                lecteurs.append(parts);
            }
        }
        fichier.close();
    }
    return lecteurs;
}

QList<QStringList> g_rapports_stat::chargerTousLesLivres()
{
    QList<QStringList> livres;
    QFile fichier("livres.dat");
    if (fichier.open(QIODevice::ReadOnly)) {
        QTextStream flux(&fichier);
        while (!flux.atEnd()) {
            QString ligne = flux.readLine();
            QStringList livre = ligne.split("|");
            if (livre.size() == 5) {
                livres.append(livre);
            }
        }
        fichier.close();
    }
    return livres;
}

QList<QStringList> g_rapports_stat::chargerPrets()
{
    QList<QStringList> prets;
    QFile fichier("prets.dat");
    if (fichier.open(QIODevice::ReadOnly)) {
        QTextStream flux(&fichier);
        while (!flux.atEnd()) {
            QString ligne = flux.readLine().trimmed();
            if (ligne.isEmpty()) continue;
            QStringList pret = ligne.split("|");
            while (!pret.isEmpty() && pret.last().isEmpty()) {
                pret.removeLast();
            }
            if (pret.size() >= 5) {
                prets.append(pret);
            }
        }
        fichier.close();
    }
    return prets;
}

// STATISTIQUES GENERALES
// void g_rapports_stat::on_btn_stats_general_clicked()
// {
//     ui->listWidget->clear();

//     QList<QStringList> lecteurs = chargerLecteurs();
//     QList<QStringList> livres = chargerTousLesLivres();
//     QList<QStringList> prets = chargerPrets();

//     ui->listWidget->addItem("VUE D'ENSEMBLE");
//     ui->listWidget->addItem("==============");
//     ui->listWidget->addItem("");

//     ui->listWidget->addItem("Lecteurs inscrits: " + QString::number(lecteurs.size()));
//     ui->listWidget->addItem("Livres au catalogue: " + QString::number(livres.size()));
//     ui->listWidget->addItem("Total des prets: " + QString::number(prets.size()));
// }




// STATISTIQUES LECTEURS
void g_rapports_stat::on_btn_stats_lecteurs_clicked()
{
    ui->listWidget->clear();

    QList<QStringList> lecteurs = chargerLecteurs();
    QList<QStringList> prets = chargerPrets();

    ui->listWidget->addItem("STATISTIQUES LECTEURS");
    ui->listWidget->addItem("====================");
    ui->listWidget->addItem("");

    ui->listWidget->addItem("Nombre total de lecteurs: " + QString::number(lecteurs.size()));

    // Lecteurs avec prets en cours
    QSet<QString> lecteursActifs;
    for (const QStringList& pret : prets) {
        if (pret.size() < 6 || pret[5].isEmpty()) {
            lecteursActifs.insert(pret[1]);
        }
    }

    ui->listWidget->addItem("Lecteurs avec prets en cours: " + QString::number(lecteursActifs.size()));
}

// STATISTIQUES LIVRES
void g_rapports_stat::on_btn_stats_livres_clicked()
{
    ui->listWidget->clear();

    QList<QStringList> livres = chargerTousLesLivres();

    ui->listWidget->addItem("STATISTIQUES LIVRES");
    ui->listWidget->addItem("===================");
    ui->listWidget->addItem("");

    int livresDisponibles = 0;
    for (const QStringList& livre : livres) {
        if (livre[4] == "Oui") livresDisponibles++;
    }

    ui->listWidget->addItem("Total livres: " + QString::number(livres.size()));
    ui->listWidget->addItem("Livres disponibles: " + QString::number(livresDisponibles));
    ui->listWidget->addItem("Livres empruntes: " + QString::number(livres.size() - livresDisponibles));
}

// STATISTIQUES PRETS
void g_rapports_stat::on_btn_stats_prets_clicked()
{
    ui->listWidget->clear();

    QList<QStringList> prets = chargerPrets();
    QDate aujourdhui = QDate::currentDate();

    ui->listWidget->addItem("STATISTIQUES PRETS");
    ui->listWidget->addItem("==================");
    ui->listWidget->addItem("");

    int pretsEnCours = 0;
    int pretsRendus = 0;
    int pretsEnRetard = 0;

    for (const QStringList& pret : prets) {
        if (pret.size() < 6 || pret[5].isEmpty()) {
            pretsEnCours++;

            // Verifier les retards
            QDate dateRetourPrevue = QDate::fromString(pret[4], "dd-MM-yyyy");
            if (aujourdhui > dateRetourPrevue) {
                pretsEnRetard++;
            }
        } else {
            pretsRendus++;
        }
    }

    ui->listWidget->addItem("Prets en cours: " + QString::number(pretsEnCours));
    ui->listWidget->addItem("Prets rendus: " + QString::number(pretsRendus));
    ui->listWidget->addItem("Prets en retard: " + QString::number(pretsEnRetard));

    if (pretsEnRetard > 0) {
        ui->listWidget->addItem("Amendes totales: " + QString::number(pretsEnRetard * 5000) + " Fmg");
    }
}

// BOUTON RETOUR
void g_rapports_stat::on_btn_retour_clicked()
{
    this->close();  // Ferme la fenetre des rapports
}

// ✅ AJOUTE CETTE FONCTION MANQUANTE
void g_rapports_stat::on_btn_stats_general_clicked()
{
    ui->listWidget->clear();

    // Charger toutes les données
    QList<QStringList> lecteurs = chargerLecteurs();
    QList<QStringList> livres = chargerTousLesLivres();
    QList<QStringList> prets = chargerPrets();

    ui->listWidget->addItem("VUE D'ENSEMBLE");
    ui->listWidget->addItem("==============");
    ui->listWidget->addItem("");

    // Statistiques générales
    ui->listWidget->addItem("Lecteurs inscrits: " + QString::number(lecteurs.size()));
    ui->listWidget->addItem("Livres au catalogue: " + QString::number(livres.size()));
    ui->listWidget->addItem("Total des prets: " + QString::number(prets.size()));
    ui->listWidget->addItem("");

    // Calcul disponibilité
    int livresDisponibles = 0;
    for (const QStringList& livre : livres) {
        if (livre[4] == "Oui") livresDisponibles++;
    }

    if (livres.size() > 0) {
        int tauxDispo = (livresDisponibles * 100) / livres.size();
        ui->listWidget->addItem("Taux de disponibilite: " + QString::number(tauxDispo) + "%");
    }

    // Prêts en cours
    int pretsEnCours = 0;
    for (const QStringList& pret : prets) {
        if (pret.size() < 6 || pret[5].isEmpty()) {
            pretsEnCours++;
        }
    }

    ui->listWidget->addItem("Prets en cours: " + QString::number(pretsEnCours));
}


g_rapports_stat::~g_rapports_stat()
{
    delete ui;
}
