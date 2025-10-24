/********************************************************************************
** Form generated from reading UI file 'g_livres_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_LIVRES_WINDOW_H
#define UI_G_LIVRES_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
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

class Ui_g_livres_window
{
public:
    QPushButton *pushButton_4;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *input_rech;
    QPushButton *but_rech;

    void setupUi(QDialog *g_livres_window)
    {
        if (g_livres_window->objectName().isEmpty())
            g_livres_window->setObjectName(QString::fromUtf8("g_livres_window"));
        g_livres_window->resize(623, 415);
        g_livres_window->setAutoFillBackground(false);
        pushButton_4 = new QPushButton(g_livres_window);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setGeometry(QRect(40, 300, 81, 21));
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(g_livres_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 151, 16));
        listWidget = new QListWidget(g_livres_window);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(300, 60, 301, 211));
        listWidget->setMouseTracking(true);
        listWidget->setMovement(QListView::Static);
        buttonBox = new QDialogButtonBox(g_livres_window);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(350, 280, 165, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton_6 = new QPushButton(g_livres_window);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(370, 310, 131, 31));
        layoutWidget = new QWidget(g_livres_window);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 80, 141, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(g_livres_window);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(330, 80, 204, 169));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(167772, 16777215));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        dateEdit = new QDateEdit(layoutWidget1);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_4->addWidget(dateEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        layoutWidget_2 = new QWidget(g_livres_window);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(280, 20, 311, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        input_rech = new QLineEdit(layoutWidget_2);
        input_rech->setObjectName(QString::fromUtf8("input_rech"));

        horizontalLayout_5->addWidget(input_rech);

        but_rech = new QPushButton(layoutWidget_2);
        but_rech->setObjectName(QString::fromUtf8("but_rech"));

        horizontalLayout_5->addWidget(but_rech);


        retranslateUi(g_livres_window);

        QMetaObject::connectSlotsByName(g_livres_window);
    } // setupUi

    void retranslateUi(QDialog *g_livres_window)
    {
        g_livres_window->setWindowTitle(QCoreApplication::translate("g_livres_window", "Dialog", nullptr));
        pushButton_4->setText(QCoreApplication::translate("g_livres_window", "<< RETOUR", nullptr));
        label->setText(QCoreApplication::translate("g_livres_window", ">> GESTION LECTEUR", nullptr));
        pushButton_6->setText(QCoreApplication::translate("g_livres_window", "TOUT SUPPRIMER", nullptr));
        pushButton->setText(QCoreApplication::translate("g_livres_window", "AJOUTER", nullptr));
        pushButton_5->setText(QCoreApplication::translate("g_livres_window", "MODIFIER", nullptr));
        pushButton_2->setText(QCoreApplication::translate("g_livres_window", "SUPPRIMER", nullptr));
        pushButton_3->setText(QCoreApplication::translate("g_livres_window", "LISTER", nullptr));
        label_2->setText(QCoreApplication::translate("g_livres_window", " NUMERO :", nullptr));
        label_3->setText(QCoreApplication::translate("g_livres_window", " TITRE :", nullptr));
        label_4->setText(QCoreApplication::translate("g_livres_window", " AUTEUR  :", nullptr));
        label_5->setText(QCoreApplication::translate("g_livres_window", " DATE :", nullptr));
        but_rech->setText(QCoreApplication::translate("g_livres_window", "RECHERCHER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class g_livres_window: public Ui_g_livres_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_G_LIVRES_WINDOW_H
