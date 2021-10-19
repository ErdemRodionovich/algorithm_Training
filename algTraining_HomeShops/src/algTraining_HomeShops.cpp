#include <iostream>
using namespace std;

int main() {

	int hs[10];
	int s[10];
	int ans=0, j=0;
	for(int i=0; i<10; i++){
		cin>>hs[i];
		if(hs[i] == 2){
			s[j] = i;
			j++;
		}
	}

	int min_rh, tr;
	bool ansSeted = false;
	for(int i=0; i<10; i++){
		if(hs[i] == 1){
			min_rh = 11;
			for(int k=0; k<j; k++){
				tr = abs(i-s[k]);
				if(min_rh > tr){
					min_rh = tr;
				}
			}
			if(!ansSeted){
				ans = min_rh;
				ansSeted = true;
			}else if(ans < min_rh){
				ans = min_rh;
			}
		}
	}

	cout<<ans;

	return 0;
}
