#ifndef _Author_
#define _Author_

#include "ImportantLibraries.hpp"
#include "GeneralFunctions.hpp"
#include "Date.hpp"
#include "Book.hpp"
#include "WritingDefines.hpp"

class Author 
{
	private :
		int id;
		std::string name;
		int year_of_birth;
		std::string gender;
		std::string place_of_birth;
		Date member_since;
		std::vector < std::string > genres;
		std::vector < Book* > books;
	public :
		Author(int id_,std::string name_,std::string gender_,Date member_since,int year_of_birth_,std::string place_of_birth_,std::vector<std::string> genres_);
		Author();
		int getId();
		void addBook(Book* book);
		void showInfo();
		void printGenres();
		void printBooks();
		std:: string getName();	
};

bool compairBooksById(Book* book1, Book* book2);

#endif
