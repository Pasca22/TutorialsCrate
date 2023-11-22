#pragma once

#include <QMainWindow>
#include "ui_userGUI.h"
#include "service.h"
#include <vector>

class UserGUI : public QMainWindow
{
	Q_OBJECT

public:
	UserGUI(Service service, QWidget *parent = nullptr);
	~UserGUI();

private:
	Service service;
	Tutorial selectedTutorial; 
	std::vector<Tutorial> tutorialsFiltered;

	Ui::userGUIClass ui;

	void connectSignalsAndSlots();
};
