#ifndef _Date_
#define _Date_

#include "ImportantLibraries.hpp"
#include "GeneralFunctions.hpp"
#include "WritingDefines.hpp"
#define MONTH_IN_DATE 0
#define DAY_IN_DATE 1
#define YEAR_IN_DATE 2


class Date
{
	private :
		std::string month;
		int day;
		int year;
	public:
		Date(std::vector<std::string> vec_date);
		Date();	
		void print();
};

#endif
