/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QPushButton *pushButton;
    QLabel *label;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(634, 391);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(50, 80, 172, 41));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(430, 80, 172, 41));
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName(QString::fromUtf8("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(50, 160, 172, 41));
        commandLinkButton_4 = new QCommandLinkButton(centralwidget);
        commandLinkButton_4->setObjectName(QString::fromUtf8("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(430, 160, 172, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 260, 91, 31));
        QFont font;
        font.setBold(false);
        pushButton->setFont(font);
        pushButton->setMouseTracking(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 1, 221, 31));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(90, 10, 411, 31));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 83, 155);\n"
"color: #000000;\n"
"border: none;\n"
"border-radius: 6px;"));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 30, 611, 311));
        listWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(71, 77, 75, 213);\n"
"color: #000000;\n"
"border: none;\n"
"border-radius: 6px"));
        MainWindow->setCentralWidget(centralwidget);
        listWidget_2->raise();
        listWidget->raise();
        commandLinkButton->raise();
        commandLinkButton_2->raise();
        commandLinkButton_3->raise();
        commandLinkButton_4->raise();
        pushButton->raise();
        label->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "GESTION LECTEURS", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("MainWindow", "GESTION LIVRES", nullptr));
        commandLinkButton_3->setText(QCoreApplication::translate("MainWindow", "GESTION PR\303\212TS", nullptr));
        commandLinkButton_4->setText(QCoreApplication::translate("MainWindow", "RAPPORTS & STATS", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "QUITTER", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "GESTIONNAIRE DE BIBLIOTHEQUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
