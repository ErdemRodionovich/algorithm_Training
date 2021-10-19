#include <sstream>
#include <iostream>

using namespace std;

int main() {

	long double a,b,c,d,x,sum, e=0.0000000000000001f;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>a;
	s_str>>b;
	s_str>>c;
	s_str>>d;
	long double l=-1000000.0f, r=2000000.0f;
	cout.precision(10);
	bool right = false;
	x=r;
	sum = a*x*x*x + b*x*x + c*x + d;
	x=l;
	x = a*x*x*x + b*x*x + c*x + d;
	if(sum > x){
		right = true;
	}
	while(r-l > e){

		x = (r-l)/2.0 + l;
		sum = a*x*x*x + b*x*x + c*x + d;
		if(sum > e && right || sum < e && !right){
			r = x;
		}else{
			l = x+e;
		}

		//cout<<x<<" sum="<<sum<<"\n";

	}

	cout<<x;

	return 0;
}
