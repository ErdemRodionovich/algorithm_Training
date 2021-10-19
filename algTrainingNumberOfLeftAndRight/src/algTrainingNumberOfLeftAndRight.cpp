#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	int n;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	getline(fin, s);
	istringstream s_str(s);
	s_str>>n;
	int nums[n+1];
	getline(fin, s);
	s_str.str(s);
	s_str.clear();
	nums[0]=0;
	for(int i=1; i<=n; i++){
		s_str>>nums[i];
	}
	int m;
	getline(fin, s);
	s_str.str(s);
	s_str.clear();
	s_str>>m;
	getline(fin, s);
	s_str.str(s);
	s_str.clear();
	int d, l, r, c, rb;
	for(int i=0; i<m; i++){

		s_str>>d;
		l=1;
		r=n;

		while(l<r){
			c = (r-l)/2 + l;
			if(nums[c] > d){
				r = c;
			}else{
				l = c+1;
			}
		}

		if(nums[l] == d){
			rb = l;
		}else{
			rb = l-1;
		}

		if(rb > 0 && nums[rb] == d){

			l = 1;
			r = rb;
			while(l<r){
				c = (r-l)/2 + l;
				if(nums[c] >= d){
					r = c;
				}else{
					l = c+1;
				}
			}

			if(nums[l] == d){
				fout<<l<<" "<<rb<<"\n";
			}else{
				fout<<"0 0\n";
			}

		}else{
			fout<<"0 0\n";
		}

	}

	return 0;

}
