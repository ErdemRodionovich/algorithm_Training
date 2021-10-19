#include <iostream>
using namespace std;

int main() {

	int d, xX, xY;
	cin>>d>>xX>>xY;

	if(xX >=0 && xX <= d
			&& xY >= 0 && xY <= d
			&& (xY <= d-xX)
			){

		cout<<0;

	}else{

		int r1 = abs(xX) + abs(xY);
		int r2 = abs(xX - d) + abs(xY);
		int r3 = abs(xX) + abs(xY - d);

		if(r1 <= r2 && r1 <= r3){
			cout<<1;
		}else if(r2 <= r1 && r2 <= r3){
			cout<<2;
		}else{
			cout<<3;
		}

	}

	return 0;
}
