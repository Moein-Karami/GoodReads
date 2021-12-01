#ifndef _ReadinfDefines_
#define _ReadingDefines_

#define AUTHORS_DIRECTORY "/authors.csv"
#define BOOKS_DIRECTORY "/books.csv"
#define FOLLOW_EDGES_DIRECTORY "/follow_edges.csv"
#define REVIEWS_DIRECTORY "/reviews.csv"
#define USERS_DIRECTORY "/users.csv"
#define ONE 1

#define ID_IN_AUTHORS_FILE 0
#define NAME_IN_AUTHORS_FILE 1
#define GENDER_IN_AUTHORS_FILE 2
#define MEMBER_SINCE_IN_AUTHORS_FILE 3
#define YEAR_OF_BIRTH_IN_AUTHORS_FILE 4
#define PLACE_OF_BIRTH_IN_AUTHORS_FILE 5
#define GENRES_IN_AUTHORS_FILE 6

#define ID_IN_BOOKS_FILE 0
#define TITLE_IN_BOOKS_FILE 1
#define AUTHOR_ID_IN_BOOKS_FILE 2
#define GENRE_IN_BOOKS_FILE 3

#define ID_IN_REVIEWS_FILE 0
#define BOOK_ID_IN_REVIEWS_FILE 1
#define USER_ID_IN_REVIEWS_FILE 2
#define RATING_IN_REVIEWS_FILE 3
#define DATE_IN_REVIEWS_FILE 4
#define NUMBER_OF_LIKES_IN_REVIEWS_FILE 5

#define ID_IN_USERS_FILE 0
#define NAME_IN_USERS_FILE 1
#define PLACE_OF_BIRTH_IN_USERS_FILE 2
#define MEMBER_SINCE_IN_USERS_FILE 3
#define FAVORITE_AUTHORS_IN_USERS_FILE 4
#define FAVORITE_GENRES_IN_USERS_FILE 5
#define WANT_TO_READ_IN_USERS_FILE 6
#define CURRNTLY_READING_IN_USERS_FILE 7
#define READ_IN_USERS_FILE 8

#define ID_IN_FOLLOW_EDGES_FILE 0
#define FOLLOWING_IN_FOLLOW_EDGES_FILE 1
#define FOLLOWERS_IN_FOLLOW_EDGES_FILE 2

#define SHOW_AUTHOR_INFO "show_author_info"
#define SHOW_SORTED_SHELF "show_sorted_shelf"
#define CREDIT "credit"
#define BEST_BOOK "best_book"
#define BEST_REVIEWER "best_reviewer"
#define RECOMMEND_FIRST_APPROACH "recommend_first_approach"
#define RECOMMEND_SECOND_APPROACH "recommend_second_approach"

#define READ_STR "read"
#define WANT_TO_READ_STR "want_to_read"
#define CURRENTLY_READING_STR "currently_reading"

#endif
