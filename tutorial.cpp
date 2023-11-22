#include "tutorial.h"
#include <iostream>
#include <vector>
#include <QUrl>
#include <QDesktopServices>


using namespace std;

Tutorial::Tutorial()
{
	this->title = "";
	this->presenter = "";
	this->duration = 0;
	this->likes = 0;
	this->link = "";
}

Tutorial::Tutorial(string newTitle, string newPresenter, int newDuration, int newLikes, string newLink)
{
	this->title = newTitle;
	this->presenter = newPresenter;
	this->duration = newDuration;
	this->likes = newLikes;
	this->link = newLink;
}

Tutorial::~Tutorial()
{
}

string Tutorial::getTitle() const
{
	return this->title;
}

string Tutorial::getPresenter() const
{
	return this->presenter;
}

int Tutorial::getDuration() const
{
	return this->duration;
}

int Tutorial::getLikes() const
{
	return this->likes;
}

string Tutorial::getLink() const
{
	return this->link;
}

void Tutorial::setTitle(string newTitle)
{
	this->title = newTitle;
}

void Tutorial::setPresenter(string newPresenter)
{
	this->presenter = newPresenter;
}

void Tutorial::setDuration(int newDuration)
{
	this->duration = newDuration;
}

void Tutorial::setLikes(int newLikes)
{
	this->likes = newLikes;
}

void Tutorial::setLink(string newLink)
{
	this->link = newLink;
}

void Tutorial::play()
{
	QDesktopServices::openUrl(QUrl(this->getLink().c_str())); 
}

string Tutorial::toString() const
{
	string tutorialString = "";
	tutorialString += this->getTitle();

	tutorialString += " | ";
	tutorialString += this->getPresenter();

	tutorialString += " | ";
	tutorialString += to_string(this->getDuration());

	tutorialString += " | ";
	tutorialString += to_string(this->getLikes());

	tutorialString += " | ";
	tutorialString += this->getLink();

	return tutorialString;
}

string Tutorial::toStringFileFormat()
{
	string tutorialString = "";
	tutorialString += this->getTitle(); 

	tutorialString += "|";
	tutorialString += this->getPresenter(); 

	tutorialString += "|";
	tutorialString += to_string(this->getDuration()); 

	tutorialString += "|";
	tutorialString += to_string(this->getLikes()); 

	tutorialString += "|";
	tutorialString += this->getLink(); 

	return tutorialString; 
}

bool Tutorial::operator==(const Tutorial& tutorial)
{
	if (this->getTitle() == tutorial.getTitle() && this->getPresenter() == tutorial.getPresenter() && this->getDuration() == tutorial.getDuration() && this->getLikes() == tutorial.getLikes() && this->getLink() == tutorial.getLink())
	{
		return true;
	}
	return false;
}

bool Tutorial::operator != (const Tutorial& tutorial)
{
	return !this->operator == (tutorial);
}

ostream& operator << (ostream& out, const Tutorial& tutorial)
{
	out << tutorial.getTitle() << "|" << tutorial.getPresenter() << "|" << tutorial.getDuration() << "|" << tutorial.getLikes() << "|" << tutorial.getLink();
	return out;
}

istream& operator >> (istream& in, Tutorial& tutorial)
{
	string lineOfFile;
	getline(in, lineOfFile);

	char* lineOfFileString = new char[lineOfFile.size() + 1];
	strcpy(lineOfFileString, lineOfFile.c_str());


	char* token = strtok(lineOfFileString, "|"); 
	string title = token; 
	token = strtok(NULL, "|"); 
	string presenter = token; 
	token = strtok(NULL, "|"); 
	int duration = atoi(token);
	token = strtok(NULL, "|"); 
	int likes = atoi(token); 
	token = strtok(NULL, "|"); 
	string link = token;
	
	tutorial.setTitle(title); 
	tutorial.setPresenter(presenter); 
	tutorial.setDuration(duration); 
	tutorial.setLikes(likes); 
	tutorial.setLink(link); 

	delete[] lineOfFileString;
	
	return in;
}
