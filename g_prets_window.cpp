#include "g_prets_window.h"
#include "ui_g_prets_window.h"
#include <QDebug>
#include <QDialog>
#include <QList>
#include <QFile>
#include <QTextStream>

g_prets_window::g_prets_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::g_prets_window)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &g_prets_window::on_nouveau_pret_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &g_prets_window::on_lister_prets_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &g_prets_window::on_retour_livre_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &g_prets_window::on_vider_liste_clicked);

    ui->label_5->hide();
    ui->pushButton_5->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->comboBox_lecteurs->hide();
    ui->comboBox_livres->hide();
    ui->dateEdit_pret->hide();
    ui->dateEdit_2->hide();
    ui->buttonBox->hide();
    ui->listWidget->hide();
}

void g_prets_window::on_nouveau_pret_clicked()
{
    qDebug() << "=== NOUVEAU PRET ===";

    // Cacher la liste
    ui->listWidget->hide();
     ui->pushButton_5->hide();

    // Montrer le formulaire
    ui->comboBox_lecteurs->show();
    ui->comboBox_livres->show();
    ui->dateEdit_pret->show();
    ui->dateEdit_2->show();  // ← dateEdit_2 au lieu de dateEdit_retour
    ui->buttonBox->show();

    // Remplir combobox lecteurs
    ui->comboBox_lecteurs->clear();
    QList<QStringList> lecteurs = chargerLecteurs();
    for (const QStringList& lecteur : lecteurs) {
        ui->comboBox_lecteurs->addItem(lecteur[0] + " - " + lecteur[1]);
    }

    // Remplir combobox livres disponibles
    ui->comboBox_livres->clear();
    QList<QStringList> livres = chargerLivresDisponibles();
    for (const QStringList& livre : livres) {
        ui->comboBox_livres->addItem(livre[0] + " - " + livre[1]);
    }

    // Configurer les dates
    ui->dateEdit_pret->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate().addDays(7));  // ← dateEdit_2

    qDebug() << "Formulaire pret affiche avec" << lecteurs.size() << "lecteurs et" << livres.size() << "livres";
}

QList<QStringList> g_prets_window::chargerLecteurs()
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

QList<QStringList> g_prets_window::chargerLivresDisponibles()
{
    QList<QStringList> livres;
    QFile fichier("livres.dat");
    if (fichier.open(QIODevice::ReadOnly)) {
        QTextStream flux(&fichier);
        while (!flux.atEnd()) {
            QString ligne = flux.readLine();
            QStringList livre = ligne.split("|");
            if (livre.size() == 5 && livre[4] == "Oui") {
                livres.append(livre);
            }
        }
        fichier.close();
    }
    return livres;
}

void g_prets_window::on_lister_prets_clicked()
{
    qDebug() << "=== LISTER PRÊTS ===";

    // Cacher le formulaire
    ui->comboBox_lecteurs->hide();
    ui->comboBox_livres->hide();
    ui->dateEdit_pret->hide();
    ui->dateEdit_2->hide();
    ui->buttonBox->hide();


     ui->pushButton_5->show();
    // Montrer la liste
    ui->listWidget->show();
    ui->listWidget->clear();

    // Charger les prêts
    QList<QStringList> tousLesPrets = chargerPrets();

    if (tousLesPrets.isEmpty()) {
        ui->listWidget->addItem("Aucun prêt enregistré");
        ui->listWidget->addItem("Utilisez NOUVEAU PRÊT pour commencer");
        return;
    }

    // Afficher chaque prêt
    for (const QStringList& pret : tousLesPrets) {
        QString statut = (pret.size() == 6 && !pret[5].isEmpty()) ? "✓ RENDU" : "📖 EN COURS";
        QString affichage = pret[0] + " - " + pret[1] + " → " + pret[2] + " (" + pret[3] + " - " + pret[4] + ") " + statut;
        ui->listWidget->addItem(affichage);
    }

    // Statistiques
    int pretsEnCours = 0;
    for (const QStringList& pret : tousLesPrets) {
        if (pret.size() == 5 || pret[5].isEmpty()) {
            pretsEnCours++;
        }
    }

    ui->listWidget->addItem("");
    ui->listWidget->addItem("📊 " + QString::number(pretsEnCours) + " prêt(s) en cours");
}

