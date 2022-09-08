//
// Created by user on 22. 9. 6.
//
#include "student_info.h"
#include <iostream>
#include <stdexcept>
#include "median.h"

static std::istream& read_hw (std::istream& in, std::vector<double>& homeworks)
{
    if(in) {
        homeworks.clear();

        double homework;
        while (in >> homework) {
            homeworks.push_back(homework);
        }

        in.clear();
    }
    return in;
}


std::istream& read(std::istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.finalterm;
    ::read_hw(in, s.homeworks);
    return in;
}


static double grade(double midterm, double finalterm, double homework)
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

static double grade(double midterm, double finalterm, const std::vector<double>& homeworks)
{
    if(homeworks.empty()) {
        throw std::domain_error("homework vector is empty");
    }
    double median = ::median(homeworks);
    double finalScore = ::grade(midterm, finalterm, median);
    return finalScore;
}

double grade(const Student_info& s)
{
    return ::grade(s.midterm, s.finalterm, s.homeworks);
}

bool Student_info::operator<(const Student_info &rhs) const
{
    return this->name < rhs.name;
}