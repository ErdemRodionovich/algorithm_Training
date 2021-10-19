#include <iostream>
#include <sstream>
using namespace std;


int main() {

	int n;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	long long numbers[n];
	long long sums[n+1];
	long long curSum = 0, d=0;
	getline(cin, s);
	istringstream s_2(s);
	long long maxSum = 0, minSum = 0;
	bool maxSetted = false, minSetted = false;
	int indOfMax, indOfMin;
	for(int i=0; i<n; i++){
		sums[i]=curSum;
		s_2>>d;
		numbers[i] = d;
		curSum += d;
		if(maxSum < curSum || !maxSetted){
			maxSum = curSum;
			maxSetted = true;
			indOfMax = i+1;
		}
		if(minSum > curSum || !minSetted){
			minSum = curSum;
			minSetted = true;
			indOfMin = i+1;
		}
	}
	sums[n] = curSum;
	long long checkMax = maxSum;

	if(indOfMin < indOfMax){
		if(maxSum - minSum > maxSum){
			maxSum -= minSum;
		}
	}else{

		int l=0, r=1, prev_l=0, prev_r=1, chl=0;
		while(r<n && l+1 < n){

			while(l+1 < n && sums[l+1] <= sums[l]){
				l++;
			}
			r = l + 1;
			while(sums[r+1] >= sums[r] && r < n){
				r++;
			}
			chl = l;
			if(sums[r] > sums[prev_r] && sums[l] > sums[prev_l] && sums[l] <= sums[prev_r]){
				chl = prev_l;
			}
			if(sums[r] <= sums[prev_r] && sums[l] >= sums[prev_l] && l != prev_l){
				l = r + 1;
			}else{

				curSum = sums[r] - sums[chl];
				if(maxSum < curSum){
					maxSum = curSum;
				}
				prev_l = chl;
				prev_r = r;
				l = r + 1;

			}

		}

	}
/*
	for(int i=0; i<n; i++){
		for(int j=i+1; j<=n; j++){
			curSum = sums[j] - sums[i];
			if(checkMax < curSum){
				checkMax = curSum;
			}
		}
	}
*/

	cout<<maxSum;//<<" checkSum="<<checkMax;

	return 0;
}
