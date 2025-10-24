/********************************************************************************
** Form generated from reading UI file 'g_rapports_stat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_RAPPORTS_STAT_H
#define UI_G_RAPPORTS_STAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_g_rapports_stat
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton_4;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *g_rapports_stat)
    {
        if (g_rapports_stat->objectName().isEmpty())
            g_rapports_stat->setObjectName(QString::fromUtf8("g_rapports_stat"));
        g_rapports_stat->resize(551, 355);
        listWidget = new QListWidget(g_rapports_stat);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 80, 501, 221));
        pushButton_4 = new QPushButton(g_rapports_stat);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 310, 121, 31));
        label = new QLabel(g_rapports_stat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 111, 16));
        layoutWidget = new QWidget(g_rapports_stat);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 301, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(g_rapports_stat);

        QMetaObject::connectSlotsByName(g_rapports_stat);
    } // setupUi

    void retranslateUi(QDialog *g_rapports_stat)
    {
        g_rapports_stat->setWindowTitle(QCoreApplication::translate("g_rapports_stat", "Dialog", nullptr));
        pushButton_4->setText(QCoreApplication::translate("g_rapports_stat", "RETOUR", nullptr));
        label->setText(QCoreApplication::translate("g_rapports_stat", ">> STATISTIQUES", nullptr));
        pushButton->setText(QCoreApplication::translate("g_rapports_stat", "LECTEUR", nullptr));
        pushButton_2->setText(QCoreApplication::translate("g_rapports_stat", "LIVRE", nullptr));
        pushButton_3->setText(QCoreApplication::translate("g_rapports_stat", "PRETS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class g_rapports_stat: public Ui_g_rapports_stat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_G_RAPPORTS_STAT_H
