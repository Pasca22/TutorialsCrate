#pragma once
#include "repository.h"
#include "watch_list.h"

class Service
{
private:
	Repository repository; 
	Repository watchList;
	WatchList* watchListType;

public:
	Service();
	Service(Repository, Repository, WatchList*); 
	~Service();

	vector<TElem> getAllData();
	vector<TElem> getWatchList();
	void addElement(string, string, int, int, string);
	void updateElement(int, string, string, int, int, string);
	void removeElement(string, string);

	void addElementToWatchList(TElem);
	void deleteElementFromWatchList(TElem);

	void incrementLikes(TElem);

	vector<TElem> getTutorialByString(string);

	int indexOfElementInData(string, string);

	int indexOfElementInWatchList(TElem);

	void readFromFile();
	void writeToFile();

	void writeWatchListToFile();
	void openWatchList(); 

};