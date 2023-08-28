/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qtmaterialautocomplete.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QtMaterialAutoComplete *usrLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QtMaterialAutoComplete *pwdLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginBtn;
    QPushButton *signBtn;
    QPushButton *resignButton;
    QLabel *login;
    QLabel *Qlabel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(492, 298);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 110, 269, 128));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        usrLineEdit = new QtMaterialAutoComplete(layoutWidget);
        usrLineEdit->setObjectName(QString::fromUtf8("usrLineEdit"));

        horizontalLayout->addWidget(usrLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pwdLineEdit = new QtMaterialAutoComplete(layoutWidget);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(pwdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        loginBtn = new QPushButton(layoutWidget);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"border: 0.5px solid white;\n"
"\n"
"border-radius: 6px;\n"
"\n"
"background-color: rgb(255,0,0);\n"
"\n"
"min-width: 80px;\n"
"\n"
"font-family:\"Microsoft YaHei\";\n"
"\n"
"font-size:10pt;\n"
"\n"
"font-weight: bold;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"border: 0.5px solid white;\n"
"\n"
"border-radius: 6px;\n"
"\n"
"background-color:#DE2916;\n"
"\n"
"min-width: 80px;\n"
"\n"
"font-family:\"Microsoft YaHei\";\n"
"\n"
"font-size:10pt;\n"
"\n"
"font-weight: bold;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(loginBtn);

        signBtn = new QPushButton(layoutWidget);
        signBtn->setObjectName(QString::fromUtf8("signBtn"));
        signBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"border: 0.5px solid white;\n"
"\n"
"border-radius: 6px;\n"
"\n"
"background-color: rgb(255,0,0);\n"
"\n"
"min-width: 80px;\n"
"\n"
"font-family:\"Microsoft YaHei\";\n"
"\n"
"font-size:10pt;\n"
"\n"
"font-weight: bold;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"border: 0.5px solid white;\n"
"\n"
"border-radius: 6px;\n"
"\n"
"background-color:#DE2916;\n"
"\n"
"min-width: 80px;\n"
"\n"
"font-family:\"Microsoft YaHei\";\n"
"\n"
"font-size:10pt;\n"
"\n"
"font-weight: bold;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(signBtn);

        resignButton = new QPushButton(layoutWidget);
        resignButton->setObjectName(QString::fromUtf8("resignButton"));
        resignButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"\n"
"border: 0.5px solid white;\n"
"\n"
"border-radius: 6px;\n"
"\n"
"background-color: rgb(255,0,0);\n"
"\n"
"min-width: 80px;\n"
"\n"
"font-family:\"Microsoft YaHei\";\n"
"\n"
"font-size:10pt;\n"
"\n"
"font-weight: bold;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"\n"
"border: 0.5px solid white;\n"
"\n"
"border-radius: 6px;\n"
"\n"
"background-color:#DE2916;\n"
"\n"
"min-width: 80px;\n"
"\n"
"font-family:\"Microsoft YaHei\";\n"
"\n"
"font-size:10pt;\n"
"\n"
"font-weight: bold;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(resignButton);


        verticalLayout->addLayout(horizontalLayout_3);

        login = new QLabel(Dialog);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(70, 50, 211, 51));
        login->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-family:\"Microsoft YaHei\";\n"
"font-size:35px;\n"
"font-weight:bold;\n"
"color:black;\n"
"border:none;\n"
"\n"
"\n"
"\n"
"}"));
        Qlabel = new QLabel(Dialog);
        Qlabel->setObjectName(QString::fromUtf8("Qlabel"));
        Qlabel->setGeometry(QRect(0, 0, 491, 301));
        Qlabel->setStyleSheet(QString::fromUtf8("QLabel#backgroundLabel {\n"
"\n"
"    background-image: url(:/red/02.png);\n"
"    background-repeat: no-repeat;\n"
"background-position:center center;\n"
"	background-size:cover;\n"
"}\n"
"\n"
""));
        Qlabel->raise();
        layoutWidget->raise();
        login->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        usrLineEdit->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label->setText(QApplication::translate("Dialog", "\345\257\206    \347\240\201", nullptr));
        pwdLineEdit->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginBtn->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        signBtn->setText(QApplication::translate("Dialog", "\346\263\250\345\206\214", nullptr));
        resignButton->setText(QApplication::translate("Dialog", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        login->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\">login</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
