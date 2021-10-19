#include <set>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	int n;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	set<pair<long long, long long>>segments;
	long long l, r;
	for(int i=0; i<n; i++){
		getline(cin, s);
		s_str.str(s);
		s_str.clear();
		s_str>>l;
		s_str>>r;
		segments.insert({l, r});
	}

	long long dl=0;
	l = segments.begin()->first;
	r = segments.begin()->second;
	for(auto it = segments.begin(); it != segments.end(); it++){

		if(it->first > r){
			dl += (r-l);
			l = it->first;
			r = it->second;
		}else if(it->second > r){
			r = it->second;
		}

	}
	dl += (r-l);
	cout<<dl;

	return 0;
}
