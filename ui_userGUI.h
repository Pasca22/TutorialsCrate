/********************************************************************************
** Form generated from reading UI file 'userGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERGUI_H
#define UI_USERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userGUIClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *filterByPresenterLineEdit;
    QPushButton *searchButton;
    QListWidget *filteredByPresenterList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addToWatchListButton;
    QPushButton *deleteFromWatchListButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *seeWatchListButton;
    QPushButton *openOnYoutubeButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *userGUIClass)
    {
        if (userGUIClass->objectName().isEmpty())
            userGUIClass->setObjectName("userGUIClass");
        userGUIClass->resize(679, 505);
        centralWidget = new QWidget(userGUIClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        filterByPresenterLineEdit = new QLineEdit(centralWidget);
        filterByPresenterLineEdit->setObjectName("filterByPresenterLineEdit");

        horizontalLayout_3->addWidget(filterByPresenterLineEdit);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName("searchButton");

        horizontalLayout_3->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout_3);

        filteredByPresenterList = new QListWidget(centralWidget);
        filteredByPresenterList->setObjectName("filteredByPresenterList");

        verticalLayout->addWidget(filteredByPresenterList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addToWatchListButton = new QPushButton(centralWidget);
        addToWatchListButton->setObjectName("addToWatchListButton");

        horizontalLayout_2->addWidget(addToWatchListButton);

        deleteFromWatchListButton = new QPushButton(centralWidget);
        deleteFromWatchListButton->setObjectName("deleteFromWatchListButton");

        horizontalLayout_2->addWidget(deleteFromWatchListButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        seeWatchListButton = new QPushButton(centralWidget);
        seeWatchListButton->setObjectName("seeWatchListButton");

        horizontalLayout->addWidget(seeWatchListButton);

        openOnYoutubeButton = new QPushButton(centralWidget);
        openOnYoutubeButton->setObjectName("openOnYoutubeButton");

        horizontalLayout->addWidget(openOnYoutubeButton);


        verticalLayout->addLayout(horizontalLayout);

        userGUIClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(userGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        userGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(userGUIClass);
        statusBar->setObjectName("statusBar");
        userGUIClass->setStatusBar(statusBar);

        retranslateUi(userGUIClass);

        QMetaObject::connectSlotsByName(userGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *userGUIClass)
    {
        userGUIClass->setWindowTitle(QCoreApplication::translate("userGUIClass", "userGUI", nullptr));
        searchButton->setText(QCoreApplication::translate("userGUIClass", "Search", nullptr));
        addToWatchListButton->setText(QCoreApplication::translate("userGUIClass", "Add to Watch List", nullptr));
        deleteFromWatchListButton->setText(QCoreApplication::translate("userGUIClass", "Delete From Watch List", nullptr));
        seeWatchListButton->setText(QCoreApplication::translate("userGUIClass", "See the Watch List", nullptr));
        openOnYoutubeButton->setText(QCoreApplication::translate("userGUIClass", "Watch video on YouTube", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userGUIClass: public Ui_userGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERGUI_H
