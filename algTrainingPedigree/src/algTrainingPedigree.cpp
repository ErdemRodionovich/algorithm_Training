#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

vector<string> findAllAncestors(map<string, string>*ancestors, string desc){

	vector<string>ancs;
	auto it = ancestors->find(desc);
	ancs.push_back(desc);
	while(it != ancestors->end()){
		ancs.push_back(it->second);
		it = ancestors->find(it->second);
	}

	return ancs;

}

int main() {

	int n;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	getline(fin, s);
	istringstream s_str(s);
	s_str>>n;
	map<string, string>ancestors;
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
		vector<string>ancs1 = findAllAncestors(&ancestors, el1);
		vector<string>ancs2 = findAllAncestors(&ancestors, el2);

		if(ancs1.size() > 0 && ancs2.size() > 0){

			int ind1 = ancs1.size()-1;
			int ind2 = ancs2.size()-1;
			string anc = "";
			while(ind1 >=0 && ind2 >= 0 && ancs1[ind1] == ancs2[ind2]){
				anc = ancs1[ind1];
				ind1--;
				ind2--;
			}

			fout<<anc<<"\n";
		}
	}

	return 0;
}
