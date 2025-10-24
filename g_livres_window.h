#ifndef G_LIVRES_WINDOW_H
#define G_LIVRES_WINDOW_H
#include <QListWidgetItem>
#include <QDialog>

namespace Ui {
class g_livres_window;
}

class g_livres_window : public QDialog
{
    Q_OBJECT

public:
    explicit g_livres_window(QWidget *parent = nullptr);
    ~g_livres_window();

private:
    Ui::g_livres_window *ui;
    void sauvegarderLivre(const QString& numero, const QString& titre, const QString& auteur, const QString& date);
    QList<QStringList> chargerLivres();
    void supprimerLivre(const QString& numero);// SUPPRIMER

private slots:
    void on_but_rech_clicked();
    void on_ajouter();        // AJOUTER
    void on_lister();         //LISTER
    void on_buttonBox_accepted();        // OK
    void on_buttonBox_rejected();        // ANNULER
    void on_supprimer();
    void on_tout_supprimer_clicked();             // TOUT SUPPRIMER
    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);  // DOUBLE-CLIC
    void on_pushButton_4_clicked();


};

#endif // G_LIVRES_WINDOW_H
