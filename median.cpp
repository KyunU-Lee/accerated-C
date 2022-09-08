//
// Created by user on 22. 9. 6.
//
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.h"
using std::vector;
using std::domain_error;

double median(const vector<double>& v)
{
    if(v.empty() ){
        throw domain_error("vector is empty");
    }
    vector<double> vec = v;
    std::sort(vec.begin(), vec.end());

    vector<double>::size_type n = vec.size();
    double median = (n % 2) ? vec[n/2] : (vec[n/2] + vec[n/2 - 1]) / 2;
    return median;
}



