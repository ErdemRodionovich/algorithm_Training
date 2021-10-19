#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

	string s;
	getline(cin, s);
	istringstream s_str(s);

	long double a, k, b, m, x, l, r, c;

	s_str>>a;
	s_str>>k;
	s_str>>b;
	s_str>>m;
	s_str>>x;

	long double n = (x*k*m)/(a*(k*m-m)+b*(k*m-k));
	cout.precision(20);

	r = floor(n+10);
	l = 0;

	long double sum;
	while(l < r){

		c = floor((r+l)/2.0);
		sum = a*(c-floor(c/k))+b*(c-floor(c/m));
		if(sum >= x){
			r = c;
		}else{
			l = c + 1;
		}

		//cout<<c<<" sum="<<sum<<" l="<<l<<" r="<<r<<"\n";

	}
	cout<<l;

	return 0;
}
