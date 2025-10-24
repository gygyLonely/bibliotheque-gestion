#include "g_livres_window.h"
#include "ui_g_livres_window.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

g_livres_window::g_livres_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::g_livres_window)
{
    ui->setupUi(this);

    ui->input_rech->hide();
    ui->but_rech->hide();
    ui->pushButton_6->hide();
    ui->listWidget->hide();
    ui->label_5->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->lineEdit->hide();      // numero
    ui->lineEdit_2->hide();    // titre
    ui->lineEdit_3->hide();    // auteur
    ui->dateEdit->hide();      // date
    ui->buttonBox->hide();     // boutons OK/Annuler

    connect(ui->but_rech, &QPushButton::clicked, this, &g_livres_window::on_but_rech_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &g_livres_window::on_lister);
    connect(ui->pushButton, &QPushButton::clicked, this, &g_livres_window::on_ajouter);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &g_livres_window::on_supprimer);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &g_livres_window::on_tout_supprimer_clicked);
}

// ✅ AJOUTE CETTE FONCTION pour la recherche de livres
void g_livres_window::on_but_rech_clicked()
{
    QString recherche = ui->input_rech->text().trimmed().toLower();

    if (recherche.isEmpty()) {
        // Si la recherche est vide, afficher tous les livres
        on_lister();
        return;
    }

    // Charger tous les livres
    QList<QStringList> tousLesLivres = chargerLivres();

    // Filtrer selon la recherche
    ui->listWidget->clear();
    int resultatsTrouves = 0;

    for (const QStringList& livre : tousLesLivres) {
        QString numero = livre[0].toLower();
        QString titre = livre[1].toLower();
        QString auteur = livre[2].toLower();

        // Vérifier si le numéro OU le titre OU l'auteur contient le texte recherché
        if (numero.contains(recherche) || titre.contains(recherche) || auteur.contains(recherche)) {
            QString affichage = livre[0] + " - " + livre[1] + " (" + livre[2] + ", " + livre[3] + ")";
            ui->listWidget->addItem(affichage);
            resultatsTrouves++;
        }
    }

    // Message si aucun résultat
    if (resultatsTrouves == 0) {
        ui->listWidget->addItem("Aucun livre trouvé pour : \"" + ui->input_rech->text() + "\"");
        ui->listWidget->addItem("Essayez avec un autre terme de recherche");
    } else {
        ui->listWidget->addItem("");
        ui->listWidget->addItem("📚 " + QString::number(resultatsTrouves) + " livre(s) trouvé(s)");
    }
}


void g_livres_window::sauvegarderLivre(const QString& numero, const QString& titre, const QString& auteur, const QString& date)
{
    QFile fichier("livres.dat");
    if (fichier.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream flux(&fichier);
        flux << numero << "|" << titre << "|" << auteur << "|" << date << "|Oui\n";
        fichier.close();
        qDebug() << "Livre sauvegarde :" << numero << "-" << titre;
    }
}

QList<QStringList> g_livres_window::chargerLivres()
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

void g_livres_window::on_ajouter()  // AJOUTER
{
    ui->listWidget->hide();
    ui->input_rech->hide();
    ui->but_rech->hide();

    ui->label_5->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();

    ui->lineEdit->show();      // numero
    ui->lineEdit_2->show();    // titre
    ui->lineEdit_3->show();    // auteur
    ui->dateEdit->show();      // date
    ui->buttonBox->show();     // boutons OK/Annuler

    // ⭐⭐ VIDER LES CHAMPS ⭐⭐
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->dateEdit->setDate(QDate::currentDate()); // date du jour

    qDebug() << "Formulaire affiche pour ajout";
}

// void g_livres_window::on_lister() //LISTER
// {
//     qDebug() << "cliquer";
//     // ui->verticalLayout_3->hide();
//     ui->label_5->hide();
//     ui->label_2->hide();
//     ui->label_3->hide();
//     ui->label_4->hide();

//     ui->lineEdit_2->hide();
//     ui->lineEdit->hide();
//     ui->lineEdit_3->hide();
//     ui->dateEdit->hide();
//     ui->buttonBox->hide();
//     ui->listWidget->show();
//     ui->listWidget->clear();

//     QList<QStringList> tousLesLivres = chargerLivres();

//     for (const QStringList& livre : tousLesLivres) {
//         QString affichage = livre[0] + " - " + livre[1] + " (" + livre[2] + ", " + livre[3] + ")";
//         ui->listWidget->addItem(affichage);
//     }

//     if (tousLesLivres.isEmpty()) {
//         ui->listWidget->addItem("Aucun livre enregistre");
//         ui->listWidget->addItem("Utilisez AJOUTER pour commencer");
//     }
// }

