/********************************************************************************
** Form generated from reading UI file 'g_prets_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_PRETS_WINDOW_H
#define UI_G_PRETS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_g_prets_window
{
public:
    QPushButton *pushButton_4;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox_lecteurs;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_livres;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDateEdit *dateEdit_pret;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDateEdit *dateEdit_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *g_prets_window)
    {
        if (g_prets_window->objectName().isEmpty())
            g_prets_window->setObjectName(QString::fromUtf8("g_prets_window"));
        g_prets_window->resize(542, 380);
        pushButton_4 = new QPushButton(g_prets_window);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 280, 80, 23));
        label = new QLabel(g_prets_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 127, 16));
        listWidget = new QListWidget(g_prets_window);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(255, 70, 281, 221));
        pushButton_5 = new QPushButton(g_prets_window);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(330, 300, 111, 21));
        widget = new QWidget(g_prets_window);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 80, 129, 102));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        widget1 = new QWidget(g_prets_window);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(290, 100, 181, 149));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox_lecteurs = new QComboBox(widget1);
        comboBox_lecteurs->setObjectName(QString::fromUtf8("comboBox_lecteurs"));

        horizontalLayout->addWidget(comboBox_lecteurs);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBox_livres = new QComboBox(widget1);
        comboBox_livres->setObjectName(QString::fromUtf8("comboBox_livres"));

        horizontalLayout_2->addWidget(comboBox_livres);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        dateEdit_pret = new QDateEdit(widget1);
        dateEdit_pret->setObjectName(QString::fromUtf8("dateEdit_pret"));

        horizontalLayout_3->addWidget(dateEdit_pret);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        dateEdit_2 = new QDateEdit(widget1);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout_4->addWidget(dateEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(widget1);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(g_prets_window);

        QMetaObject::connectSlotsByName(g_prets_window);
    } // setupUi

    void retranslateUi(QDialog *g_prets_window)
    {
        g_prets_window->setWindowTitle(QCoreApplication::translate("g_prets_window", "Dialog", nullptr));
        pushButton_4->setText(QCoreApplication::translate("g_prets_window", "RETOUR", nullptr));
        label->setText(QCoreApplication::translate("g_prets_window", ">>GESTION PRETS", nullptr));
        pushButton_5->setText(QCoreApplication::translate("g_prets_window", "VIDER LA LISTE", nullptr));
        pushButton->setText(QCoreApplication::translate("g_prets_window", "NOUVEAU PRET", nullptr));
        pushButton_3->setText(QCoreApplication::translate("g_prets_window", "LISTER PRETS", nullptr));
        pushButton_2->setText(QCoreApplication::translate("g_prets_window", "RETOUR LIVRES", nullptr));
        label_2->setText(QCoreApplication::translate("g_prets_window", "LECTEUR :", nullptr));
        label_3->setText(QCoreApplication::translate("g_prets_window", "LIVRE  :", nullptr));
        label_4->setText(QCoreApplication::translate("g_prets_window", "DATE PRET :", nullptr));
        label_5->setText(QCoreApplication::translate("g_prets_window", "DATE RETOUR :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class g_prets_window: public Ui_g_prets_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_G_PRETS_WINDOW_H
