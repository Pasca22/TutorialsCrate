#include "startGUI.h"
#include <QDialog>
#include "a89.h"
#include "userGUI.h"

StartGUI::StartGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

StartGUI::~StartGUI()
{}

void StartGUI::connectSignalsAndSlots()
{
	QObject::connect(this->ui.csvButton, &QPushButton::clicked, [&]() {
		close();

		Repository repository;
		Repository watchList;
		WatchList* watchListType = new CSVWatchList{ "watch_list.csv" };

		Service service(repository, watchList, watchListType);

		AdminGUI* adminGUI = new AdminGUI{ service };
		adminGUI->show(); 

		UserGUI* userGUI = new UserGUI{ service };
		userGUI->show(); 

	});
	QObject::connect(this->ui.htmlButton, &QPushButton::clicked, [&]() {
		close(); 
		
		Repository repository; 
		Repository watchList; 
		WatchList* watchListType = new HTMLWatchList{ "watch_list.html" };

		Service service(repository, watchList, watchListType); 

		AdminGUI* adminGUI = new AdminGUI{ service };
		adminGUI->show();

		UserGUI* userGUI = new UserGUI{ service };
		userGUI->show();
		
	});
	QObject::connect(this->ui.exitButton, &QPushButton::clicked, [&]() {
		exit(0);
	});

}

