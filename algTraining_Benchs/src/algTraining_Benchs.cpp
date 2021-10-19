#include <iostream>
using namespace std;

int main() {

	int dl, count;
	cin>>dl>>count;
	int b[count];
	bool mb_one = (dl % 2 != 0);
	int c1 = dl/2;
	int c2 = c1 + 1;
	int ans1=0;
	int ans2=0;
	bool ans2Setted = false;
	bool isOne = false;
	for(int i=0; i<count; i++){

		cin>>b[i];
		if(b[i] < c1){
			ans1 = b[i];
		}else if(b[i] == c1 && mb_one){
			ans1 = b[i];
			isOne = true;
		}else if(!ans2Setted){
			ans2 = b[i];
			ans2Setted = true;
		}

	}

	cout<<ans1;
	if(!isOne){
		cout<<" "<<ans2;
	}

	return 0;
}
