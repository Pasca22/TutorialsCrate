#include "service.h"
#include "repository.h"
#include "tutorial_validator.h"

Service::Service() 
{
	this->watchListType = new CSVWatchList{ "watch_list.csv" };
}


Service::Service(Repository r, Repository w, WatchList* wlt) : repository{ r }, watchList{ w }, watchListType{ wlt }
{
	this->readFromFile();
}


Service::~Service()
{
	this->writeToFile();
}

vector<TElem> Service::getAllData()   
{
	return this->repository.getAll();
}

vector<TElem> Service::getWatchList()
{
	return this->watchList.getAll(); 
}

void Service::addElement(string newTitle, string newPresenter, int newDuration, int newLikes, string newLink)
{
	if (this->repository.findIndexOfElement(newTitle, newPresenter) != -1)
	{
		throw exception();
	}

	TElem newElement(newTitle, newPresenter, newDuration, newLikes, newLink);

	TutorialValidator validator;
	validator.validate(newElement);
	this->repository.addItem(newElement);
}

void Service::updateElement(int indexOfElement, string newTitle, string newPresenter, int newDuration, int newLikes, string newLink)
{
	TElem newElement(newTitle, newPresenter, newDuration, newLikes, newLink);
	TutorialValidator validator; 
	validator.validate(newElement); 

	this->repository.updateItem(indexOfElement, newTitle, newPresenter, newDuration, newLikes, newLink);
}

void Service::removeElement(string title, string presenter)
{
	int indexOfElement = this->repository.findIndexOfElement(title, presenter);
	if (indexOfElement == -1)
	{
		throw exception();
	}

	this->repository.removeItem(indexOfElement);
}

void Service::addElementToWatchList(TElem tutorial)
{
	this->watchList.addItem(tutorial);
}

void Service::deleteElementFromWatchList(TElem tutorial)
{
	int indexOfElement = this->watchList.findIndexOfElement(tutorial.getTitle(), tutorial.getPresenter());
	if (indexOfElement == -1)
	{
		throw exception();
	}

	this->watchList.removeItem(indexOfElement);
}

void Service::incrementLikes(TElem tutorial)
{
	int indexOfElementInData = this->repository.findIndexOfElement(tutorial.getTitle(), tutorial.getPresenter());

	this->repository.incrementLikes(indexOfElementInData);

}

vector<TElem> Service::getTutorialByString(string userGivenString)
{
	if (userGivenString == "")
	{
		return this->repository.getAll();
	}
	
	vector<TElem> tutorialsByString;
	vector<TElem> allData = this->repository.getAll();

	for (TElem element : allData)
	{
		if (element.getPresenter() == userGivenString)
		{
			tutorialsByString.push_back(element);
		}
	}
	return tutorialsByString;
}

int Service::indexOfElementInData(string title , string presenter)
{
	return this->repository.findIndexOfElement(title, presenter);
}

int Service::indexOfElementInWatchList(TElem tutorial)
{
	return this->watchList.findIndexOfElement(tutorial.getTitle(), tutorial.getPresenter()); 
}


void Service::readFromFile()
{
	string data = "tutorials.txt";
	this->repository.readFromFile(data);
}

void Service::writeToFile()
{
	string data = "tutorials.txt";
	this->repository.writeToFile(data);
}

void Service::writeWatchListToFile()
{
	vector<TElem> watchList = this->watchList.getAll(); 
	this->watchListType->writeToFile(watchList);
}

void Service::openWatchList()
{
	this->watchListType->showWatchList();
}
