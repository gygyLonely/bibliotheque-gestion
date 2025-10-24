#include "lecteurs.h"

lecteurs::lecteurs() {

}
#include <QMessageBox>
#include "g_lecteurs_window.h"
#include "ui_g_lecteurs_window.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

G_Lecteurs_Window::G_Lecteurs_Window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::G_Lecteurs_Window)
{
    ui->setupUi(this);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &G_Lecteurs_Window::on_tout_supprimer_clicked);

    // Cache les éléments du formulaire au début
    ui->lineEdit_numero->hide();
    ui->lineEdit_nom->hide();
    ui->buttonBox->hide();
    ui->pushButton_5->hide();

    // Affiche un message d'accueil
    ui->listWidget->clear();
    // ui->listWidget->addItem("BIENVENUE");
    QListWidgetItem* welcomeItem = new QListWidgetItem("BIENVENUE");
    welcomeItem->setTextAlignment(Qt::AlignCenter);
    ui->listWidget->addItem(welcomeItem);

}

void G_Lecteurs_Window::sauvegarderLecteur(const QString& numero, const QString& nom)
{
    QFile fichier("lecteurs.dat");
    if (fichier.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream flux(&fichier);
        flux << numero << "|" << nom << "\n";
        fichier.close();
        qDebug() << "Lecteur sauvegarde :" << numero << "-" << nom;
    }
}

QList<QStringList> G_Lecteurs_Window::chargerLecteurs()
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

void G_Lecteurs_Window:ajouter()
{
    // Montrer la liste, cacher le formulaire
    ui->pushButton_5->hide();
    ui->lineEdit_numero->hide();
    ui->lineEdit_nom->hide();
    ui->buttonBox->hide();
    ui->listWidget->addItem(">LECTEURS");
    ui->listWidget->show();


    // Charger et afficher les lecteurs
    ui->listWidget->clear();
    QList<QStringList> tousLesLecteurs = chargerLecteurs();

    for (const QStringList& lecteur : tousLesLecteurs) {
        QString affichage = lecteur[0] + " - " + lecteur[1];
        ui->listWidget->addItem(affichage);
    }

    if (tousLesLecteurs.isEmpty()) {
        ui->listWidget->addItem("Aucun lecteur enregistre");
        ui->listWidget->addItem("Utilisez AJOUTER pour commencer");
    }
}

void G_Lecteurs_Window::lister()
{
    // Cacher la liste, montrer le formulaire
    ui->listWidget->hide();
    ui->pushButton_5->hide();
    ui->lineEdit_numero->show();
    ui->lineEdit_nom->show();
    ui->buttonBox->show();
    ui->lineEdit_numero->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_numero->setFocus();
}

void G_Lecteurs_Window::on_buttonBox_accepted()
{
    ui->pushButton_5->hide();
    QString numero = ui->lineEdit_numero->text();
    QString nom = ui->lineEdit_nom->text();

    if (numero.isEmpty() || nom.isEmpty()) {
        qDebug() << "Erreur: Champs vides";
        return;
    }

    sauvegarderLecteur(numero, nom);
    qDebug() << "Lecteur ajoute:" << numero << "-" << nom;

    // Retourner a l'etat initial
    ui->lineEdit_numero->hide();
    ui->lineEdit_nom->hide();
    ui->buttonBox->hide();
    ui->listWidget->show();

    // Optionnel: actualiser la liste
    on_pushButton_3_clicked();
}

void G_Lecteurs_Window::on_buttonBox_rejected()
{
    // Annuler et retourner a l'etat initial
    ui->pushButton_5->hide();
    ui->lineEdit_numero->hide();
    ui->lineEdit_nom->hide();
    ui->buttonBox->hide();
    ui->listWidget->show();
}

void G_Lecteurs_Window::supprimer()
{
    this->close();
}

void G_Lecteurs_Window::retour()
{
    // Montrer la liste pour selectionner un lecteur a supprimer
    ui->lineEdit_numero->hide();
    ui->lineEdit_nom->hide();
    ui->buttonBox->hide();
    ui->listWidget->show();
    ui->pushButton_5->show();  // Montrer le bouton TOUT SUPPRIMER

    // Charger et afficher les lecteurs
    ui->listWidget->clear();
    QList<QStringList> tousLesLecteurs = chargerLecteurs();

    for (const QStringList& lecteur : tousLesLecteurs) {
        QString affichage = lecteur[0] + " - " + lecteur[1];
        ui->listWidget->addItem(affichage);
    }

    if (tousLesLecteurs.isEmpty()) {
        ui->listWidget->addItem("Aucun lecteur a supprimer");
        ui->pushButton_5->hide();  // Cacher si pas de lecteurs
        return;
    }

    // Ajouter des instructions
    QListWidgetItem* instructionItem = new QListWidgetItem("Selectionnez un lecteur a supprimer");
    instructionItem->setTextAlignment(Qt::AlignCenter);
    ui->listWidget->insertItem(0, instructionItem);

    QListWidgetItem* emptyItem = new QListWidgetItem("");
    ui->listWidget->insertItem(1, emptyItem);
}

// Fonction pour supprimer un lecteur du fichier
 item)
{
    QString texte = item->text();

    // Vérifier si c'est un élément de lecteur (format "numero - nom")
    if (texte.contains(" - ")) {
        QString numero = texte.split(" - ")[0];

        // Demander confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation",
                                      "Voulez-vous vraiment supprimer le lecteur : " + texte + " ?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            supprimerLecteur(numero);
            // Actualiser l'affichage
            on_pushButton_2_clicked();
        }
    }
}
void G_Lecteurs_Window::supprimerLecteur(const QString& numero)
{
    QList<QStringList> tousLesLecteurs = chargerLecteurs();

    QFile fichier("lecteurs.dat");
    if (fichier.open(QIODevice::WriteOnly)) {
        QTextStream flux(&fichier);

        for (const QStringList& lecteur : tousLesLecteurs) {
            if (lecteur[0] != numero) {
                // Réécrire tous les lecteurs sauf celui à supprimer
                flux << lecteur[0] << "|" << lecteur[1] << "\n";
            }
        }
        fichier.close();
        qDebug() << "Lecteur supprime :" << numero;
    }
}

// Fonction pour gérer la sélection dans la liste
void G_Lecteurs_Window::on_listWidget_itemDoubleClicked(QListWidgetItem*

void G_Lecteurs_Window::on_tout_supprimer_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer TOUS les lecteurs ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QFile fichier("lecteurs.dat");
        if (fichier.open(QIODevice::WriteOnly)) {
            fichier.close();  // Crée un fichier vide
            qDebug() << "Tous les lecteurs ont ete supprimes";
        }

        // Actualiser l'affichage
        on_pushButton_2_clicked();  // Recharger la vue suppression
    }
}


G_Lecteurs_Window::~G_Lecteurs_Window()
{
    delete ui;
}
