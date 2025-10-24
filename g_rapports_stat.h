#ifndef G_RAPPORTS_STAT_H
#define G_RAPPORTS_STAT_H

#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QSet>
#include <QDialog>

namespace Ui {
class g_rapports_stat;
}

class g_rapports_stat : public QDialog
{
    Q_OBJECT

public:
    explicit g_rapports_stat(QWidget *parent = nullptr);
    ~g_rapports_stat();

private:
    Ui::g_rapports_stat *ui;
    QList<QStringList> chargerLecteurs();
    QList<QStringList> chargerTousLesLivres();
    QList<QStringList> chargerPrets();


private slots:
    void on_btn_stats_lecteurs_clicked();    // Pour pushButton
    void on_btn_stats_livres_clicked();      // Pour pushButton_2
    void on_btn_stats_prets_clicked();       // Pour pushButton_3
    void on_btn_stats_general_clicked();     // Pour pushButton_4 (STATS)
    void on_btn_retour_clicked();            // Pour RETOUR
};

#endif // G_RAPPORTS_STAT_H
