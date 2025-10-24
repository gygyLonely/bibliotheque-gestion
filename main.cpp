#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString stylepr =
        "QMainWindow, QDialog {"
        "    background-color: #ECF0F1 !important;"
        "}"
        "QPushButton {"
        "    background-color: #2C3E50 !important;"
        "    color: #FFFFFF !important;"
        "    border: none !important;"
        "    padding: 8px 12px !important;"
        "    border-radius: 6px !important;"
        "    font-size: 12px !important;"
        "    font-weight: normal !important;"
        "    min-width: 100px !important;"
        "}"
        "QPushButton:hover {"
        "    background-color: #34495E !important;"
        "}"
        "QListWidget {"
        "    background-color: #FFFFFF !important;"
        "    color: #000000 !important;"
        "    border: 1px solid #BDC3C7 !important;"
        "    border-radius: 4px !important;"
        "}"
        "QLineEdit, QComboBox, QDateEdit {"
        "    background-color: #FFFFFF !important;"
        "    color: #000000 !important;"
        "    border: 1px solid #BDC3C7 !important;"
        "    border-radius: 4px !important;"
        "}"
        "QLabel {"
        "    color: #000000 !important;"
        "    background-color: transparent !important;"
        "}";

    app.setStyleSheet(stylepr);
    MainWindow w;
    w.show();

    return app.exec();
}
