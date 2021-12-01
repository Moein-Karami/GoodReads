#include "ImportantLibraries.hpp"
#include "ReadingDefines.hpp"
#include "GoodReads.hpp"
#include "WritingDefines.hpp"

using namespace std;

void showAuthorInfo(GoodReads& goodreads)
{
	int author_id;
	cin>>author_id;
	goodreads.showAuthorInfo(author_id);
}

string getGenre()
{
	string genre;
	char tmp;
	getchar();
	while(tmp=getchar())
	{
		if(tmp==ENTER)
			break;
		genre+=tmp;
	}
	return genre;
}

void showSortedShelf(GoodReads& goodreads)
{ 
	map<string,int> mp={{READ_STR,READ},{CURRENTLY_READING_STR,CURRENTLY_READING},
	{WANT_TO_READ_STR,WANT_TO_READ}};
	int user_id;
	string shelf_type,genre;
	cin>>user_id>>shelf_type;
	genre=getGenre();
	goodreads.showSortedShelf(user_id,mp[shelf_type],genre);	
}

void credit(GoodReads& goodreads)
{
	int user_id;
	cin>>user_id;
	goodreads.showUserCredit(user_id);
}

void recommendFirstApproach(GoodReads& goodreads)
{
	int user_id;
	cin>>user_id;
	goodreads.recommendFirstApproach(user_id);
}

void recommendSecondApproach(GoodReads& goodreads)
{
	int user_id;
	cin>>user_id;
	goodreads.recommendSecondApproach(user_id);
}

void getOrders(GoodReads& goodreads)
{
	string s;
	while(cin>>s)
	{
		if(s==SHOW_AUTHOR_INFO)
			showAuthorInfo(goodreads);
		else if(s==SHOW_SORTED_SHELF)
			showSortedShelf(goodreads);
		else if(s==CREDIT)
			credit(goodreads);
		else if(s==BEST_BOOK)
			goodreads.showBestBook();
		else if(s==BEST_REVIEWER)
			goodreads.showBestReviewer();
		else if(s==RECOMMEND_FIRST_APPROACH)
			recommendFirstApproach(goodreads);
		else if(s==RECOMMEND_SECOND_APPROACH)
			recommendSecondApproach(goodreads);
	}
}

int main ( int argc, char* argv[] )
{
	string assets_directory(argv[ONE]);
	GoodReads goodreads(assets_directory);
	getOrders(goodreads);
	return 0;
}
