
#include <iostream>
using namespace std;

int main() {

	int count;
	cin>>count;
	int d[count];
	int ans = 0;
	int ts = 0;
	int r[count];
	for(int i=0; i<count; i++){
		cin>>d[i];
		r[i] = ts;
		ts += d[i];
		for(int j=0; j<i; j++){
			r[j] += d[i];
		}
	}

	if(count>0){
		ans=r[0];
		for(int i=1; i<count; i++){
			if(ans > r[i]){
				ans = r[i];
			}
		}
		cout<<ans;
	}



	return 0;
}
