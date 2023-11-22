#include "a89.h"
#include "tutorial.h"
#include <qmessagebox.h>
#include "tutorial_validator.h"

using namespace std;

AdminGUI::AdminGUI(Service s, QWidget *parent)
    : QMainWindow(parent), service{ s }
{
    ui.setupUi(this);
	this->loadData(); 
	this->connectSignalsAndSlots(); 
}

AdminGUI::~AdminGUI()
{
}

void AdminGUI::loadData()
{
	this->ui.listWithData->clear(); 

	vector<Tutorial> tutorials = this->service.getAllData();

	for (const auto& t : tutorials)
		this->ui.listWithData->addItem(QString::fromStdString(t.toString()));
}

void AdminGUI::connectSignalsAndSlots()
{
	QObject::connect(this->ui.exitButton, &QPushButton::clicked, [&]() {
		close(); 
		});
	QObject::connect(this->ui.addButton, &QPushButton::clicked, [&]() {
		
		auto title = this->ui.titleLineEdit->text();
		auto presenter = this->ui.presnterLineEdit->text();
		auto duration = this->ui.durationLineEdit->text();
		auto likes = this->ui.likesLineEdit->text();
		auto link = this->ui.linkLineEdit->text();

		try
		{
			this->service.addElement(title.toStdString(), presenter.toStdString(), stoi(duration.toStdString()), stoi(likes.toStdString()), link.toStdString());
		}
		catch (exception&)
		{
			QMessageBox::critical(this, "Error", "Tutorial already in list");
		}
		catch (TutorialException&)
		{
			QMessageBox::critical(this, "Error", "Please introduce valid input");
		}

		loadData();
		});

	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, [&]() {

		try
		{
			this->service.removeElement(selectedTutorial.getTitle(), selectedTutorial.getPresenter());

		}
		catch (exception&)
		{
			QMessageBox::critical(this, "Error", "Item not in list");

		}

		loadData();
		});

	QObject::connect(this->ui.updateButton, &QPushButton::clicked, [&]() {
		
		auto title = this->ui.titleLineEdit->text();
		auto presenter = this->ui.presnterLineEdit->text();
		auto duration = this->ui.durationLineEdit->text();
		auto likes = this->ui.likesLineEdit->text();
		auto link = this->ui.linkLineEdit->text();

		try
		{
			int index = this->service.indexOfElementInData(selectedTutorial.getTitle(), selectedTutorial.getPresenter());
			this->service.updateElement(index, title.toStdString(), presenter.toStdString(), stoi(duration.toStdString()), stoi(likes.toStdString()), link.toStdString());
		}
		catch (TutorialException&)
		{
			QMessageBox::critical(this, "Error", "Please introduce valid input");
		}

		loadData();
		});

	QObject::connect(this->ui.listWithData, &QListWidget::itemSelectionChanged, [&]() {
		auto selected = this->ui.listWithData->selectedItems();
		if (selected.isEmpty())
		{
			this->ui.titleLineEdit->setText("");
			this->ui.presnterLineEdit->setText("");
			this->ui.durationLineEdit->setText("");
			this->ui.likesLineEdit->setText("");
			this->ui.linkLineEdit->setText("");

			selectedTutorial = Tutorial{ "", "", 0, 0, "" };

			return;
		}
		else
		{
			auto item = selected.at(0);
			auto parts = item->text().split(" | ");
			this->ui.titleLineEdit->setText(parts.at(0));
			this->ui.presnterLineEdit->setText(parts.at(1));
			this->ui.durationLineEdit->setText(parts.at(2));
			this->ui.likesLineEdit->setText(parts.at(3));
			this->ui.linkLineEdit->setText(parts.at(4));

			selectedTutorial = Tutorial{ parts.at(0).toStdString(), parts.at(1).toStdString(), stoi(parts.at(2).toStdString()), stoi(parts.at(3).toStdString()), parts.at(4).toStdString() };
		}
		});
}
