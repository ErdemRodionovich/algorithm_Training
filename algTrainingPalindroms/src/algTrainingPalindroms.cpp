#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cin>>str;
	int i=0, k = str.length()-1;
	int ans = 0;
	while(i < k){
		if(str[i] != str[k]){
			ans++;
		}
		i++;
		k--;
	}
	cout<<ans;

	return 0;
}
