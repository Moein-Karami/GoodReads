#ifndef _GoodReads_
#define _GoodReads_

#include "ImportantLibraries.hpp"
#include "GeneralFunctions.hpp"
#include "ReadingDefines.hpp"
#include "User.hpp"
#include "Author.hpp"
#include "Book.hpp"
#include "Review.hpp"
#include "WritingDefines.hpp"

class GoodReads 
{
	private:
		std::vector < User* > users;
		std::vector < Author* > authors;
		std::vector < Book* > books;
		std::vector < Review* > reviews;
		int number_of_reviews_likes;
	public:
		GoodReads( std::string assets_directory );
		void readAuthorsData(std::string path);
		void readOneAuthorData(std::vector<std::string> data);
		void readBooksData(std::string path);
		void readOneBookData(std::vector<std::string> data);
		void addBookToAuthor(Book* book , int author_id);
		Author* findOneAuthor(int id);
		void readUsersData(std::string path);
		void readOneUserData(std::vector<std::string> data);
		std::vector<Book*> findBooks(std::string books_id_str);
		Book* findOneBook(int id);
		std::vector<Author*> findAuthors(std::string authors_id_str);
		void readReviewsData(std::string path);
		void readOneReviewData(std::vector<std::string> data);
		void setReviewsUserCredit();
		void setOneReviewUserCredit(Review* review);
		void addReviewToUser(Review* review, int user_id);
		User* findOneUser(int id);
		void addReviewToBook(Review* review, int book_id);
		void readFollowEdgesData(std::string);
		void readOneFollowEdgeData(std::vector<std::string> data);
		void addFollowersOfUser(std::vector<int> followers_of_user_id, User* user);
		void addFollowingsOfUser(std::vector<int> followings_of_user_id,User* user);
		std::vector<User*> findUsers(std::vector<int> user_id);
		void showAuthorInfo(int author_id);
		void showSortedShelf(int user_id, int shelf_type, std::string genre);
		void setBooksAuthorName();
		void showUserCredit(int user_id);
		void showBestBook();
		Book* getBestBook();
		bool compairBooksForBestBook(Book* book1, Book* book2);
		void showBestReviewer();
		User* getBestReviewer();
		bool compaireUsersForBestReviewer(User* user1, User* user2);
		void recommendFirstApproach(int user_id);
		bool compairBooksForFirstRecommend(Book* book1, Book* book2, User* user);
		double getTotalScore(Book* book , User* user);
		void recommendSecondApproach(int user_id);
};

int findSimilarString(std::vector<std::string> str_set, std::string str);


#endif
