#pragma once
#include "a89.h"
#include "service.h"
#include "tutorial.h"
#include "tutorial_validator.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <qdebug.h>
#include <qmessagebox.h>


using namespace std;

class GUI : public QWidget
{
public:
	GUI(Service& service) 
	{ 
		this->service = service;
		this->service.readFromFile();
		run();
		loadData();
		initConnect();
	};
	~GUI() 
	{
		this->service.writeToFile(); 
	};  
private:

	Service service;

	Tutorial selectedTutorial;
	
	QListWidget* listWithData = new QListWidget{}; 
	QPushButton* exitButton = new QPushButton{ "&Exit" }; 
	QPushButton* addButton = new QPushButton{ "&Add" };
	QPushButton* deleteButton = new QPushButton{ "&Delete" };
	QPushButton* updateButton = new QPushButton{ "&Update" };
	QLineEdit* titleTextBox = new QLineEdit{};
	QLineEdit* presenterTextBox = new QLineEdit{};
	QLineEdit* durationTextBox = new QLineEdit{};
	QLineEdit* likesTextBox = new QLineEdit{};
	QLineEdit* linkTextBox = new QLineEdit{};


	void initConnect()
	{
		QObject::connect(exitButton, &QPushButton::clicked, [&]() {
			close();
			});
		QObject::connect(addButton, &QPushButton::clicked, [&]() {
			auto name = titleTextBox->text();
			auto presenter = presenterTextBox->text(); 
			auto duration = durationTextBox->text(); 
			auto likes = likesTextBox->text();
			auto link = linkTextBox->text();
			
			try
			{
				this->service.addElement(name.toStdString(), presenter.toStdString(), stoi(duration.toStdString()), stoi(likes.toStdString()), link.toStdString());
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

		QObject::connect(deleteButton, &QPushButton::clicked, [&]() {

			try
			{
				this->service.removeElement(selectedTutorial.getTitle(), selectedTutorial.getPresenter()); 

			}
			catch (exception& )
			{
				QMessageBox::critical(this, "Error", "Item not in list");

			}

			loadData(); 
			});

		QObject::connect(updateButton, &QPushButton::clicked, [&]() {
			auto title = titleTextBox->text(); 
			auto presenter = presenterTextBox->text(); 
			auto duration = durationTextBox->text(); 
			auto likes = likesTextBox->text(); 
			auto link = linkTextBox->text(); 

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

		QObject::connect(listWithData, &QListWidget::itemSelectionChanged, [&]() {
			auto selected = listWithData->selectedItems();
			if (selected.isEmpty())
			{
				titleTextBox->setText("");
				presenterTextBox->setText("");
				durationTextBox->setText("");
				likesTextBox->setText("");
				linkTextBox->setText("");

				selectedTutorial = Tutorial{ "", "", 0, 0, "" }; 

				return;
			}
			else
			{
				auto item = selected.at(0); 
				auto parts = item->text().split(" | "); 
				titleTextBox->setText(parts.at(0)); 
				presenterTextBox->setText(parts.at(1)); 
				durationTextBox->setText(parts.at(2)); 
				likesTextBox->setText(parts.at(3)); 
				linkTextBox->setText(parts.at(4)); 

				selectedTutorial = Tutorial{ parts.at(0).toStdString(), parts.at(1).toStdString(), stoi(parts.at(2).toStdString()), stoi(parts.at(3).toStdString()), parts.at(4).toStdString() };
			}
			});

	}

	void loadData()
	{
		listWithData->clear();
		
		vector<Tutorial> tutorials = service.getAllData();

		for (const auto& t : tutorials)
			listWithData->addItem(QString::fromStdString(t.toString()));
	}

	void run()
	{
		QHBoxLayout* mainLayout = new QHBoxLayout{}; 
		setLayout(mainLayout);

		mainLayout->addWidget(listWithData); 
		 
		auto formAndButtonsLayout = new QVBoxLayout{}; 

		auto formLayout = new QFormLayout{};
		formLayout->addRow("Name", titleTextBox);
		formLayout->addRow("Presenter", presenterTextBox);
		formLayout->addRow("Duration", durationTextBox);
		formLayout->addRow("Likes", likesTextBox);
		formLayout->addRow("Link", linkTextBox);

		formAndButtonsLayout->addLayout(formLayout);


		auto buttonsLayout = new QHBoxLayout{};
		buttonsLayout->addWidget(addButton);
		buttonsLayout->addWidget(deleteButton);
		buttonsLayout->addWidget(updateButton);	
		buttonsLayout->addWidget(exitButton); 

		formAndButtonsLayout->addLayout(buttonsLayout);

		mainLayout->addLayout(formAndButtonsLayout);

	}

};