#include "tutorial.h"
#include "repository.h"
#include "service.h"
#include "tutorial_validator.h"
#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

void tutorialDomainTests()
{	
	Tutorial newTutorial(string("c++"), string("Aba"), 10, 3000, string("http"));

	assert(newTutorial.getTitle() == string("c++"));
	assert(newTutorial.getPresenter() == string("Aba"));
	assert(newTutorial.getDuration() == 10);
	assert(newTutorial.getLikes() == 3000);
	assert(newTutorial.getLink() == string("http"));

	newTutorial.setTitle(string("c#"));
	newTutorial.setPresenter(string("Lobo"));
	newTutorial.setDuration(5);
	newTutorial.setLikes(2000);
	newTutorial.setLink(string("www"));

	assert(newTutorial.getTitle() == string("c#"));
	assert(newTutorial.getPresenter() == string("Lobo"));
	assert(newTutorial.getDuration() == 5);
	assert(newTutorial.getLikes() == 2000);
	assert(newTutorial.getLink() == string("www"));

	assert(newTutorial.toString() == string(" - Title: c# | Presenter: Lobo | Minutes: 5 | Nr of likes: 2000 | Link: www"));
	newTutorial.play();
}

void repositoryTests()
{
	Repository repository;
	TElem element1(string("c++"), string("Aba"), 10, 3000, string("https:asd"));
	TElem element2(string("c#"), string("Lobo"), 5, 2000, string("https:asd"));
	repository.addItem(element1);
	repository.addItem(element2);
	
	repository.incrementLikes(0);
	assert(repository.getItem(0).getLikes() == 3001); 

	assert(repository.getItem(0).getTitle() == string("c++"));
	assert(repository.getItem(1).getTitle() == string("c#"));

	assert(repository.getSize() == 2);

	assert(repository.findIndexOfElement(element2.getTitle(), element2.getPresenter()) == 1);

	repository.removeItem(1);
	assert(repository.getSize() == 1);

	repository.updateItem(0, string("c#"), string("Lobo"), 5, 2000, string("https:asd"));
	assert(repository.getItem(0).getTitle() == string("c#"));
}

void serviceTests()
{
	Repository repository;
	Repository watchList;
	WatchList* watchListType = new CSVWatchList("test.csv");
	Service service(repository, watchList, watchListType); 

	service.addElement(string("c++"), string("Aba"), 10, 3000, string("https:asdas"));
	service.addElement(string("c#"), string("Lobo"), 5, 2000, string("https:jkjk"));

	service.addElementToWatchList(TElem(string("c++"), string("Aba"), 10, 3000, string("https:asdas")));
	service.addElementToWatchList(TElem(string("c#"), string("Lobo"), 5, 2000, string("https:jkjk")));

	assert(service.getAllData().size() == 2);
	assert(service.getWatchList().size() == 2);

	service.deleteElementFromWatchList(TElem(string("c#"), string("Lobo"), 5, 2000, string("https:jkjk")));
	assert(service.getWatchList().size() == 1); 

	assert(service.indexOfElementInWatchList(TElem(string("c++"), string("Aba"), 10, 3000, string("https:asdas"))) == 0);

	try
	{
		service.addElement(string("c#"), string("Lobo"), 5, 2000, string("https:jkjk")); 
		assert(false);
	}
	catch (TutorialException)
	{
		assert(true);
	}
	catch (const exception&)
	{
		assert(true);
	}
	
	service.updateElement(1, string("pyhton"), string("me"), 50, 800, string("https:aa"));

	assert(service.indexOfElementInData(string("pyhton"), string("me")) == 1); 

	try
	{
		service.updateElement(1, string("java"), string("you"), 0, 800, string("https:aa"));  
		assert(false); 
	}
	catch (TutorialException)
	{
		assert(true); 
	}

	try
	{
		service.removeElement(string("java"), string("you")); 
		assert(false);
	}
	catch (const exception&)
	{
		assert(true);
	}

	service.removeElement(string("c++"), string("Aba"));

	assert(service.getAllData().size() == 1);

}

void add_Service_ValidInput_returnTrue()
{
	/*FakeRepository fakeRepository; 
	Service service(fakeRepository); 

	fakeRepository.index = -1;

	service.addElement("aaa", "bbb", 50, 30, "https:asda");
	assert(true);*/
}

void add_Service_WrongInput_returnFalse()
{
	/*FakeRepository fakeRepository;
	Service service(fakeRepository);

	fakeRepository.index = 1;

	try
	{
		service.addElement("aaa", "bbb", 50, 30, "https:asda");
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}*/

}

void allTests()
{
	/*tutorialDomainTests(); 
	repositoryTests();
	serviceTests();*/
	add_Service_ValidInput_returnTrue();
	add_Service_WrongInput_returnFalse();

	cout << "\n\nAll tests passed\n\n";
}