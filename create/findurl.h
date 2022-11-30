#ifndef GUARD_findurl_h
#define GUARD_findurl_h
#include<vector>
#include<string>

std::vector<std::string> find_urls(const std::string&);
std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e);
std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e);
bool not_url_char(char c);

#endif // !GUARD_findurl_h
