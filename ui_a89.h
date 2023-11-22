/********************************************************************************
** Form generated from reading UI file 'a89.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A89_H
#define UI_A89_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_a89Class
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWithData;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLabel *presenterLabel;
    QLineEdit *presnterLineEdit;
    QLabel *durationLabel;
    QLineEdit *durationLineEdit;
    QLabel *likesLabel;
    QLineEdit *likesLineEdit;
    QLabel *linkLabel;
    QLineEdit *linkLineEdit;
    QLineEdit *titleLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *a89Class)
    {
        if (a89Class->objectName().isEmpty())
            a89Class->setObjectName("a89Class");
        a89Class->resize(839, 345);
        centralWidget = new QWidget(a89Class);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWithData = new QListWidget(centralWidget);
        listWithData->setObjectName("listWithData");

        horizontalLayout_2->addWidget(listWithData);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName("titleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        presenterLabel = new QLabel(centralWidget);
        presenterLabel->setObjectName("presenterLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, presenterLabel);

        presnterLineEdit = new QLineEdit(centralWidget);
        presnterLineEdit->setObjectName("presnterLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, presnterLineEdit);

        durationLabel = new QLabel(centralWidget);
        durationLabel->setObjectName("durationLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, durationLabel);

        durationLineEdit = new QLineEdit(centralWidget);
        durationLineEdit->setObjectName("durationLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, durationLineEdit);

        likesLabel = new QLabel(centralWidget);
        likesLabel->setObjectName("likesLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, likesLabel);

        likesLineEdit = new QLineEdit(centralWidget);
        likesLineEdit->setObjectName("likesLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, likesLineEdit);

        linkLabel = new QLabel(centralWidget);
        linkLabel->setObjectName("linkLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, linkLabel);

        linkLineEdit = new QLineEdit(centralWidget);
        linkLineEdit->setObjectName("linkLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, linkLineEdit);

        titleLineEdit = new QLineEdit(centralWidget);
        titleLineEdit->setObjectName("titleLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, titleLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        updateButton = new QPushButton(centralWidget);
        updateButton->setObjectName("updateButton");

        horizontalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName("exitButton");

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        a89Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(a89Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 839, 22));
        a89Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(a89Class);
        mainToolBar->setObjectName("mainToolBar");
        a89Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(a89Class);
        statusBar->setObjectName("statusBar");
        a89Class->setStatusBar(statusBar);

        retranslateUi(a89Class);

        QMetaObject::connectSlotsByName(a89Class);
    } // setupUi

    void retranslateUi(QMainWindow *a89Class)
    {
        a89Class->setWindowTitle(QCoreApplication::translate("a89Class", "a89", nullptr));
        titleLabel->setText(QCoreApplication::translate("a89Class", "Title", nullptr));
        presenterLabel->setText(QCoreApplication::translate("a89Class", "Presenter: ", nullptr));
        durationLabel->setText(QCoreApplication::translate("a89Class", "Duration: ", nullptr));
        likesLabel->setText(QCoreApplication::translate("a89Class", "Likes: ", nullptr));
        linkLabel->setText(QCoreApplication::translate("a89Class", "Link: ", nullptr));
        addButton->setText(QCoreApplication::translate("a89Class", "Add", nullptr));
        updateButton->setText(QCoreApplication::translate("a89Class", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("a89Class", "Delete", nullptr));
        exitButton->setText(QCoreApplication::translate("a89Class", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class a89Class: public Ui_a89Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A89_H
