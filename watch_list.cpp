#include "watch_list.h"
#include <fstream>
#include <QUrl>
#include <QDesktopServices>
#include <QProcess>

using namespace std; 

WatchList::WatchList()
{
}

WatchList::WatchList(string filePath) : filePath{ filePath }
{
}

WatchList::~WatchList() 
{
}




CSVWatchList::CSVWatchList(string filePath) : WatchList{ filePath }
{
}

CSVWatchList::~CSVWatchList()
{
}

void CSVWatchList::writeToFile(vector<TElem> watchList)
{
	ofstream file(this->filePath.c_str());

	file << "Title,Presenter,Minutes,Likes,Link\n";

	for (Tutorial tutorial : watchList)  
	{
		file << tutorial.getTitle() << "," << tutorial.getPresenter() << "," << tutorial.getDuration() << "," << tutorial.getLikes() << "," << tutorial.getLink() << "\n"; 
	}
	file.close(); 
}

void CSVWatchList::showWatchList()
{
	QStringList arguments;
	arguments << QString::fromStdString(this->filePath);

	QProcess::startDetached("notepad.exe", arguments);
}



HTMLWatchList::HTMLWatchList(string filePath) : WatchList{ filePath }
{
}

HTMLWatchList::~HTMLWatchList()
{
}

void HTMLWatchList::writeToFile(vector<TElem> watchList)
{
	const string htmlHeader = "<!DOCTYPE html>\n"
								"<html>\n"
								"<head>\n"
								"\t<title>Watch List</title>\n"
								"</head>\n"
								"<body>\n"
								"<table border=\"1\" style=\"text-align: center; width: 100%;\">\n"
									"\t<tr>\n"
										"\t\t<td>Title</td>\n"
										"\t\t<td>Presenter</td>\n"
										"\t\t<td>Minutes</td>\n"
										"\t\t<td>Likes</td>\n"
										"\t\t<td>Link</td>\n"
									"\t</tr>\n";

	const string htmlFooter = "</table>\n"
							  "</body>\n"
							  "</html>"; 

	ofstream file(this->filePath.c_str()); 

	file << htmlHeader; 
	for (Tutorial tutorial : watchList)
	{
		file << "\t<tr>\n" 
				"\t\t<td>" << tutorial.getTitle() << "</td>\n" 
				"\t\t<td>" << tutorial.getPresenter() << "</td>\n" 
				"\t\t<td>" << tutorial.getDuration() << "</td>\n"  
				"\t\t<td>" << tutorial.getLikes() << "</td>\n" 
				"\t\t<td><a href = \"" << tutorial.getLink() << "\">Link to tutorial</a></td>\n" 
			"\t</tr>\n";
	}
	file << htmlFooter; 

	file.close();  
}

void HTMLWatchList::showWatchList()
{
	QDesktopServices::openUrl(QUrl::fromLocalFile("watch_list.html")); 
}
