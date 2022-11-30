#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;
#include<algorithm>
using std::getline;
#include<vector>
using std::vector;
#include"findurl.h"

int main() {
	
	string s;

	while (getline(cin, s)) {
		vector<string> v = find_urls(s);
		for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) {
			cout << *i << endl;
		}
	}
	return 0;
}