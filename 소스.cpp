#include<iostream>
using std::cout; using std::endl; using std::cin; using std::istream;
#include<string>
using std::string;
#include<map>
using std::map;
#include<vector>
using std::vector;
#include"split.h"
using std::getline;


map<string, vector<int> > xref(istream& in,
	vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int>> ret;

	while (getline(in, line)){
		++line_number;

		vector<string> words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);

	}
	return ret;
}	

int main()
{
	string s;

	map<string, int> counters;

	while (cin >> s)
		++counters[s];

	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}

	return 0;
}