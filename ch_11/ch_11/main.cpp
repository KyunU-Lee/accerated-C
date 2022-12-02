#include<iostream>
#include"vec.h"
using std::cout; using std::endl;
#include<string>
using std::string;

int main() {

	Vec<string> i;

	i.push_back("do not");
	i.push_back("gentle the");
	i.push_back("good night");
	i.push_back(" ");

	Vec<string>::iterator iter;
	for(iter = i.begin();iter != i.end(); iter++)
	{
		cout << *iter << endl;
	}



	return 0;
}