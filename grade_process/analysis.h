#ifndef GUARD_analysis_h
#define GUARD_analysis_h
#include"Student_info.h"


double grade_aux(const Student_info& s);
double median_anaysis(const std::vector<Student_info>& students);
void write_analysis(std::ostream& out, const std::string& name,
	double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>& did,
	const std::vector < Student_info>& didnt);

double average(const std::vector<double>&);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info&);
double optimistic_median_analysis(const std::vector<Student_info>&);

#endif // !GUARD_write_h
