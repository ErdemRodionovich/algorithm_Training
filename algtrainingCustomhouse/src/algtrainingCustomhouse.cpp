#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {

	int n;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	int t, l;
	set<pair<int, int>>events;
	for(int i=0; i<n; i++){
		getline(cin, s);
		s_str.str(s);
		s_str.clear();

		s_str>>t;
		auto it = events.lower_bound({t, -n});
		if(it == events.end() || it->first != t){
			events.insert({t, 1});
		}else{
			events.erase({t, it->second});
			events.insert({t, it->second + 1});
		}

		s_str>>l;
		t += l;
		it = events.lower_bound({t, -n});
		if(it == events.end() || it->first != t){
			events.insert({t, -1});
		}else{
			events.erase({t, it->second});
			events.insert({t, it->second - 1});
		}
	}

	t=0; l=0;
	for(auto it = events.begin(); it != events.end(); it++){
		t += it->second;
		if(t > l){
			l = t;
		}
	}

	cout<<l;

	return 0;
}
