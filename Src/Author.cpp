#include "Author.hpp"

using namespace std;

Author::Author(int id_,string name_,string gender_,Date member_since_,int year_of_birth_,string place_of_birth_,vector<string> genres_)
{
	id=id_;
	name=name_;
	gender=gender_;
	member_since=member_since_;
	year_of_birth=year_of_birth_;
	place_of_birth=place_of_birth_;
	genres=genres_;
	books=EMPTY;
}

Author::Author()
{
	id=ZERO;
	name=BLANK;
	gender=BLANK;
	member_since=Date();
	year_of_birth=ZERO;
	place_of_birth=BLANK;
	genres=EMPTY;
	books=EMPTY;
}

int Author::getId() { return id; }

void Author::addBook(Book* book) { books.push_back(book); }

void Author::showInfo()
{
	cout<<ID<<id<<endl;
	cout<<NAME<<name<<endl;
	cout<<YEAR_OF_BIRTH<<year_of_birth<<endl;
	cout<<PLACE_OF_BIRTH<<place_of_birth<<endl;
	cout<<MEMBER_SINCE;
	member_since.print();
	cout<<endl;
	printGenres();
	printBooks();
}

void Author::printGenres()
{
	cout<<GENRES;
	sort(genres.begin(),genres.end());
	for(int i=ZERO;i<genres.size();i++)
	{
		cout<<genres[i];
		if(i!=genres.size()-1)
			cout<<COMMA<<SPACE;
	}
	cout<<endl;
}

void Author::printBooks()
{
	cout<<BOOKS<<endl;
	sort(books.begin(),books.end(),compairBooksById);
	for(int i=ZERO;i<books.size();i++)
		books[i]->printForAuthor();
}

bool compairBooksById(Book* book1, Book* book2)
{
	return book1->getId()<book2->getId();
}

string Author::getName(){return	name;}