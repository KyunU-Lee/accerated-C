#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h
#include<string>
#include<vector>
#include<iostream>

class Student_info {
public:

	Student_info();
	Student_info(std::istream&);

	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }

	std::istream& read(std::istream&);
	
	double grade() const;
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;

};

bool compare(const Student_info& x, const Student_info& y);

#endif