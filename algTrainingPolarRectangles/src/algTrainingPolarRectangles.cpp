#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <tuple>

using namespace std;

int main() {

	int n;
	string s;
	getline(cin, s);
	double rb1=0, rb2=0;
	double r1, r2, f1, f2;
	double pi = 3.14159265359;
	set<tuple<long long, int, int>>rays;
	bool beginSetted=false;
	istringstream s_str(s);
	s_str>>n;
	long long koef = 10000000000;
	for(int i=0; i<n; i++){

		getline(cin, s);
		s_str.str(s);
		s_str.clear();
		s_str>>r1;
		s_str>>r2;
		s_str>>f1;
		s_str>>f2;

		rays.insert({f1*koef, 1, i});
		rays.insert({f2*koef, -1, i});

		if(!beginSetted){
			rb1 = r1;
			rb2 = r2;
			beginSetted = true;
		}
		if(r1 > rb1){
			rb1 = r1;
		}
		if(r2 < rb2){
			rb2 = r2;
		}

	}

	cout<<fixed<<setprecision(10)<<setfill('0')<<left;

	if(rb1 < rb2){

		int index, type;
		set<int>openedSegments;
		for(auto it = rays.begin(); it!=rays.end(); it++){

			type = get<1>(*it);
			index = get<2>(*it);
			if(type == 1){
				openedSegments.insert(index);
			}else if(openedSegments.find(index) != openedSegments.end()){
				openedSegments.erase(index);
			}

		}

		double sq = 0;
		double r_sq = (rb2*rb2 - rb1*rb1);
		long long curAngle=0;
		for(auto it = rays.begin(); it != rays.end(); it++){

			type = get<1>(*it);
			index = get<2>(*it);
			if(type == 1){
				openedSegments.insert(index);
				curAngle = get<0>(*it);
			}else{
				if(openedSegments.size() == n){
					double ang = ((double)(get<0>(*it) - curAngle))/koef;
					sq += (ang/2)*r_sq;
				}
				openedSegments.erase(index);
			}

		}

		if(openedSegments.size() == n){
			double ang = 2*pi - ((double)curAngle)/koef;
			sq += (ang/2)*r_sq;
		}

		cout<<sq;

	}
	else{
		cout<<0.0;
	}

	return 0;
}
