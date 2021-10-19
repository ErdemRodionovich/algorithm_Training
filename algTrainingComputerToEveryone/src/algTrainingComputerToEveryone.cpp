#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

	int n, m;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	s_str>>m;

	//  group 	auditoria
	map<int,  	int>pl;

	//  students 	numbers
	map<int,     	vector<int>> groups;

	//  seats 	numbers
	map<int,  	vector<int>> auds;

	getline(cin, s);
	istringstream s_2(s);
	int c;
	for(int i=1; i<=n; i++){

		s_2>>c;
		c++;//Teacher
		pl[i]=0;

		if(groups.find(c) == groups.end()){
			vector<int>v;
			groups[c] = v;
		}
		groups[c].push_back(i);

	}
	getline(cin, s);
	istringstream s_3(s);
	for(int i=1; i<=m; i++){

		s_3>>c;
		if(auds.find(c) == auds.end()){
			vector<int>v;
			auds[c] = v;
		}
		auds[c].push_back(i);

	}

	int count=0;
	auto caud = auds.begin();
	for(auto cgr = groups.begin(); cgr != groups.end(); cgr++){

		while(cgr->second.size() > 0 && caud != auds.end()){

			while(caud != auds.end() && (cgr->first > caud->first || caud->second.size() == 0)){
				caud++;
			}

			if(caud != auds.end()){
				int cnt = min(cgr->second.size(), caud->second.size());
				int numAud, numGr;
				for(int i=0; i< cnt; i++){

					numAud = caud->second[caud->second.size()-1];
					numGr = cgr->second[cgr->second.size()-1];
					pl[numGr] = numAud;
					caud->second.pop_back();
					cgr->second.pop_back();
					count++;

				}
			}

		}

	}

	cout<<count<<"\n";
	if(count > 0){
		for(auto it = pl.begin(); it != pl.end(); it++){
			cout<<it->second<<"\n";
		}
	}else{
		cout<<"0\n";
	}

	return 0;
}
