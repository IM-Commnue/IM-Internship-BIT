/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Homepage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *username;
    QPushButton *revise;
    QPushButton *chatpushButton;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *vlayout;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QPushButton *detefriendbutelton;
    QPushButton *addButton_2;
    QPushButton *deletegroupchatbutton;

    void setupUi(QDialog *Homepage)
    {
        if (Homepage->objectName().isEmpty())
            Homepage->setObjectName(QString::fromUtf8("Homepage"));
        Homepage->resize(271, 535);
        verticalLayout = new QVBoxLayout(Homepage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        username = new QLabel(Homepage);
        username->setObjectName(QString::fromUtf8("username"));

        verticalLayout->addWidget(username);

        revise = new QPushButton(Homepage);
        revise->setObjectName(QString::fromUtf8("revise"));

        verticalLayout->addWidget(revise);

        chatpushButton = new QPushButton(Homepage);
        chatpushButton->setObjectName(QString::fromUtf8("chatpushButton"));

        verticalLayout->addWidget(chatpushButton);

        toolBox = new QToolBox(Homepage);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 253, 264));
        vlayout = new QVBoxLayout(page);
        vlayout->setObjectName(QString::fromUtf8("vlayout"));
        toolBox->addItem(page, QString::fromUtf8("\345\245\275\345\217\213"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 253, 264));
        toolBox->addItem(page_2, QString::fromUtf8("\347\276\244\350\201\212\345\244\251"));

        verticalLayout->addWidget(toolBox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addButton = new QPushButton(Homepage);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        detefriendbutelton = new QPushButton(Homepage);
        detefriendbutelton->setObjectName(QString::fromUtf8("detefriendbutelton"));

        gridLayout->addWidget(detefriendbutelton, 0, 1, 1, 1);

        addButton_2 = new QPushButton(Homepage);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));
        addButton_2->setAutoRepeatDelay(300);

        gridLayout->addWidget(addButton_2, 1, 0, 1, 1);

        deletegroupchatbutton = new QPushButton(Homepage);
        deletegroupchatbutton->setObjectName(QString::fromUtf8("deletegroupchatbutton"));

        gridLayout->addWidget(deletegroupchatbutton, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Homepage);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Homepage);
    } // setupUi

    void retranslateUi(QDialog *Homepage)
    {
        Homepage->setWindowTitle(QApplication::translate("Homepage", "Dialog", nullptr));
        username->setText(QApplication::translate("Homepage", "\344\270\252\344\272\272\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        revise->setText(QApplication::translate("Homepage", "\346\230\265\347\247\260\344\277\256\346\224\271", nullptr));
        chatpushButton->setText(QApplication::translate("Homepage", "\350\201\212\345\244\251\346\234\272\345\231\250\344\272\272", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Homepage", "\345\245\275\345\217\213", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Homepage", "\347\276\244\350\201\212\345\244\251", nullptr));
        addButton->setText(QApplication::translate("Homepage", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        detefriendbutelton->setText(QApplication::translate("Homepage", "\345\210\240\351\231\244\345\245\275\345\217\213", nullptr));
        addButton_2->setText(QApplication::translate("Homepage", "\346\267\273\345\212\240\347\276\244\350\201\212", nullptr));
        deletegroupchatbutton->setText(QApplication::translate("Homepage", "\345\210\240\351\231\244\347\276\244\350\201\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Homepage: public Ui_Homepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
