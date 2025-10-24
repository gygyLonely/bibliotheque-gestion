#ifndef G_PRETS_WINDOW_H
#define G_PRETS_WINDOW_H
#include <QListWidgetItem>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class g_prets_window;
}

class g_prets_window : public QDialog
{
    Q_OBJECT

public:
    explicit g_prets_window(QWidget *parent = nullptr);
    ~g_prets_window();

private:
    Ui::g_prets_window *ui;
    QList<QStringList> chargerLecteurs();
    QList<QStringList> chargerLivresDisponibles();
    QList<QStringList> chargerPrets();
    QList<QStringList> chargerTousLesLivres();

private slots:
    void on_nouveau_pret_clicked();          // NOUVEAU PRÊT
    void on_lister_prets_clicked();  // LISTER PRÊTS
    void on_retour_livre_clicked();  // RETOUR LIVRE
    void on_buttonBox_accepted();            // OK
    void on_buttonBox_rejected();            // ANNULER
    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);
    void traiterRetourPret(const QString& idPret);
    void on_vider_liste_clicked();
    void on_pushButton_4_clicked();
};

#endif // G_PRETS_WINDOW_H
