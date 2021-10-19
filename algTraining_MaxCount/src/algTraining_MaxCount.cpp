
#include <iostream>
using namespace std;

int main() {

	int ans, tm, d;
	cin>>d;
	tm = d;
	ans = 1;
	while(d != 0){
		cin>>d;
		if(tm < d){
			tm = d;
			ans = 1;
		}else if(tm == d){
			ans++;
		}
	}

	cout<<ans;

	return 0;
}
