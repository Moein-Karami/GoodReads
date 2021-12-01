#include "GoodReads.hpp"

using namespace std;

GoodReads::GoodReads( string assets_directory )
{
	number_of_reviews_likes=ZERO;
	readAuthorsData(assets_directory+AUTHORS_DIRECTORY);
	readBooksData(assets_directory+BOOKS_DIRECTORY);
	readUsersData(assets_directory+USERS_DIRECTORY);
	readReviewsData(assets_directory+REVIEWS_DIRECTORY);
	readFollowEdgesData(assets_directory+FOLLOW_EDGES_DIRECTORY);
	setBooksAuthorName();
	setReviewsUserCredit();
}

void GoodReads::readAuthorsData(string path)
{
	vector<vector<string>> data=proccesFileInfo(path);
	for(int i=ZERO;i<data.size();i++)
		readOneAuthorData(data[i]);
}

void GoodReads::readOneAuthorData(vector<string> data)
{
	int id=stoi(data[ID_IN_AUTHORS_FILE]);
	string name=(data[NAME_IN_AUTHORS_FILE]);
	string gender=(data[GENDER_IN_AUTHORS_FILE]);
	Date member_since=Date(divideStrByChar(data[MEMBER_SINCE_IN_AUTHORS_FILE],SPACE));
	int year_of_birth=stoi(data[YEAR_OF_BIRTH_IN_AUTHORS_FILE]);
	string place_of_birth=data[PLACE_OF_BIRTH_IN_AUTHORS_FILE];
	vector<string> genres=divideStrByChar(data[GENRES_IN_AUTHORS_FILE],DOLLAR);

	authors.push_back(new Author(id,name,gender,member_since,year_of_birth,place_of_birth,genres));
}

void GoodReads::readBooksData(string path)
{
	vector<vector<string>> data=proccesFileInfo(path);
	for(int i=ZERO;i<data.size();i++)
		readOneBookData(data[i]);
}

void GoodReads::readOneBookData(vector<string> data)
{
	int id=stoi(data[ID_IN_BOOKS_FILE]);
	string title=data[TITLE_IN_BOOKS_FILE];
	int author_id=stoi(data[AUTHOR_ID_IN_BOOKS_FILE]);
	string genre=data[GENRE_IN_BOOKS_FILE];
	
	books.push_back(new Book(id,title,author_id,genre));
	addBookToAuthor(books.back(),author_id);
}

void GoodReads::addBookToAuthor(Book* book , int author_id)
{
	Author* author=findOneAuthor(author_id);
	author->addBook(book);
}

Author* GoodReads::findOneAuthor(int id)
{
	for(int i=ZERO;i<authors.size();i++)
		if(authors[i]->getId()==id)
			return authors[i];
}

void GoodReads::readUsersData(string path)
{
	vector<vector<string>> data=proccesFileInfo(path);
	for(int i=ZERO;i<data.size();i++)
		readOneUserData(data[i]);
}

void GoodReads::readOneUserData(vector<string> data)
{
	int id=stoi(data[ID_IN_USERS_FILE]);
	string name=data[NAME_IN_USERS_FILE];
	string place_of_birth=data[PLACE_OF_BIRTH_IN_USERS_FILE];
	Date member_since=Date(divideStrByChar(data[MEMBER_SINCE_IN_USERS_FILE],SPACE));
	vector<string> favorite_genres=divideStrByChar(data[FAVORITE_GENRES_IN_USERS_FILE],DOLLAR);
	vector<Author*> favorite_authors=findAuthors(data[FAVORITE_AUTHORS_IN_USERS_FILE]);
	vector<Book*> shelfs[NUMBER_OF_SHELFS];
	shelfs[READ]=findBooks(data[READ_IN_USERS_FILE]);
	shelfs[CURRENTLY_READING]=findBooks(data[CURRNTLY_READING_IN_USERS_FILE]);
	shelfs[WANT_TO_READ]=findBooks(data[WANT_TO_READ_IN_USERS_FILE]);
	users.push_back(new User(id,name,place_of_birth,member_since,favorite_genres,favorite_authors,shelfs));
}

