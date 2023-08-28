/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *underlineToolBtn;
    QPushButton *sendimagebutton;
    QPushButton *sendToolBtn;
    QPushButton *saveToolBtn;
    QPushButton *clearToolBtn;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitpushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1093, 485);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1056, 461));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fontComboBox = new QComboBox(layoutWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout_2->addWidget(fontComboBox);

        sizeComboBox = new QComboBox(layoutWidget);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));

        horizontalLayout_2->addWidget(sizeComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        underlineToolBtn = new QPushButton(layoutWidget);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));

        horizontalLayout->addWidget(underlineToolBtn);

        sendimagebutton = new QPushButton(layoutWidget);
        sendimagebutton->setObjectName(QString::fromUtf8("sendimagebutton"));

        horizontalLayout->addWidget(sendimagebutton);

        sendToolBtn = new QPushButton(layoutWidget);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));

        horizontalLayout->addWidget(sendToolBtn);

        saveToolBtn = new QPushButton(layoutWidget);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));

        horizontalLayout->addWidget(saveToolBtn);

        clearToolBtn = new QPushButton(layoutWidget);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));

        horizontalLayout->addWidget(clearToolBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setIndent(-2);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        exitpushButton = new QPushButton(layoutWidget);
        exitpushButton->setObjectName(QString::fromUtf8("exitpushButton"));

        horizontalLayout_3->addWidget(exitpushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(tableWidget);


        retranslateUi(Widget);
        QObject::connect(clearToolBtn, SIGNAL(clicked()), textBrowser, SLOT(clear()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
        underlineToolBtn->setText(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
        sendimagebutton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\345\233\276\347\211\207", nullptr));
        sendToolBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        saveToolBtn->setText(QApplication::translate("Widget", "\344\270\213\350\275\275\346\226\207\346\241\243", nullptr));
        clearToolBtn->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        pushButton_8->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\275\223\345\211\215\344\272\272\346\225\260</p></body></html>", nullptr));
        exitpushButton->setText(QApplication::translate("Widget", "\346\216\250\345\207\272\350\201\212\345\244\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
