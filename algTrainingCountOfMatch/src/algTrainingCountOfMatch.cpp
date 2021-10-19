#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {

	set<int> d;
	int count = 0;

	string s;
	getline(cin, s);
	istringstream s_str(s);
	int x;
	while(s_str >> x){
		d.insert(x);
	}

	getline(cin, s);
	istringstream s2_str(s);

	while(s2_str >> x){
		if(d.count(x) > 0){
			count++;
		}
	}

	cout<<count;

	return 0;
}
