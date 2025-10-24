#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "g_lecteurs_window.h"
#include "g_livres_window.h"
#include "g_prets_window.h"
#include "g_rapports_stat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->commandLinkButton, &QCommandLinkButton::clicked, this, [this]() {
        G_Lecteurs_Window fenetreLecteurs(this);
        fenetreLecteurs.exec();
    });//pour gestion_lecteurs xd

    connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, this, [this]() {
        g_livres_window fenetreLivres(this);
        fenetreLivres.exec();
    });//pour gestion_livres xd

    connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, this, [this]() {
        g_prets_window fenetrePrets(this);
        fenetrePrets.exec();
    });//pour gestion_pret

    connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, this, [this]() {
        g_rapports_stat fenetrePrets(this);
        fenetrePrets.exec();
    });//pour gestion_pret

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();

}


