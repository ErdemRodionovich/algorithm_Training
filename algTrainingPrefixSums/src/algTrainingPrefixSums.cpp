#include <iostream>
#include <sstream>
using namespace std;

int main() {

	int n, q;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	s_str>>q;
	long long sums[n+1];
	getline(cin, s);
	istringstream s_2(s);
	long long curSum = 0, d=0;
	sums[0] = 0;
	for(int i=0; i<n; i++){
		sums[i] = curSum;
		s_2>>d;
		curSum += d;
	}
	sums[n] = curSum;

	int l, r;
	for(int i=0; i<q; i++){
		getline(cin, s);
		istringstream s_3(s);
		s_3>>l;
		s_3>>r;
		l--;
		cout<<(sums[r] - sums[l])<<"\n";
	}

	return 0;
}