vector<Book*> GoodReads::findBooks(string books_id_str)
{
	vector<int> books_id=convertOneStringToVectorOfInts(books_id_str,DOLLAR);
	vector<Book*> wanted_books;
	for(int i=ZERO;i<books_id.size();i++)
		wanted_books.push_back(findOneBook(books_id[i]));
	return wanted_books;
}

Book* GoodReads::findOneBook(int id)
{
	for(int i=ZERO;i<books.size();i++)
		if(books[i]->getId()==id)
			return books[i];
}

vector<Author*> GoodReads::findAuthors(string authors_id_str)
{
	vector<int> authors_id=convertOneStringToVectorOfInts(authors_id_str,DOLLAR);
	vector<Author*> wanted_authors;
	for(int i=ZERO;i<authors_id.size();i++)
		wanted_authors.push_back(findOneAuthor(authors_id[i]));
	return wanted_authors;
}

void GoodReads::readReviewsData(string path)
{
	vector<vector<string>> data=proccesFileInfo(path);
	for(int i=ZERO;i<data.size();i++)
		readOneReviewData(data[i]);
}

void GoodReads::readOneReviewData(vector<string> data)
{
	int id=stoi(data[ID_IN_REVIEWS_FILE]);
	int book_id=stoi(data[BOOK_ID_IN_REVIEWS_FILE]);
	int user_id=stoi(data[USER_ID_IN_REVIEWS_FILE]);
	int rating=stoi(data[RATING_IN_REVIEWS_FILE]);
	Date date(divideStrByChar(data[DATE_IN_REVIEWS_FILE],SPACE));
	int number_of_likes=stoi(data[NUMBER_OF_LIKES_IN_REVIEWS_FILE]);
	
	number_of_reviews_likes+=number_of_likes;
	reviews.push_back(new Review(id,book_id,user_id,rating,date,number_of_likes));
	addReviewToUser(reviews.back(),user_id);
	addReviewToBook(reviews.back(),book_id);
}

void GoodReads::setReviewsUserCredit()
{
	for(int i=ZERO;i<reviews.size();i++)
		setOneReviewUserCredit(reviews[i]);
}

void GoodReads::setOneReviewUserCredit(Review* review)
{
	User* user=findOneUser(review->getUserId());
	review->setUserCredit(user->getCredit(number_of_reviews_likes,reviews.size()));
}

void GoodReads::addReviewToUser(Review* review, int user_id)
{
	User* user=findOneUser(user_id);
	user->addReview(review);
}

User* GoodReads::findOneUser(int id)
{
	for(int i=ZERO;i<users.size();i++)
		if(users[i]->getId()==id)
			return users[i];
}

void GoodReads::addReviewToBook(Review* review, int book_id)
{
	Book* book=findOneBook(book_id);
	book->addReview(review);
}

void GoodReads::readFollowEdgesData(string path)
{
	vector<vector<string>> data=proccesFileInfo(path);
	for(int i=ZERO;i<data.size();i++)
		readOneFollowEdgeData(data[i]);
}

void GoodReads::readOneFollowEdgeData(vector<string> data)
{
	int user_id=stoi(data[ID_IN_FOLLOW_EDGES_FILE]);
	User* user=findOneUser(user_id);
	vector<int> followings_of_user_id=convertOneStringToVectorOfInts(data[FOLLOWING_IN_FOLLOW_EDGES_FILE],DOLLAR);
	vector<int> followers_of_user_id=convertOneStringToVectorOfInts(data[FOLLOWERS_IN_FOLLOW_EDGES_FILE],DOLLAR);
	addFollowingsOfUser(followings_of_user_id,user);
	addFollowersOfUser(followers_of_user_id,user);
}

void GoodReads::addFollowersOfUser(vector<int> followers_of_user_id, User* user)
{
	vector<User*> followers_of_user=findUsers(followers_of_user_id);
	for(int i=ZERO;i<followers_of_user.size();i++)
		user->addFollowerUser(followers_of_user[i]);
}

