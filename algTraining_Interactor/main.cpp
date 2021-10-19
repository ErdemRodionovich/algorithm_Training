#include <iostream>

using namespace std;

int main(){

	int code, interactor, checker;

	cin>>code;
	cin>>interactor;
	cin>>checker;

	int ans = interactor;
	switch(interactor){
	case 0:
		if(code != 0){
			ans = 3;
		}else{
			ans = checker;
		}
		break;
	case 1:
		ans = checker;
		break;
	case 4:
		if(code != 0){
			ans = 3;
		}else{
			ans = 4;
		}
		break;
	case 6:
		ans = 0;
		break;
	case 7:
		ans = 1;
		break;
	default:
		ans = interactor;
		break;
	}

	cout<<ans;

}
