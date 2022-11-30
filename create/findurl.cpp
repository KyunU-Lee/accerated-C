#include"findurl.h"
using std::vector; using std::string;
#include<algorithm>
using std::search;
using std::find_if;
#include<cctype>
using std::isalnum;
using std::isalpha;

vector<string> find_urls(const string& s) 
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while (b != e)
	{
		b = url_beg(b, e);
		if (b != e) {
			iter after = url_end(b, e);
			
			ret.push_back(string(b, after));

			b = after;	
		}
	}
	return ret;
}

string::const_iterator url_beg(const string::const_iterator b, const string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;

	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e){
		if (i != b && i + sep.size() != e) {
			iter beg = i;

			while (beg != b && isalpha(beg[-1]))
				--beg;

			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		i += sep.size();
	}
	return e;
}

string::const_iterator url_end(const string::const_iterator b, const string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}