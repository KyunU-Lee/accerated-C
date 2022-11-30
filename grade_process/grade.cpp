#include"grade.h"
#include"median.h"
#include<list>
using std::list; using std::vector;
using std::domain_error;
#include<algorithm>
using std::remove_copy_if; using std::back_inserter;
using std::remove_if; using std::stable_partition;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}

vector<Student_info> extract_fail(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter
		= stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());
	
	return fail;
}

