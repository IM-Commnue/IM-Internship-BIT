/********************************************************************************
** Form generated from reading UI file 'sign.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_H
#define UI_SIGN_H

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

class Ui_sign
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QtMaterialAutoComplete *usernamelineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QtMaterialAutoComplete *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QtMaterialAutoComplete *codelineEditit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QtMaterialAutoComplete *codelineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *confirmbutton;
    QPushButton *cancelbutton;
    QLabel *login;

    void setupUi(QDialog *sign)
    {
        if (sign->objectName().isEmpty())
            sign->setObjectName(QString::fromUtf8("sign"));
        sign->resize(492, 298);
        sign->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(sign);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 110, 241, 158));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        usernamelineEdit = new QtMaterialAutoComplete(layoutWidget);
        usernamelineEdit->setObjectName(QString::fromUtf8("usernamelineEdit"));

        horizontalLayout->addWidget(usernamelineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEdit = new QtMaterialAutoComplete(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        codelineEditit = new QtMaterialAutoComplete(layoutWidget);
        codelineEditit->setObjectName(QString::fromUtf8("codelineEditit"));

        horizontalLayout_2->addWidget(codelineEditit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        codelineEdit_2 = new QtMaterialAutoComplete(layoutWidget);
        codelineEdit_2->setObjectName(QString::fromUtf8("codelineEdit_2"));

        horizontalLayout_3->addWidget(codelineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        confirmbutton = new QPushButton(layoutWidget);
        confirmbutton->setObjectName(QString::fromUtf8("confirmbutton"));
        confirmbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_4->addWidget(confirmbutton);

        cancelbutton = new QPushButton(layoutWidget);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        cancelbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_4->addWidget(cancelbutton);


        verticalLayout->addLayout(horizontalLayout_4);

        login = new QLabel(sign);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(50, 50, 211, 51));
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

        retranslateUi(sign);

        QMetaObject::connectSlotsByName(sign);
    } // setupUi

    void retranslateUi(QDialog *sign)
    {
        sign->setWindowTitle(QApplication::translate("sign", "Dialog", nullptr));
        label->setText(QApplication::translate("sign", "\347\224\250  \346\210\267  \345\220\215", nullptr));
        usernamelineEdit->setPlaceholderText(QApplication::translate("sign", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QApplication::translate("sign", "\351\202\256        \347\256\261", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setPlaceholderText(QApplication::translate("sign", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261", nullptr));
        label_2->setText(QApplication::translate("sign", "\345\257\206        \347\240\201", nullptr));
        codelineEditit->setPlaceholderText(QApplication::translate("sign", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("sign", "\345\206\215\346\254\241\347\241\256\350\256\244", nullptr));
        codelineEdit_2->setInputMask(QString());
        codelineEdit_2->setText(QString());
        codelineEdit_2->setPlaceholderText(QApplication::translate("sign", "\350\257\267\345\206\215\346\254\241\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        confirmbutton->setText(QApplication::translate("sign", "\347\241\256\350\256\244", nullptr));
        cancelbutton->setText(QApplication::translate("sign", "\345\217\226\346\266\210", nullptr));
        login->setText(QApplication::translate("sign", "<html><head/><body><p align=\"center\">sign</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign: public Ui_sign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_H
