#include "a89.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include "gui.h"
#include "repository.h"
#include "service.h"
#include "tests.h"
#include "a89.h"
#include <memory>
#include "userGUI.h"
#include "startGUI.h"


int main(int argc, char *argv[])
{ 	
	QApplication a(argc, argv);

	StartGUI startGUI;
	startGUI.show();

	/*Repository repository;
	Repository watchList;
	WatchList* watchListType;

	if (startGUI.getIsCSV())
	{
		watchListType = new CSVWatchList{ "watch_list.csv" };
	}
	else
	{
		watchListType = new HTMLWatchList{ "watch_list.html" };
	}

	Service service(repository, watchList, watchListType);

	AdminGUI adminGUI{service};
	adminGUI.show(); 

	UserGUI userGUI{service};  
	userGUI.show();*/


	return a.exec(); 
	
}
