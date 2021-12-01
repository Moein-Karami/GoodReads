#ifndef _User_
#define _User_

#include "ImportantLibraries.hpp"
#include "GeneralFunctions.hpp"
#include "Date.hpp"
#include "Author.hpp"
#include "Book.hpp"
#include "Review.hpp"
#include "WritingDefines.hpp"

#define NUMBER_OF_SHELFS 3
#define WANT_TO_READ 2
#define CURRENTLY_READING 1
#define READ 0

const double HALF=0.5;

class User 
{
	private:
		int id;
		std::string name;
		std::string place_of_birth;
		Date member_since;
		std::vector < Author* > favorite_authors;
		std::vector < std::string > favorite_genres;
		std::vector < Book* > shelfs[NUMBER_OF_SHELFS];
		std::vector < Review* > reviews;
		std::vector < User* > followings;
		std::vector < User* > followers;
		int number_of_reviews_likes;
	public:
		User(int id_,std::string name_,std::string place_of_birth_,
				Date member_since_,std::vector<std::string> favorite_genres_,
				std::vector<Author*> favorite_authors_,
				std::vector<Book*> shelfs_[NUMBER_OF_SHELFS]);
		User();
		int getId();
		void addReview(Review* review);
		void addFollowingUser(User* following_user);
		void addFollowerUser(User* follower_user);
		void showSortedShelf(int shelf_type,std::string genre);
		void sortAndShowBooks(std::vector<Book> books_for_print);
		double getCredit(int total_number_of_likes, int total_number_of_reviews);
		int getNumberOfReviewsLikes();
		void showForBestReviewer();
		void showFavoriteGenres();
		void showFavoriteAuthors();
		std::vector<std::string> getFavoriteGenres();
		Book* getRecommendSecondApproach();
		std::vector<Book*> getRecommendedBooks();
		void suggestBooks(std::vector<Book*>& recommended_books, std::map<int,bool>& checked_user);
		void  suggestYourBestBooks(std::vector<Book*>& recommended_books);
		Book* findMostRepeatedBook(std::vector<Book*> chosen_books);
		bool comairBooksByReapeat(Book* book1, Book* book2, std::map<Book*,int> counter);

};

bool compairBooksByNameAndId(Book book1, Book book2);
bool compairAuthorsById(Author* author1, Author* author2);
bool compairBooksByScoreAndId(Book* book1, Book* book2);

#endif
