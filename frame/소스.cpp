#include<iostream>
#include<vector>
#include<string>
#include"split.h"
#include"frame.h"
using namespace std;
using std::getline;

int main()
{
	vector<string> p;
	p.push_back("this is an");
	p.push_back("example");
	p.push_back("to");
	p.push_back("illustrate");
	p.push_back("framing");

	ostream_iterator<string>ofile(cout, "\n");
	copy(p.begin(), p.end(), ofile);
	cout << endl;

	vector<string> f = frame(p);
	copy(f.begin(), f.end(), ofile);
	cout << endl;

	vector<string> v = vcat(p, f);
	copy(v.begin(), v.end(), ofile);
	cout << endl;

	vector<string> h = hcat(f, p);
	copy(h.begin(), h.end(), ofile);
	cout << endl;
	
	string s;
		while (getline(cin, s)) {
			vector<string> v = split(s);

			for (vector<string>::size_type i = 0; i != v.size(); ++i) {
				cout << v[i] << endl;
			}
		}

	return 0;
}
