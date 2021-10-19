#include <iostream>
#include <sstream>
#include <map>
#include <tuple>
#include <vector>
#include <fstream>

using namespace std;

bool isAncestor(string desc, string anc, map<string, string>*ancestors){

	bool answer = false;
	auto it = ancestors->find(desc);
	while(it != ancestors->end() && !answer){
		if(it->second == anc){
			answer = true;
		}else{
			it = ancestors->find(it->second);
		}
	}

	return answer;

}

int main() {

	int n;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	getline(fin, s);
	istringstream s_str(s);
	s_str>>n;
	//	descendant	ancestor
	map<string, 	string>ancestors;
	string desc, anc;
	for(int i=0; i<n-1; i++){
		getline(fin, s);
		s_str.str(s);
		s_str.clear();
		s_str>>desc;
		s_str>>anc;
		ancestors[desc] = anc;
	}
	string el1, el2;
	while(getline(fin, s)){
		s_str.str(s);
		s_str.clear();
		s_str>>el1;
		s_str>>el2;
		if(isAncestor(el2, el1, &ancestors)){
			fout<<"1 ";
		}else if(isAncestor(el1, el2, &ancestors)){
			fout<<"2 ";
		}else{
			fout<<"0 ";
		}
	}

	return 0;
}
