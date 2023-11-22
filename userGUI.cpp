#include "userGUI.h"
#include <string>
#include <qmessagebox.h>

using namespace std;

UserGUI::UserGUI(Service s, QWidget* parent)
	: QMainWindow(parent), service{ s }
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

UserGUI::~UserGUI()
{}

void UserGUI::connectSignalsAndSlots()
{
	QObject::connect(this->ui.searchButton, &QPushButton::clicked, [&]() {

		auto presenter = this->ui.filterByPresenterLineEdit->text();

		this->ui.filteredByPresenterList->clear();

		this->tutorialsFiltered = this->service.getTutorialByString(presenter.toStdString());

		for (const auto& t : this->tutorialsFiltered)
			this->ui.filteredByPresenterList->addItem(QString::fromStdString(t.toString()));

		});

	QObject::connect(this->ui.filteredByPresenterList, &QListWidget::itemSelectionChanged, [&]() {
		auto selected = this->ui.filteredByPresenterList->selectedItems();
		if (selected.isEmpty())
		{
			selectedTutorial = Tutorial{ "", "", 0, 0, "" };
			return;
		}
		else
		{
			auto item = selected.at(0);
			auto parts = item->text().split(" | ");

			selectedTutorial = Tutorial{ parts.at(0).toStdString(), parts.at(1).toStdString(), stoi(parts.at(2).toStdString()), stoi(parts.at(3).toStdString()), parts.at(4).toStdString() };
		}
		});

	QObject::connect(this->ui.addToWatchListButton, &QPushButton::clicked, [&]() {
		
		if (selectedTutorial.getTitle() == "")
		{
			QMessageBox::critical(this, "Error", "No tutorial selected");
			return;
		}

		this->service.addElementToWatchList(selectedTutorial); 
		this->service.writeWatchListToFile(); 

		});

	QObject::connect(this->ui.deleteFromWatchListButton, &QPushButton::clicked, [&]() {
		try
		{
			this->service.deleteElementFromWatchList(selectedTutorial);
			this->service.writeWatchListToFile(); 
		}
		catch (exception&)
		{
			QMessageBox::critical(this, "Error", "Tutorial not in Watch List");
			return;
		}
		});

	QObject::connect(this->ui.openOnYoutubeButton, &QPushButton::clicked, [&]() {
		if (selectedTutorial.getTitle() == "")
		{
			QMessageBox::critical(this, "Error", "No tutorial selected");
			return;
		}

		selectedTutorial.play();
		});

	QObject::connect(this->ui.seeWatchListButton, &QPushButton::clicked, [&]() {
		
		this->service.writeWatchListToFile(); 
		this->service.openWatchList();

		});

}

