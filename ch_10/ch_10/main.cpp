#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<fstream>
using std::ifstream; using std::ofstream;
#include<string>
using std::string; using std::getline;

int main() {

	ifstream infile("in.txt");
	ofstream outfile("out.txt");

	string s;

	while (getline(infile, s)) {
		outfile << s << endl;
		cout << s << endl;
	}


	return 0;
}
