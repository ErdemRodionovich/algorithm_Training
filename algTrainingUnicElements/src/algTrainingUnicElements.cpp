#include <iostream>
#include <tuple>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main() {

	set<tuple<int, int, int>>d;
	set<pair<int, int>>unic;
	int x;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	int i=0;
	int xx, cc, ii;
	while(s_str >> x){

		auto it = d.upper_bound(make_tuple(x, -1, i));
		if(it == d.end()){
			d.insert(make_tuple(x, 1, i));
		}else{
			tie(xx, cc, ii) = *it;
			if(xx == x){
				d.erase(it);
				d.insert(make_tuple(x, cc+1, ii));
			}else{
				d.insert(make_tuple(x, 1, i));
			}
		}

		i++;
	}


	for(auto it = d.begin(); it != d.end(); it++){

		tie(xx, cc, ii) = *it;
		if(cc == 1){
			unic.insert(make_pair(ii, xx));
		}

	}

	for(auto it = unic.begin(); it != unic.end(); it++){
		tie(ii, xx) = *it;
		cout<<xx<<' ';
	}

	return 0;
}
