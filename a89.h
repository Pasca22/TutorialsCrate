#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_a89.h"
#include "service.h"

class AdminGUI : public QMainWindow
{
    Q_OBJECT

public:
    AdminGUI(Service service, QWidget *parent = nullptr);
    ~AdminGUI();

private:
    Service service;
    Tutorial selectedTutorial;

    Ui::a89Class ui;

    void loadData();

    void connectSignalsAndSlots();

};
