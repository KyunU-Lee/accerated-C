#include"analysis.h"
#include"grade.h"
#include"median.h"
#include"Student_info.h"
using std::vector; using std::ostream; using std::endl;
using std::domain_error; using std::string; using std::back_inserter;
#include<algorithm>
using std::transform; using std::remove_copy;
#include<numeric>
using std::accumulate;

double grade_aux(const Student_info& s)
{
	try
	{
		return grade(s);
	}
	catch (domain_error)
	{
		return grade(s.midterm, s.final, 0);
	}

}

double median_anaysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did,
	const vector < Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did)
		<< ", median(didnt) = " << analysis(didnt) << endl;
}

double average(const std::vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}
double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));

}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