void GoodReads::addFollowingsOfUser(vector<int> followings_of_user_id,User* user)
{
	vector<User*> followings_of_user=findUsers(followings_of_user_id);
	for(int i=ZERO;i<followings_of_user.size();i++)
		user->addFollowingUser(followings_of_user[i]);
}

vector<User*> GoodReads::findUsers(vector<int> users_id)
{
	vector<User*> wanted_users;
	for(int i=ZERO;i<users_id.size();i++)
	{
		User* wanted_user=findOneUser(users_id[i]);
		wanted_users.push_back(wanted_user);
	}
	return wanted_users;
}

void GoodReads::showAuthorInfo(int author_id)
{
	Author* author=findOneAuthor(author_id);
	author->showInfo();
}

void GoodReads::showSortedShelf(int user_id, int shelf_type, string genre)
{
	User* user=findOneUser(user_id);
	user->showSortedShelf(shelf_type,genre);
}

void GoodReads::setBooksAuthorName()
{
	for(int i=ZERO;i<books.size();i++)
	{
		Author* author=findOneAuthor(books[i]->getAuthorId());
		books[i]->setAuthorName(author->getName());
	}
}

void GoodReads::showUserCredit(int user_id)
{
	User* user=findOneUser(user_id);
	cout<<fixed<<setprecision(SIX)<<user->getCredit(number_of_reviews_likes,reviews.size())<<endl;
}

void GoodReads::showBestBook()
{
	Book* best_book=getBestBook();
	best_book->showForBestBook();
}

Book* GoodReads::getBestBook()
{
	Book* best_book=books[ZERO];
	for(int i=ONE;i<books.size();i++)
		if(compairBooksForBestBook(books[i],best_book))
			best_book=books[i];
	return best_book;
}

bool GoodReads::compairBooksForBestBook(Book* book1, Book* book2)
{
	if(book1->getAverageRating()!=book2->getAverageRating())
		return book1->getAverageRating()>book2->getAverageRating();
	return book1->getId()<book2->getId();
}

void GoodReads::showBestReviewer()
{
	User* best_reviewer=getBestReviewer();
	best_reviewer->showForBestReviewer();
}

User* GoodReads::getBestReviewer()
{
	User* best_reviewer=users[ZERO];
	for(int i=ONE;i<users.size();i++)
		if(compaireUsersForBestReviewer(users[i],best_reviewer))
			best_reviewer=users[i];
	return best_reviewer;
}

bool GoodReads::compaireUsersForBestReviewer(User* user1, User* user2)
{
	if(user1->getNumberOfReviewsLikes()!=user2->getNumberOfReviewsLikes())
		return user1->getNumberOfReviewsLikes()>user2->getNumberOfReviewsLikes();
	return user1->getId()<user2->getId();
}

void GoodReads::recommendFirstApproach(int user_id)
{
	User* user=findOneUser(user_id);
	Book* best_book=books[ZERO];
	for(int i=ONE;i<books.size();i++)
	{
		if(compairBooksForFirstRecommend(books[i],best_book,user))
			best_book=books[i];
	}
	best_book->showForBestRecommend();
}

bool GoodReads::compairBooksForFirstRecommend(Book* book1, Book* book2, User* user)
{
	double book1_score=getTotalScore(book1, user),book2_score=getTotalScore(book2, user);
	if(book1_score !=book2_score)
		return book1_score>book2_score;
	return book1->getId()<book2->getId();
}

double GoodReads::getTotalScore(Book* book , User* user)
{
	double book_score=book->getScore();
	book_score+=findSimilarString(user->getFavoriteGenres(), book->getGenre());
	return book_score;
}

int findSimilarString(vector<string> str_set, string str)
{
	for(int i=ZERO;i<str_set.size();i++)
		if(str_set[i]==str)
			return FIVE;
	return ZERO;
}

void GoodReads::recommendSecondApproach(int user_id)
{
	User* user=findOneUser(user_id);
	Book* recommended_book=user->getRecommendSecondApproach();
	recommended_book->showForBestRecommend();
}
