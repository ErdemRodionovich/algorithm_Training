#include <iostream>
using namespace std;

int main() {

	int c[3][3];
	int x=0, n=0, lx=0, ln=0;

	for(int i=0; i<3; i++){

		for(int j=0; j<3; j++){

			cin>>c[i][j];
			if(c[i][j] == 1){
				x++;
			}else if(c[i][j] == 2){
				n++;
			}

		}

		if(c[i][0] == c[i][1] && c[i][1] == c[i][2]){
			if(c[i][0] == 1){
				lx++;
			}else if(c[i][0] == 2){
				ln++;
			}
		}

	}

	if(x >= n && x - n < 2 && lx < 3 && ln < 3){

		for(int i=0; i<3; i++){
			if(c[0][i] == c[1][i] && c[1][i] == c[2][i]){
				if(c[0][i] == 1){
					lx++;
				}else if(c[0][i] == 2){
					ln++;
				}
			}
		}

		if(c[0][0] == c[1][1] && c[1][1] == c[2][2]){
			if(c[2][2] == 1){
				lx++;
			}else if(c[2][2] == 2){
				ln++;
			}
		}

		if(c[0][2] == c[1][1] && c[1][1] == c[2][0]){
			if(c[2][0] == 1){
				lx++;
			}else if(c[2][0] == 2){
				ln++;
			}
		}

		if(lx > 2 || ln > 2){
			cout<<"NO";
		}else{

			if(lx == 1 && x == n){
				cout<<"NO";
			}else if(ln == 1 && x != n){
				cout<<"NO";
			}else{
				cout<<"YES";
			}
		}

	}else{
		cout<<"NO";
	}

	return 0;
}
