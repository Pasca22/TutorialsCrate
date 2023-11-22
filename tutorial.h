#pragma once
#include <string>
#include <iostream>

using namespace std;

class Tutorial
{
private:
	string title;
	string presenter;
	int duration;
	int likes;
	string link;

public:
	Tutorial();
	Tutorial(string, string, int, int, string);

	~Tutorial();

	string getTitle() const;
	string getPresenter() const;
	int getDuration() const;
	int getLikes() const;
	string getLink() const;

	void setTitle(string);
	void setPresenter(string);
	void setDuration(int);
	void setLikes(int);
	void setLink(string);

	void play();

	string toString() const; 
	string toStringFileFormat();

	bool operator == (const Tutorial&);
	bool operator != (const Tutorial&);

	friend ostream& operator << (ostream& os, const Tutorial& tutorial);
	friend istream& operator >> (istream& os, Tutorial& tutorial);

};