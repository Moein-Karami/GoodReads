#ifndef _Review_
#define _Review_

#include "ImportantLibraries.hpp"
#include "GeneralFunctions.hpp"
#include "Date.hpp"
#include "WritingDefines.hpp"
class Review
{
	private :
		int id;
		int book_id;
		int user_id;
		int rating;
		Date date;
		int number_of_likes;
		double user_credit;
	public :
		Review(int id_,int book_id_,int user_id_,int rating_,Date date_, int number_of_likes_);
		Review();
		int getNumberOfLikes();
		int getRating();
		void setUserCredit(double user_credit_);
		double getUserCredit();
		void showForBestRecommend();
		int getId();
		int getUserId();
};



#endif
