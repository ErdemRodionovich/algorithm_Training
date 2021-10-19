#include <sstream>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {

	int n, m;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	s_str>>m;
	multiset<int>cats;
	getline(cin, s);
	s_str.str(s);
	s_str.clear();
	int d;
	for(int i=0; i<n; i++){
		s_str>>d;
		cats.insert(d);
	}
	map<int, int>sums;
	int p = 0, prev = -1;
	sums[0] = p;
	for(auto it=cats.begin(); it != cats.end(); it++){
		if(prev != (*it)){
			sums[(*it)] = p;
			prev = (*it);
		}
		p++;
	}
	auto pe = cats.end();
	pe--;
	sums[(*pe)+1] = p;
	int l, r;
	for(int i=0; i<m; i++){
		getline(cin, s);
		s_str.str(s);
		s_str.clear();
		s_str>>l;
		s_str>>r;

		auto it = sums.lower_bound(l);
		auto pr = sums.lower_bound(r+1);

		if(it == sums.end()){
			it--;
		}
		if(pr == sums.end()){
			pr--;
		}
		cout<<(pr->second - it->second)<<"\n";

	}

	return 0;
}
