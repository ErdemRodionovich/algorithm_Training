#include <iostream>
using namespace std;

int main() {

	int x, y, z;
	cin>>x>>y>>z;

	if((x > 12 && y > 12
			|| x <= 12 && y < 12
			|| x < 12 && y <= 12)
			&& !(x == y && x <= 12)){
		cout<<0;
	}else{
		int m = min(x, y);
		int d = max(x, y);
		if(m == 2){
			if(z % 4 == 0){
				if(d < 30){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(d < 29){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(m==4
				|| m==6
				|| m==9
				|| m==11){

			if(d<31){
				cout<<1;
			}else{
				cout<<0;
			}
		}else {
			cout<<1;
		}
	}

	return 0;
}
