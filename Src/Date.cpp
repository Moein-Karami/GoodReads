#include "Date.hpp"

using namespace std;

Date::Date(vector<string> vec_date)
{
	month=vec_date[MONTH_IN_DATE];
	day=stoi(vec_date[DAY_IN_DATE]);
	year=stoi(vec_date[YEAR_IN_DATE]);
}

Date::Date()
{
	month=BLANK;
	day=ZERO;
	year=ZERO;
}

void Date::print()
{
	cout<<month<<" "<<day<<" "<<year;
}
