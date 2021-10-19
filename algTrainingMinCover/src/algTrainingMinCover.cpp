#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {

	int m;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>m;
	int l, r;
	bool haveSegment = true;
	set<pair<int, int>> segments;
	while(haveSegment){
		getline(cin, s);
		s_str.str(s);
		s_str.clear();
		s_str>>l;
		s_str>>r;
		if(l == 0 && r == 0){
			haveSegment = false;
		}else{
			segments.insert({l, r});
		}
	}

	l=0;r=0;
	haveSegment = true;
	auto it = segments.begin();
	int rMax=r, nl=0;
	set<pair<int, int>> solution;

	while(haveSegment){

		rMax = r;
		for(auto ptr = it; ptr != segments.end() && ptr->first <= r; ptr++){
			if(ptr->second > rMax){
				rMax = ptr->second;
				nl = ptr->first;
				it = ptr;
			}
		}

		if(rMax > r){
			solution.insert({nl, rMax});
			r = rMax;
			if(r >= m){
				haveSegment = false;
			}
		}else{
			haveSegment = false;
		}

	}

	if(rMax >= m && solution.size() > 0){
		cout<<solution.size()<<"\n";
		for(it = solution.begin(); it != solution.end(); it++){
			cout<<it->first<<" "<<it->second<<"\n";
		}
	}else{
		cout<<"No solution";
	}

	return 0;
}
