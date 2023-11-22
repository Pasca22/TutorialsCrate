/********************************************************************************
** Form generated from reading UI file 'startGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTGUI_H
#define UI_STARTGUI_H

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

class Ui_startGUIClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *htmlButton;
    QPushButton *csvButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *startGUIClass)
    {
        if (startGUIClass->objectName().isEmpty())
            startGUIClass->setObjectName("startGUIClass");
        startGUIClass->resize(409, 305);
        centralWidget = new QWidget(startGUIClass);
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
        htmlButton = new QPushButton(centralWidget);
        htmlButton->setObjectName("htmlButton");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        htmlButton->setFont(font1);

        horizontalLayout->addWidget(htmlButton);

        csvButton = new QPushButton(centralWidget);
        csvButton->setObjectName("csvButton");
        csvButton->setFont(font1);

        horizontalLayout->addWidget(csvButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setFont(font1);

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);

        startGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(startGUIClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 409, 22));
        startGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(startGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        startGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(startGUIClass);
        statusBar->setObjectName("statusBar");
        startGUIClass->setStatusBar(statusBar);

        retranslateUi(startGUIClass);

        QMetaObject::connectSlotsByName(startGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *startGUIClass)
    {
        startGUIClass->setWindowTitle(QCoreApplication::translate("startGUIClass", "startGUI", nullptr));
        label->setText(QCoreApplication::translate("startGUIClass", "Choose your file type", nullptr));
        htmlButton->setText(QCoreApplication::translate("startGUIClass", "HTML", nullptr));
        csvButton->setText(QCoreApplication::translate("startGUIClass", "CSV", nullptr));
        exitButton->setText(QCoreApplication::translate("startGUIClass", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startGUIClass: public Ui_startGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTGUI_H
