#include <iostream>

using namespace std;

int main() {

	int curSum=0;
	string s;
	getline(cin ,s);
	for(int i=0; i < s.length() && curSum >=0; i++){
		if(s[i] == '('){
			curSum++;
		}else{
			curSum--;
		}
	}

	if(curSum == 0){
		cout<<"YES";
	}else{
		cout<<"NO";
	}

	return 0;
}
