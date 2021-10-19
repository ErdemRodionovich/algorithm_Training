#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(a != 0){
		float x = -(float)b/(float)a;
		if(x*c != -d){
			if(round(x) != x){
				cout<<"NO";
			}else{
				cout<<(-b/a);
			}
		}else{
			cout<<"NO";
		}
	}else{
		if(b != 0){
			cout<<"NO";
		}else if(c==0 && d==0){
			cout<<"NO";
		}else{
			cout<<"INF";
		}
	}

	return 0;
}
