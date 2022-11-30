#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h
#include<string>
#include<vector>
#include<iostream>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& is, Student_info& s);
bool compare(const Student_info& x, const Student_info& y);
bool did_all_hw(const Student_info&);


#endif // !GUARD_Student_info_h
