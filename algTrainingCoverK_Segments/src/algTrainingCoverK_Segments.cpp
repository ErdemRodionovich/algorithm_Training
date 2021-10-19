#include <set>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	long long n, k, l;
	set<long long>points;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	getline(fin, s);
	istringstream s_str(s);
	s_str>>n;
	s_str>>k;
	getline(fin, s);
	s_str.str(s);
	s_str.clear();
	long long d;
	for(int i=0; i<n; i++){
		s_str>>d;
		points.insert(d);
	}

	l=1;
	auto it = points.end();
	it--;
	long long r = (*it) - (*points.begin());
	long long c, t, b;
	while(l < r){

		c = (r+l)/2;
		b=0;
		it = points.begin();
		t=(*it);
		while(it != points.end()){

			b++;
			t = (*it) + c + 1;
			it = points.lower_bound(t);

		}

		if(b <= k){
			r = c;
		}else{
			l = c + 1;
		}

	}
	if(l == 1 && b != k){
		fout<<"0";
	}else{
		fout<<l;
	}

	return 0;
}
