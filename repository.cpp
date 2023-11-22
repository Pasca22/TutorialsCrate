#include "repository.h"
#include "tutorial.h"
#include <string>
#include <fstream>


Repository::Repository()
{
}

Repository::Repository(const Repository& repository)
{
	this->data = vector<TElem>(repository.data);
}

Repository::~Repository()
{
}

Repository& Repository::operator=(const Repository& repository) 
{
	this->data = repository.data;
	return *this;
}

void Repository::readFromFile(string filePath)
{
	ifstream file(filePath.c_str());

	if (file.peek() == EOF) 
	{
		file.close(); 
		return;
	}

	do
	{
		TElem newElement;
		file >> newElement; 
		this->data.push_back(newElement);

	} while (!file.eof()); 
	
	file.close();
}

void Repository::writeToFile(string filePath)
{
	ofstream file(filePath.c_str()); 

	for (TElem element : this->data) 
	{
		file << element;
		if (element != this->data.back())
		{
			file << "\n";
		}
	}
	file.close(); 
}

int Repository::getSize() const
{
	return this->data.size();
}

vector<TElem> Repository::getAll() const
{
	vector<TElem> allData(this->data.size());
	copy(this->data.begin(), this->data.end(), allData.begin());
	return allData;
}


TElem Repository::getItem(int index)   
{
	return this->data.at(index);
}

void Repository::addItem(TElem newElement)
{
	this->data.push_back(newElement);
}

void Repository::removeItem(int index)
{
	this->data.erase(data.begin() + index);
}

void Repository::updateItem(int index, string newTitle, string newPresenter, int newDuration, int newLikes, string newLink)
{
	this->data.at(index).setTitle(newTitle); 
	this->data.at(index).setPresenter(newPresenter); 
	this->data.at(index).setDuration(newDuration); 
	this->data.at(index).setLikes(newLikes); 
	this->data.at(index).setLink(newLink); 
}

int Repository::findIndexOfElement(string elementTitle, string elementPresenter)
{
	auto found = find_if(this->data.begin(), this->data.end(), [elementTitle, elementPresenter](TElem element){
		return element.getTitle() == elementTitle && element.getPresenter() == elementPresenter;
	});

	if (found == this->data.end())
	{
		return -1;
	}

	return distance(this->data.begin(), found); 
}

void Repository::incrementLikes(int indexInData)
{
	this->data.at(indexInData).setLikes(this->data.at(indexInData).getLikes() + 1);
}

//void FakeRepository::addItem(TElem element)
//{
//	return;
//}
//
//int FakeRepository::findIndexOfElement(string title, string presenter)
//{
//	return this->index;
//}
