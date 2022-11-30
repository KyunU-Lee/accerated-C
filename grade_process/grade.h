#ifndef GUARD_grade_h
#define GUARD_grade_h
#include "Student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, std::vector<double>& hw);
double grade(const Student_info& s);
bool fgrade(const Student_info& s);
//std::vector<Student_info> extract_fail(std::vector<Student_info>& students);


#endif // !GUARD_grade_h
