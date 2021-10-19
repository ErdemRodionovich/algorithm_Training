#include <iostream>
using namespace std;

int main() {

	int n, h, e;
	cin>>n;
	h = n/2;
	for(int i=0; i<n; i++){
		cin>>e;
		if(i>=h){
			cout<<e;
			break;
		}
	}

/*
	int d[n], r[n];
	for(int i=0; i<n; i++){
		cin>>d[i];
		r[i]=0;
	}
	int ans = 0;
	if(n>0){

		int rt=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				rt = d[j] - d[i];
				r[i] += rt;
				r[j] += rt;
			}
		}

		rt = r[0];
		for(int i=1; i<n; i++){
			if(rt > r[i]){
				rt = r[i];
				ans = i;
			}
		}
		cout<<d[ans];
	}
*/
	return 0;
}
