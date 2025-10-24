/********************************************************************************
** Form generated from reading UI file 'g_lecteurs_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_LECTEURS_WINDOW_H
#define UI_G_LECTEURS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_G_Lecteurs_Window
{
public:
    QLabel *label;
    QPushButton *pushButton_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_numero;
    QLineEdit *lineEdit_nom;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input_rech;
    QPushButton *but_rech;

    void setupUi(QDialog *G_Lecteurs_Window)
    {
        if (G_Lecteurs_Window->objectName().isEmpty())
            G_Lecteurs_Window->setObjectName(QString::fromUtf8("G_Lecteurs_Window"));
        G_Lecteurs_Window->resize(609, 393);
        label = new QLabel(G_Lecteurs_Window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 151, 16));
        pushButton_4 = new QPushButton(G_Lecteurs_Window);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 290, 91, 31));
        layoutWidget = new QWidget(G_Lecteurs_Window);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 70, 121, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        listWidget = new QListWidget(G_Lecteurs_Window);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(250, 50, 281, 241));
        buttonBox = new QDialogButtonBox(G_Lecteurs_Window);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 250, 165, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton_5 = new QPushButton(G_Lecteurs_Window);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 300, 141, 31));
        layoutWidget1 = new QWidget(G_Lecteurs_Window);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 100, 110, 55));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_numero = new QLineEdit(layoutWidget1);
        lineEdit_numero->setObjectName(QString::fromUtf8("lineEdit_numero"));

        verticalLayout_2->addWidget(lineEdit_numero);

        lineEdit_nom = new QLineEdit(layoutWidget1);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));

        verticalLayout_2->addWidget(lineEdit_nom);

        widget = new QWidget(G_Lecteurs_Window);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(240, 20, 311, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        input_rech = new QLineEdit(widget);
        input_rech->setObjectName(QString::fromUtf8("input_rech"));

        horizontalLayout->addWidget(input_rech);

        but_rech = new QPushButton(widget);
        but_rech->setObjectName(QString::fromUtf8("but_rech"));

        horizontalLayout->addWidget(but_rech);


        retranslateUi(G_Lecteurs_Window);

        QMetaObject::connectSlotsByName(G_Lecteurs_Window);
    } // setupUi

    void retranslateUi(QDialog *G_Lecteurs_Window)
    {
        G_Lecteurs_Window->setWindowTitle(QCoreApplication::translate("G_Lecteurs_Window", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("G_Lecteurs_Window", ">> GESTION LECTEUR", nullptr));
        pushButton_4->setText(QCoreApplication::translate("G_Lecteurs_Window", "<< RETOUR", nullptr));
        pushButton->setText(QCoreApplication::translate("G_Lecteurs_Window", "AJOUTER", nullptr));
        pushButton_2->setText(QCoreApplication::translate("G_Lecteurs_Window", "SUPPRIMER", nullptr));
        pushButton_3->setText(QCoreApplication::translate("G_Lecteurs_Window", "LISTER", nullptr));
        pushButton_5->setText(QCoreApplication::translate("G_Lecteurs_Window", "SUPPRIMER TOUS", nullptr));
        but_rech->setText(QCoreApplication::translate("G_Lecteurs_Window", "RECHERCHER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class G_Lecteurs_Window: public Ui_G_Lecteurs_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_G_LECTEURS_WINDOW_H
