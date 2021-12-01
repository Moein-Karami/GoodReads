#ifndef _Book_
#define _Book_

#include "ImportantLibraries.hpp"
#include "GeneralFunctions.hpp"
#include "Review.hpp"
#include "WritingDefines.hpp"

#define WANT_TO_READ 2
#define CURRNETLY_READING 1
#define READ 0

class Book 
{
	private :
		int id;
		std:: string title;
		int author_id;
		std::string author_name;
		std::string genre;
		std::vector < Review* > reviews;
		int sum_of_rating;
	public:
		Book(int id_, std::string title_, int author_id_, std::string genre_);
		Book();
		int getId();
		void addReview(Review* review);
		void printForAuthor();
		std::string getGenre();
		std::string getTitle();
		void showForUser();
		int getAuthorId();
		void setAuthorName(std:: string author_name_);
		double getAverageRating();
		void showForBestBook();
		double getScore();
		void showForBestRecommend();
		void showReviewsForBestRecommend();
};
bool compairReviewsById(Review* review1, Review* review2);

#endif

