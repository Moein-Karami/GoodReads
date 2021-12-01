#include "Review.hpp"

using namespace std;


Review::Review(int id_=ZERO ,int book_id_=ZERO ,int user_id_=ZERO ,int rating_=ZERO ,Date date_=Date(), int number_of_likes_=ZERO)
{
	id=id_;
	book_id = book_id_ ;
	user_id = user_id_;
	rating=rating_;
	date=date_;
 	number_of_likes=number_of_likes_;     
 	user_credit=ZERO; 
}

Review::Review()
{
	id=ZERO;
	book_id = ZERO ;
	user_id = ZERO;
	rating=ZERO;
	date=Date();
 	number_of_likes=ZERO;
 	user_credit=ZERO;
}

int Review::getNumberOfLikes() { return number_of_likes; }

int Review::getRating() { return rating; }

void Review::setUserCredit(double user_credit_)
{
	user_credit=user_credit_;
}

double Review::getUserCredit(){return user_credit;}

void Review::showForBestRecommend()
{
	cout<<ID<<id<<SPACE<<RATING<<rating<<SPACE<<LIKES<<number_of_likes<<SPACE<<DATE;
	date.print();
	cout<<endl;
}

int Review::getId(){return id;}

int Review::getUserId(){return user_id;}