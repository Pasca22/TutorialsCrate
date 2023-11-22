/********************************************************************************
** Form generated from reading UI file 'chooseGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEGUI_H
#define UI_CHOOSEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseGUIClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *userButton;
    QPushButton *adminButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *chooseGUIClass)
    {
        if (chooseGUIClass->objectName().isEmpty())
            chooseGUIClass->setObjectName("chooseGUIClass");
        chooseGUIClass->resize(414, 288);
        centralWidget = new QWidget(chooseGUIClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        userButton = new QPushButton(centralWidget);
        userButton->setObjectName("userButton");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        userButton->setFont(font1);

        horizontalLayout->addWidget(userButton);

        adminButton = new QPushButton(centralWidget);
        adminButton->setObjectName("adminButton");
        adminButton->setFont(font1);

        horizontalLayout->addWidget(adminButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setFont(font1);

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);

        chooseGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chooseGUIClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 414, 22));
        chooseGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chooseGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        chooseGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chooseGUIClass);
        statusBar->setObjectName("statusBar");
        chooseGUIClass->setStatusBar(statusBar);

        retranslateUi(chooseGUIClass);

        QMetaObject::connectSlotsByName(chooseGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *chooseGUIClass)
    {
        chooseGUIClass->setWindowTitle(QCoreApplication::translate("chooseGUIClass", "chooseGUI", nullptr));
        label->setText(QCoreApplication::translate("chooseGUIClass", "Choose your mode", nullptr));
        userButton->setText(QCoreApplication::translate("chooseGUIClass", "USER", nullptr));
        adminButton->setText(QCoreApplication::translate("chooseGUIClass", "ADMIN", nullptr));
        exitButton->setText(QCoreApplication::translate("chooseGUIClass", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooseGUIClass: public Ui_chooseGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEGUI_H