void g_prets_window::on_buttonBox_accepted()
{
    qDebug() << "OK nouveau prêt cliqué";
    ui->pushButton_5->hide();

    // Récupérer les données
    QString lecteurSelectionne = ui->comboBox_lecteurs->currentText();
    QString livreSelectionne = ui->comboBox_livres->currentText();
    QString datePret = ui->dateEdit_pret->date().toString("dd-MM-yyyy");
    QString dateRetour = ui->dateEdit_2->date().toString("dd-MM-yyyy");

    // Extraire les numéros
    QString numLecteur = lecteurSelectionne.split(" - ")[0];
    QString numLivre = livreSelectionne.split(" - ")[0];

    // Générer un ID de prêt
    QString idPret = "P" + QString::number(QDateTime::currentMSecsSinceEpoch()).right(3);

    // ⭐⭐ 1. SAUVEGARDER LE PRÊT
    QFile fichierPrets("prets.dat");
    if (fichierPrets.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream fluxPrets(&fichierPrets);
        fluxPrets << idPret << "|" << numLecteur << "|" << numLivre << "|" << datePret << "|" << dateRetour << "|\n";
        fichierPrets.close();
        qDebug() << "Prêt sauvegardé :" << idPret;
    }

    // ⭐⭐ 2. METTRE LE LIVRE "INDISPONIBLE"
    QList<QStringList> tousLesLivres = chargerTousLesLivres();
    QFile fichierLivres("livres.dat");
    if (fichierLivres.open(QIODevice::WriteOnly)) {
        QTextStream fluxLivres(&fichierLivres);
        for (const QStringList& livre : tousLesLivres) {
            if (livre[0] == numLivre) {
                // Modifier ce livre pour le rendre indisponible
                fluxLivres << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|Non\n";
            } else {
                // Recopier les autres livres inchangés
                fluxLivres << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|" << livre[4] << "\n";
            }
        }
        fichierLivres.close();
        qDebug() << "Livre" << numLivre << "marqué comme indisponible";
    }

    // Cacher le formulaire
    ui->comboBox_lecteurs->hide();
    ui->comboBox_livres->hide();
    ui->dateEdit_pret->hide();
    ui->dateEdit_2->hide();
    ui->buttonBox->hide();

    // Montrer la liste
    ui->listWidget->show();
    ui->listWidget->clear();
    ui->listWidget->addItem("Prêt enregistré : " + idPret);
    ui->listWidget->addItem("Livre " + numLivre + " maintenant indisponible");
}

QList<QStringList> g_prets_window::chargerTousLesLivres()
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

void g_prets_window::on_buttonBox_rejected()
{
    qDebug() << "Annuler nouveau prêt cliqué";

    // Cacher le formulaire sans sauvegarder
    ui->pushButton_5->hide();
    ui->label_5->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->comboBox_lecteurs->hide();
    ui->comboBox_livres->hide();
    ui->dateEdit_pret->hide();
    ui->dateEdit_2->hide();
    ui->buttonBox->hide();

    // Montrer la liste vide
    ui->listWidget->show();
    ui->listWidget->clear();
    ui->listWidget->addItem("Opération annulée");
}

