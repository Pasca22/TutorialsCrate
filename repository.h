#pragma once
#include "tutorial.h"
#include <vector>
typedef Tutorial TElem;

class Repository
{
private:
	vector<TElem> data;

public:
	Repository();
	Repository(const Repository& repository);
	~Repository();

	Repository& operator = (const Repository& repository);

	void readFromFile(string);
	void writeToFile(string);

	int getSize() const;
	TElem getItem(int);
	virtual void addItem(TElem);
	void removeItem(int);
	void updateItem(int, string, string, int, int, string);

	vector<TElem> getAll() const;

	virtual int findIndexOfElement(string, string);

	void incrementLikes(int);
};

//class FakeRepository : public Repository
//{
//public:
//
//	int index;
//
//	void addItem(TElem) override;
//	int findIndexOfElement(string, string) override;
//};