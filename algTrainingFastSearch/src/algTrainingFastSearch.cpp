#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void sort(vector<int>*nums, int start, int finish, int x){

	int ex=start, grx=start, max=0, min=0, b, c;
	bool maxSetted = false, minSetted = false;
	for(int i=start; i<=finish; i++){

		c = (*nums)[i];
		if(c > max || !maxSetted){
			max = c;
			maxSetted = true;
		}

		if(c < min || !minSetted){
			min = c;
			minSetted = true;
		}

		if(c == x){
			b = (*nums)[grx];
			(*nums)[grx] = c;
			(*nums)[i] = b;
			grx++;
		}else if(c < x){
			(*nums)[i] = (*nums)[grx];
			(*nums)[grx] = (*nums)[ex];
			(*nums)[ex] = c;
			grx++;
			ex++;
		}

	}

	if(grx < finish && max > x && max > min){
		int lm = (x > min)? x : min;
		sort(nums, grx, finish, (max - lm)/2 + lm);
	}

	if(ex > start && x > min){
		sort(nums, start, ex, (x-min)/2 + min);
	}

}

int findIndexOfNotLess(vector<int>*nums, int value){

	int l = 0, r = nums->size(), c;

	while(l<r){

		c = (r-l)/2 + l;
		if((*nums)[c] >= value){
			r = c;
		}else{
			l = c + 1;
		}

	}

	return l;

}

int main() {

	int n, k;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	getline(fin, s);
	istringstream s_str(s);
	s_str >> n;
	vector<int>nums;
	int max=0, min=0, d;
	bool maxSetted = false, minSetted = false;
	getline(fin, s);
	istringstream s_2(s);
	for(int i=0; i<n; i++){
		s_2>>d;
		nums.push_back(d);
		if(d>max || !maxSetted){
			max = d;
			maxSetted = true;
		}
		if(d<min || !minSetted){
			min = d;
			minSetted = true;
		}
	}
	if(min < max){
		sort(&nums, 0, n-1, (max-min)/2 + min);
	}
	getline(fin, s);
	istringstream s_3(s);
	s_3>>k;
	int l, r, l_ind=0, r_ind=0;
	for(int i=0; i<k; i++){

		getline(fin, s);
		istringstream s_4(s);
		s_4>>l;
		s_4>>r;

		l_ind = findIndexOfNotLess(&nums, l);
		r_ind = findIndexOfNotLess(&nums, r+1);
		fout<<(r_ind-l_ind)<<" ";

	}

	return 0;
}
