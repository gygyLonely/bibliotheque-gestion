#ifndef G_LECTEURS_WINDOW_H
#define G_LECTEURS_WINDOW_H
#include <QListWidgetItem>
#include <QDialog>
#include <QListView>
#include <QStringListModel>


namespace Ui {
class G_Lecteurs_Window;
}

class G_Lecteurs_Window : public QDialog
{
    Q_OBJECT

public:
    explicit G_Lecteurs_Window(QWidget *parent = nullptr);
    ~G_Lecteurs_Window();

// private slots:
//     void on_btnLister_clicked();
//     void on_ajouter_clicked();    // Pour le bouton AJOUTER
//     void on_valider_clicked();    // Pour OK du buttonBox
//     void on_annuler_clicked();    // Pour Cancel du buttonBox

private slots:
    void on_but_rech_clicked();
    void on_pushButton_4_clicked();//retour
    void on_pushButton_3_clicked();//lister
    void on_pushButton_2_clicked();//supprimer
    void on_pushButton_clicked();//ajouter
    void on_buttonBox_accepted();//ok
    void on_buttonBox_rejected();//cancel
    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);
    void on_tout_supprimer_clicked();//tout-supprimer-lecteur

private:
    Ui::G_Lecteurs_Window *ui;
    void sauvegarderLecteur(const QString& numero, const QString& nom);
    QList<QStringList> chargerLecteurs();
    void supprimerLecteur(const QString& numero);


};

#endif // G_LECTEURS_WINDOW_H
