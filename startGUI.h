#pragma once

#include <QMainWindow>
#include "ui_startGUI.h"

class StartGUI : public QMainWindow
{
	Q_OBJECT

public:
	StartGUI(QWidget *parent = nullptr);
	~StartGUI();


private:
	Ui::startGUIClass ui;

	void connectSignalsAndSlots();
};