void g_prets_window::on_retour_livre_clicked()
{
    qDebug() << "=== RETOUR LIVRE ===";

    // Cacher le formulaire
     ui->pushButton_5->hide();
    ui->comboBox_lecteurs->hide();
    ui->comboBox_livres->hide();
    ui->dateEdit_pret->hide();
    ui->dateEdit_2->hide();
    ui->buttonBox->hide();

    // Montrer la liste
    ui->listWidget->show();
    ui->listWidget->clear();

    // Charger les prêts EN COURS (sans date de retour)
    QList<QStringList> tousLesPrets = chargerPrets();
    QList<QStringList> pretsEnCours;

    for (const QStringList& pret : tousLesPrets) {
        if (pret.size() == 5 || pret[5].isEmpty()) {  // Prêt sans date de retour
            pretsEnCours.append(pret);
        }
    }

    if (pretsEnCours.isEmpty()) {
        ui->listWidget->addItem("Aucun prêt en cours");
        ui->listWidget->addItem("Tous les livres sont rendus");
        return;
    }

    // Afficher les prêts en cours
    for (const QStringList& pret : pretsEnCours) {
        QString affichage = pret[0] + " - " + pret[1] + " → " + pret[2] + " (" + pret[3] + ")";
        ui->listWidget->addItem(affichage);
    }

    ui->listWidget->addItem("");
    ui->listWidget->addItem("Double-cliquez sur un prêt pour le retourner");
}

void g_prets_window::traiterRetourPret(const QString& idPret)
{
    // 1. Charger tous les prêts
    QList<QStringList> tousLesPrets = chargerPrets();
    QString numLivre;

    // 2. Trouver le prêt et le livre associé
    for (int i = 0; i < tousLesPrets.size(); i++) {
        if (tousLesPrets[i][0] == idPret) {
            numLivre = tousLesPrets[i][2];

            // Ajouter la date de retour actuelle
            QString dateRetour = QDate::currentDate().toString("dd-MM-yyyy");
            if (tousLesPrets[i].size() == 5) {
                tousLesPrets[i] << dateRetour;
            } else if (tousLesPrets[i].size() >= 6) {
                tousLesPrets[i][5] = dateRetour;
            }
            break;
        }
    }

    // 3. Sauvegarder les prêts modifiés
    QFile fichierPrets("prets.dat");
    if (fichierPrets.open(QIODevice::WriteOnly)) {
        QTextStream fluxPrets(&fichierPrets);
        for (const QStringList& pret : tousLesPrets) {
            for (int i = 0; i < pret.size(); i++) {
                fluxPrets << pret[i];
                if (i < pret.size() - 1) fluxPrets << "|";
            }
            fluxPrets << "\n";
        }
        fichierPrets.close();
    }

    // 4. Remettre le livre disponible
    if (!numLivre.isEmpty()) {
        QList<QStringList> tousLesLivres = chargerTousLesLivres();
        QFile fichierLivres("livres.dat");
        if (fichierLivres.open(QIODevice::WriteOnly)) {
            QTextStream fluxLivres(&fichierLivres);
            for (const QStringList& livre : tousLesLivres) {
                if (livre[0] == numLivre) {
                    fluxLivres << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|Oui\n";
                } else {
                    fluxLivres << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|" << livre[4] << "\n";
                }
            }
            fichierLivres.close();
        }
    }
}

