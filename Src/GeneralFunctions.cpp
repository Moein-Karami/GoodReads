#include "GeneralFunctions.hpp"

using namespace std;

vector<string> divideStrByChar(string str,char divider)
{
	vector<string> divided_str;
	if(str.size()==ZERO)
		return divided_str;
	str+=divider;
	for(int i=ZERO ; i<str.size();i++)
	{
		string word;
		while(str[i]!=divider)
		{
			word+=str[i];
			i++;
		}
		divided_str.push_back(word);
	}
	return divided_str;
}

vector<int> convertStringsToInts(vector<string> strs)
{
	vector<int> ints;
	for(int i=ZERO;i<strs.size();i++)
		ints.push_back(stoi(strs[i]));
	return ints;
}

vector<int> convertOneStringToVectorOfInts(string str,char divider)
{
	vector<string> tmp=divideStrByChar(str,divider);
	return convertStringsToInts(tmp);
}

vector<vector<string>> proccesFileInfo(string path)
{
	ifstream input;
	input.open(path);
	string line;
	getline(input,line);
	vector<vector<string>> data;
	while(getline(input,line))
		data.push_back(divideStrByChar(line,COMMA));
	return data;
}

double divide(double a,double b)
{
	if(b==ZERO)
		return ZERO;
	return a/b;
}