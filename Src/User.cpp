#include "User.hpp"

using namespace std;

User:: User(int id_,string name_,string place_of_birth_,Date member_since_,vector<string> favorite_genres_, 
		vector<Author*> favorite_authors_,vector<Book*> shelfs_[NUMBER_OF_SHELFS])
{
	id=id_;
	name=name_;
	place_of_birth=place_of_birth_;
	member_since=member_since_;
	favorite_genres=favorite_genres_;
	favorite_authors=favorite_authors_;
	shelfs[READ]=shelfs_[READ];
	shelfs[CURRENTLY_READING]=shelfs_[CURRENTLY_READING];
	shelfs[WANT_TO_READ]=shelfs_[WANT_TO_READ];
	reviews=EMPTY;
	followings=EMPTY;
	followers=EMPTY;
	number_of_reviews_likes=ZERO;
}

User::User()
{
	id=ZERO;
	name=BLANK;
	place_of_birth=BLANK;
	member_since=Date();
	favorite_genres=EMPTY;
	favorite_authors=EMPTY;
	shelfs[READ]=EMPTY;
	shelfs[CURRENTLY_READING]=EMPTY;
	shelfs[WANT_TO_READ]=EMPTY;
	reviews=EMPTY;
	followings=EMPTY;
	followers=EMPTY;
	number_of_reviews_likes=ZERO;
}

int User::getId() { return id; }

void User::addReview(Review* review)
{ 
	reviews.push_back(review); 
	number_of_reviews_likes+=review->getNumberOfLikes();
}

void User::addFollowingUser(User* following_user) { followings.push_back(following_user); }

void User::addFollowerUser(User* follower_user) { followers.push_back(follower_user) ;}

void User::showSortedShelf(int shelf_type, string genre)
{
	vector<Book> same_genre, different_genre;
	for(int i=ZERO;i<shelfs[shelf_type].size();i++)
	{
		if(shelfs[shelf_type][i]->getGenre()==genre)
			same_genre.push_back(*shelfs[shelf_type][i]);
		else
			different_genre.push_back(*shelfs[shelf_type][i]);
	}
	sortAndShowBooks(same_genre);
	sortAndShowBooks(different_genre);
}

void User::sortAndShowBooks(vector <Book> books_for_print)
{
	sort(books_for_print.begin(),books_for_print.end(),compairBooksByNameAndId);
	for(int i=ZERO;i<books_for_print.size();i++)
		books_for_print[i].showForUser();
}

bool compairBooksByNameAndId(Book book1, Book book2)
{
	if(book1.getTitle()!=book2.getTitle())
		return book1.getTitle()<book2.getTitle();
	else
		return book1.getId()<book2.getId();
}

double User::getCredit(int total_number_of_likes, int total_number_of_reviews)
{
	return HALF*(divide((double)number_of_reviews_likes,(double)total_number_of_likes)+
		divide((double)reviews.size(),(double)total_number_of_reviews));
}

int User::getNumberOfReviewsLikes(){ return number_of_reviews_likes;}

void User::showForBestReviewer()
{
	cout<<ID<<id<<endl;
	cout<<NAME<<name<<endl;
	cout<<PLACE_OF_BIRTH<<place_of_birth<<endl;
	cout<<MEMBER_SINCE;
	member_since.print();
	cout<<endl;
	showFavoriteGenres();
	showFavoriteAuthors();
	cout<<NUMBER_OF_BOOKS_IN_READ_SHELF<<shelfs[READ].size()<<endl;
	cout<<NUMBER_OF_BOOKS_IN_WANT_TO_READ_SHELF<<shelfs[WANT_TO_READ].size()<<endl;
	cout<<NUMBER_OF_BOOKS_IN_CURRENTLY_READING_SHELF<<shelfs[CURRENTLY_READING].size()<<endl;
	cout<<NUMBER_OF_LIKES<<number_of_reviews_likes<<endl;
}

void User::showFavoriteGenres()
{
	cout<<FAVORITE_GENRES;
	sort(favorite_genres.begin(),favorite_genres.end());
	for(int i=ZERO;i<favorite_genres.size();i++)
	{
		cout<<favorite_genres[i];
		if(i!=favorite_genres.size()-1)
			cout<<COMMA<<SPACE;
	}
	cout<<endl;
}

void User::showFavoriteAuthors()
{
	cout<<FAVORITE_AUTHORS;
	sort(favorite_authors.begin(),favorite_authors.end(),compairAuthorsById);
	for(int i=ZERO;i<favorite_authors.size();i++)
	{
		cout<<favorite_authors[i]->getName();
		if(i!=favorite_authors.size()-1)
			cout<<COMMA<<SPACE;
	}
	cout<<endl;
}

bool compairAuthorsById(Author* author1, Author* author2)
{
	return author1->getId()<author2->getId();
}

vector<string> User::getFavoriteGenres(){return favorite_genres;};

Book* User::getRecommendSecondApproach()
{
	vector<Book*> recommended_books=getRecommendedBooks();
	return findMostRepeatedBook(recommended_books);
}

vector<Book*> User::getRecommendedBooks()
{
	map<int,bool> checked_user;
	checked_user[id]=true;
	vector<Book*> recommended_books;
	for(int i=ZERO;i<followings.size();i++)
		followings[i]->suggestBooks(recommended_books,checked_user);
	return recommended_books;
}

void User::suggestBooks(vector<Book*>& recommended_books, map<int,bool>& checked_user)
{
	if(checked_user[id])
		return;
	checked_user[id]=true;
	suggestYourBestBooks(recommended_books);
	for(int i=ZERO;i<followings.size();i++)
		followings[i]->suggestBooks(recommended_books,checked_user);
}

void  User::suggestYourBestBooks(vector<Book*>& recommended_books)
{
	sort(shelfs[READ].begin(),shelfs[READ].end(),compairBooksByScoreAndId);
	for(int i=ZERO;i<min(THREE,(int)shelfs[READ].size());i++)
		recommended_books.push_back(shelfs[READ][i]);
}

bool compairBooksByScoreAndId(Book* book1, Book* book2)
{
	if(book1->getScore()!=book2->getScore())
		return (book1->getScore() > book2->getScore());
	return book1->getId() < book2->getId();
}

Book* User::findMostRepeatedBook(vector<Book*> chosen_books)
{
	map<Book*,int> counter;
	for(int i=ZERO;i<chosen_books.size();i++)
		counter[chosen_books[i]]++;
	Book* most_repeated_book=chosen_books[ZERO];
	for(int i=ONE;i<chosen_books.size();i++)
		if(comairBooksByReapeat(chosen_books[i],most_repeated_book,counter))
			most_repeated_book=chosen_books[i];
	return most_repeated_book;
}

bool User::comairBooksByReapeat(Book* book1, Book* book2, map<Book*,int> counter)
{
	if(counter[book1]!=counter[book2])
		return counter[book1]>counter[book2];
	return book1->getId()<book2->getId();
}