void g_prets_window::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    QString texte = item->text();

    if (texte.contains(" - ") && texte.contains(" → ")) {
        QString idPret = texte.split(" - ")[0];

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Retour livre",
                                      "Marquer ce prêt comme rendu ?\n" + texte,
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // 1. Charger tous les prêts
            QList<QStringList> tousLesPrets = chargerPrets();
            QString numLivre;

            // 2. Trouver le prêt et le livre associé
            for (int i = 0; i < tousLesPrets.size(); i++) {
                if (tousLesPrets[i][0] == idPret) {
                    numLivre = tousLesPrets[i][2];

                    // Ajouter la date de retour actuelle
                    QString dateRetour = QDate::currentDate().toString("dd-MM-yyyy");

                    // S'assurer qu'on a 6 champs
                    while (tousLesPrets[i].size() < 6) {
                        tousLesPrets[i] << "";
                    }
                    tousLesPrets[i][5] = dateRetour;
                    break;
                }
            }

            // 3. Sauvegarder les prêts modifiés
            QFile fichierPrets("prets.dat");
            if (fichierPrets.open(QIODevice::WriteOnly)) {
                QTextStream fluxPrets(&fichierPrets);
                for (const QStringList& pret : tousLesPrets) {
                    for (int i = 0; i < pret.size(); i++) {
                        fluxPrets << pret[i];
                        if (i < pret.size() - 1) fluxPrets << "|";
                    }
                    fluxPrets << "\n";
                }
                fichierPrets.close();
            }

            // 4. Remettre le livre disponible
            if (!numLivre.isEmpty()) {
                QList<QStringList> tousLesLivres = chargerTousLesLivres();
                QFile fichierLivres("livres.dat");
                if (fichierLivres.open(QIODevice::WriteOnly)) {
                    QTextStream fluxLivres(&fichierLivres);
                    for (const QStringList& livre : tousLesLivres) {
                        if (livre[0] == numLivre) {
                            fluxLivres << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|Oui\n";
                        } else {
                            fluxLivres << livre[0] << "|" << livre[1] << "|" << livre[2] << "|" << livre[3] << "|" << livre[4] << "\n";
                        }
                    }
                    fichierLivres.close();
                }
            }

            // ⭐⭐ 5. SUPPRIMER l'élément de la liste IMMÉDIATEMENT
            delete ui->listWidget->takeItem(ui->listWidget->row(item));

            // 6. Rafraîchir l'affichage du compteur
            int nbPretsRestants = ui->listWidget->count() - 2; // -2 pour les lignes d'info
            if (nbPretsRestants > 0) {
                // Mettre à jour le message en bas
                ui->listWidget->item(ui->listWidget->count()-1)->setText("Double-cliquez sur un prêt pour le retourner - " + QString::number(nbPretsRestants) + " prêt(s) restant(s)");
            } else {
                // Si plus de prêts, vider et afficher message
                ui->listWidget->clear();
                ui->listWidget->addItem("Aucun prêt en cours");
                ui->listWidget->addItem("Tous les livres sont rendus");
            }

            QMessageBox::information(this, "Succès", "Livre marqué comme retourné !");
        }
    }
}
QList<QStringList> g_prets_window::chargerPrets()
{
    QList<QStringList> prets;
    QFile fichier("prets.dat");

    if (fichier.open(QIODevice::ReadOnly)) {
        QTextStream flux(&fichier);
        while (!flux.atEnd()) {
            QString ligne = flux.readLine().trimmed();
            if (ligne.isEmpty()) continue;

            QStringList pret = ligne.split("|");

            // Nettoyer les champs vides
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


void g_prets_window::on_vider_liste_clicked()
{
    // Charger tous les prêts
    QList<QStringList> tousLesPrets = chargerPrets();

    // Garder seulement les prêts EN COURS (non rendus)
    QList<QStringList> pretsEnCours;

    for (const QStringList& pret : tousLesPrets) {
        // Si le prêt n'a pas de date de retour réelle, le garder
        if (pret.size() < 6 || pret[5].isEmpty()) {
            pretsEnCours.append(pret);
        }
    }

    // Sauvegarder seulement les prêts en cours
    QFile fichierPrets("prets.dat");
    if (fichierPrets.open(QIODevice::WriteOnly)) {
        QTextStream fluxPrets(&fichierPrets);
        for (const QStringList& pret : pretsEnCours) {
            for (int i = 0; i < pret.size(); i++) {
                fluxPrets << pret[i];
                if (i < pret.size() - 1) fluxPrets << "|";
            }
            fluxPrets << "\n";
        }
        fichierPrets.close();
    }

    // Mettre à jour l'affichage
    ui->listWidget->clear();
    ui->listWidget->addItem("Prêts rendus supprimés");
    ui->listWidget->addItem("Seuls les prêts en cours sont conservés");
}

void g_prets_window::on_pushButton_4_clicked()
{
    this->close();
}

g_prets_window::~g_prets_window()
{
    delete ui;

}




//FENO 500 !!!!! XDDDDDD
