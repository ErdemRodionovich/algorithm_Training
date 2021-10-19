#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> d;
	int x;
	while(cin >> x){
		if(d.count(x) > 0){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
			d.insert(x);
		}
	}

	return 0;
}