void g_livres_window::on_lister() //LISTER
{
    qDebug() << "cliquer";

    // ✅ MONTRER la barre de recherche
    ui->input_rech->show();
    ui->but_rech->show();
    ui->input_rech->clear();
    ui->input_rech->setFocus();

    // Cacher le formulaire
    ui->label_5->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit->hide();
    ui->lineEdit_3->hide();
    ui->dateEdit->hide();
    ui->buttonBox->hide();
    ui->pushButton_6->hide();

    // Montrer la liste
    ui->listWidget->show();
    ui->listWidget->clear();

    // Charger et afficher tous les livres
    QList<QStringList> tousLesLivres = chargerLivres();

    for (const QStringList& livre : tousLesLivres) {
        QString affichage = livre[0] + " - " + livre[1] + " (" + livre[2] + ", " + livre[3] + ")";
        ui->listWidget->addItem(affichage);
    }

    if (tousLesLivres.isEmpty()) {
        ui->listWidget->addItem("Aucun livre enregistre");
        ui->listWidget->addItem("Utilisez AJOUTER pour commencer");
    } else {
        ui->listWidget->addItem("");
        ui->listWidget->addItem("🔍 Utilisez la barre de recherche pour filtrer");
    }
}


void g_livres_window::on_supprimer()
{
    ui->input_rech->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->but_rech->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->dateEdit->hide();
    ui->buttonBox->hide();

    ui->listWidget->show();
    ui->pushButton_6->show();
    ui->listWidget->clear();

    QList<QStringList> tousLesLivres = chargerLivres();
    for (const QStringList& livre : tousLesLivres) {
        QString affichage = livre[0] + " - " + livre[1] + " (" + livre[2] + ", " + livre[3] + ")";
        ui->listWidget->addItem(affichage);
    }

    if (tousLesLivres.isEmpty()) {
        ui->listWidget->addItem("Aucun livre a supprimer");
        ui->pushButton_6->hide();  // Cacher si pas de livres
    } else {
        ui->listWidget->addItem("");
        ui->listWidget->addItem("--Double-cliquez sur un livre pour le supprimer--");
    }
}

void g_livres_window::on_tout_supprimer_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer TOUS les livres ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QFile fichier("livres.dat");
        if (fichier.open(QIODevice::WriteOnly)) {
            fichier.close();  // Crée un fichier vide
            qDebug() << "Tous les livres supprimes";
        }

        // Actualiser l'affichage
        on_supprimer();
    }
}

void g_livres_window::supprimerLivre(const QString& numero)
{
    QList<QStringList> tousLesLivres = chargerLivres();

    QFile fichier("livres.dat");
    if (fichier.open(QIODevice::WriteOnly)) {
        QTextStream flux(&fichier);

        // Réécrire tous les livres SAUF celui à supprimer
        for (const QStringList& livre : tousLesLivres) {
            if (livre[0] != numero) {  // Garder si numéro différent
                flux << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|" << livre[4] << "\n";
            }
        }
        fichier.close();
        qDebug() << "Livre supprime:" << numero;
    }
}

void g_livres_window::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    QString texte = item->text();

    if (texte.contains(" - ")) {
        QString numero = texte.split(" - ")[0];

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation",
                                      "Supprimer le livre : " + texte + " ?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // ⭐⭐ MAINTENANT ON SUPPRIME VRAIMENT ⭐⭐
            supprimerLivre(numero);

            // Recharger la liste
            on_supprimer();
        }
    }
}

void g_livres_window::on_buttonBox_accepted()  // OK
{

    ui->input_rech->hide();
    ui->but_rech->hide();
    ui->label_5->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();

    ui->lineEdit_2->hide();
    ui->lineEdit->hide();
    ui->lineEdit_3->hide();
    ui->dateEdit->hide();
    ui->buttonBox->hide();
    qDebug() << "ok cliker";
    QString numero = ui->lineEdit->text();      //num
    QString titre = ui->lineEdit_2->text();       //titre
    QString auteur = ui->lineEdit_3->text();      //autor
    QString date = ui->dateEdit->text();          //date ngamb

    qDebug() << "Donnees:" << numero << titre << auteur << date;

    // SAUVEGARDER
    sauvegarderLivre(numero, titre, auteur, date);
    ui->listWidget->show();
    ui->listWidget->addItem("Livre ajoute: " + titre);
}

void g_livres_window::on_buttonBox_rejected()  // ANNULER
{
    // CACHER FORMULAIRE, MONTRER LISTE
    // ui->lineEdit_2->hide(); etc...
    ui->listWidget->show();
}

void g_livres_window::on_pushButton_4_clicked()
{
    this->close();
}

g_livres_window::~g_livres_window()
{
    delete ui;
}
