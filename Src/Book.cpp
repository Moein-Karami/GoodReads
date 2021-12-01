#include "Book.hpp"

using namespace std;

Book::Book(int id_, string title_, int author_id_, string genre_)
{
	id=id_;
	title=title_;
	author_id=author_id_;
	genre=genre_;
	sum_of_rating=ZERO;
	reviews=EMPTY;
	author_name=BLANK;
}
Book::Book()
{
	id=ZERO;
	title=BLANK;
	author_id=ZERO;
	genre=BLANK;
	sum_of_rating=ZERO;
	reviews=EMPTY;
	author_name=BLANK;
}

int Book:: getId() { return id ; }

void Book::addReview(Review* review)
{
	reviews.push_back(review);
	sum_of_rating+=review->getRating();
}

void Book::printForAuthor()
{
	cout<<ID<<id<<" "<<TITLE<<title<<endl;
}

string Book::getGenre(){return genre;}

string Book::getTitle(){return title;}

void Book::showForUser()
{
	cout<<ID<<id<<endl;
	cout<<TITLE<<title<<endl;
	cout<<GENRE<<genre<<endl;
	cout<<AUTHOR<<author_name<<endl;
	cout<<SEPARATOR;
}

int Book::getAuthorId(){return author_id;}

void Book::setAuthorName( string author_name_)
{
	author_name=author_name_;
}

double Book::getAverageRating()
{
	return divide(sum_of_rating,(int)reviews.size());
}

void Book::showForBestBook()
{
	cout<<ID<<id<<endl;
	cout<<TITLE<<title<<endl;
	cout<<GENRE<<genre<<endl;
	cout<<AUTHOR<<author_name<<endl;
	cout<<AVERAGE_RATING<<fixed<<setprecision(TWO)<<getAverageRating()<<endl;
}

double Book::getScore()
{
	double sum_score=ZERO;
	for(int i=ZERO;i<reviews.size();i++)
		sum_score+=reviews[i]->getRating()*reviews[i]->getUserCredit();
	return divide(sum_score,(double)reviews.size());
}

void Book::showForBestRecommend()
{
	cout<<ID<<id<<endl;
	cout<<TITLE<<title<<endl;
	cout<<GENRE<<genre<<endl;
	cout<<AUTHOR<<author_name<<endl;
	cout<<REVIEWS<<endl;
	showReviewsForBestRecommend();
}

void Book::showReviewsForBestRecommend()
{
	sort(reviews.begin(),reviews.end(),compairReviewsById);
	for(int i=ZERO;i<reviews.size();i++)
		reviews[i]->showForBestRecommend();
}

bool compairReviewsById(Review* review1, Review* review2)
{
	return review1->getId()<review2->getId();
}