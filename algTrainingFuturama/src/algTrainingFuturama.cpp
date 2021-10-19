#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void change(vector<int>&d, set<pair<int, int>>&chs, int from, int to, bool print = true){

	int b = d[from];
	d[from] = d[to];
	d[to] = b;
	chs.insert({from, to});
	if(print){
		cout<<(from+1)<<" "<<(to+1)<<endl;
	}

}

bool HasChange(set<pair<int, int>>&chs, int a, int b){

	int fr = min(a, b);
	int to = max(a, b);

	return chs.count({fr, to}) > 0;

}

int NextIndex(set<pair<int, int>>&chs, set<pair<int, int>>&plan, int f, int count){

	int in = count-1;
	while((HasChange(chs, f, in) || in == f || HasChange(plan, f, in)) && in > 0){
		in--;
	}
	return in;
}

void MakeChange(vector<int>&d, set<pair<int, int>>&chs, set<pair<int, int>>&plan, int from, int to, int count){

	if(!HasChange(chs, from, to)){
		change(d, chs, from, to);
	}else{

		int ind = NextIndex(chs, plan, from, count);
		change(d, chs, from, ind);
		int cfr = min(to, ind);
		int cto = max(to, ind);
		if(HasChange(chs, cfr, cto)){
			MakeChange(d, chs, plan, cfr, cto, count);
		}else{
			change(d, chs, cfr, cto);
		}

	}

	if(plan.count({from, to}) > 0){
		plan.erase({from, to});
	}

}

int main() {

	int count, cc;
	cin>>count;
	cin>>cc;
	vector<int>d;
	for(int i=0; i < count; i++){
		d.push_back(i+1);
	}
	set<pair<int, int>> chs;
	set<pair<int, int>> plan;
	int f=0, t=0;
	for(int i=0; i < cc; i++){
		cin>>f>>t;
		change(d, chs, f-1, t-1, false);
	}

	for(int i=0; i < count-2; i++){

		if(d[i] != i+1){

			int n = i;
			while(d[n] != i+1){
				change(d, chs, n, count-2);
				n = d[count-2]-1;
			}

			change(d, chs, n, count-1);
			n = d[count-1]-1;
			change(d, chs, n, count-1);
			n = d[count-2]-1;
			change(d, chs, n, count-2);

		}

	}

	if(d[count-2] == count){
		change(d, chs, count-2, count-1);
	}

/*
	bool hasShange = true;
	while(hasShange){
		hasShange = false;
		int j=0;
		while(j<count){

			if(d[j] != j+1){

				int p = j+1;
				while(d[p] != j+1 && p < count){
					p++;
				}

				MakeChange(d, chs, plan, j, p, count);
				hasShange = true;

			}

			j++;

		}
	}*/
	return 0;
}




