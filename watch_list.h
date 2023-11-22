#pragma once
#include "repository.h" 

class WatchList
{
protected:
	string filePath;

public:
	WatchList();
	WatchList(string filePath);
	~WatchList();

	virtual void writeToFile(vector<TElem> watchList) = 0;
	virtual void showWatchList() = 0;

};


class CSVWatchList : public WatchList
{

public:
	CSVWatchList(string filePath);
	~CSVWatchList();

	void writeToFile(vector<TElem> watchList) override;
	void showWatchList() override;
};


class HTMLWatchList : public WatchList
{

public:
	HTMLWatchList(string filePath);
	~HTMLWatchList();

	void writeToFile(vector<TElem> watchList) override;
	void showWatchList() override;
};