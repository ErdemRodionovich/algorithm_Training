#include <iostream>
using namespace std;

bool LinesParellelAndEqual(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy){

	int x1;
	int y1;
	if(ax > bx || (ax == bx && ay > by)){
		x1 = ax - bx;
		y1 = ay - by;
	}else{
		x1 = bx - ax;
		y1 = by - ay;
	}

	int x2;
	int y2;
	if(cx > dx || (cx == dx && cy > dy)){
		x2 = cx - dx;
		y2 = cy - dy;
	}else{
		x2 = dx - cx;
		y2 = dy - cy;
	}

	return (x1 == x2 && y1 == y2);

}

int main() {

	int count=0;
	cin>>count;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	bool ans[count];
	for(int i=0; i<count; i++){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		ans[i] = false;
		if(LinesParellelAndEqual(x1, y1, x2, y2, x3, y3, x4, y4)){
			ans[i] = true;
		}else if(LinesParellelAndEqual(x1, y1, x3, y3, x2, y2, x4, y4)){
			ans[i] = true;
		}else if(LinesParellelAndEqual(x1, y1, x4, y4, x2, y2, x3, y3)){
			ans[i] = true;
		}
	}

	for(int i=0; i<count; i++){
		if(ans[i]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}

