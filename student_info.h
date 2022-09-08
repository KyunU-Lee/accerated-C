//
// Created by user on 22. 9. 6.
//

#ifndef SCORE4_STUDENT_INFO_H
#define SCORE4_STUDENT_INFO_H
#include <string>
#include <vector>


struct Student_info {
    std::string name;
    double midterm;
    double finalterm;
    std::vector<double> homeworks;

    bool operator < (const Student_info& rhs) const;
//    bool operator > (const Student_info& rhs) const;
};

double grade(const Student_info& s);
std::istream& read(std::istream& in, Student_info& s);

#endif //SCORE4_STUDENT_INFO_H
