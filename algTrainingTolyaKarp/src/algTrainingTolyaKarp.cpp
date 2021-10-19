
#include <iostream>
#include <sstream>
#include <set>
#include <limits>

using namespace std;

int main() {

	int n;
	set<pair<long long, long long>>sums;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	long long a;
	long long d;
	for(int i=0; i<n; i++){
		getline(cin, s);
		istringstream s_str_2(s);
		s_str_2>>d;
		s_str_2>>a;

		auto it = sums.lower_bound({d, numeric_limits<long long>::min()});
		if(it != sums.end() && it->first == d){
			a += it->second;
			sums.erase(it);
		}

		sums.insert({d, a});

	}

	for(auto it = sums.begin(); it != sums.end(); it++){
		cout<<it->first<<" "<<it->second<<"\n";
	}

	return 0;
}
