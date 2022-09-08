#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "student_info.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::domain_error;

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}

int main()
{
    vector<Student_info> students;
    string::size_type maxLen = 0;

    Student_info student;
    while(read(cin, student)) {
        students.push_back(student);

        maxLen = std::max(maxLen, student.name.size());
    }

    std::sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

        try {
            double finalScore = ::grade(students[i]);

            string::size_type pad = maxLen - students[i].name.size() + 1;
            std::streamsize prec = cout.precision();
            cout << students[i].name << string(pad, ' ')<< std::setprecision(3) << " : "
            << finalScore << std::setprecision(prec) << endl;
        } catch (domain_error &e) {
            std::cerr << e.what() << endl;
            return 1;
        }
    }
    return 0;
}
