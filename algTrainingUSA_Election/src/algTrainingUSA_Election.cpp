
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() {

	ifstream f("input.txt");
	ofstream out("output.txt");

	string s;
	map<string, unsigned int>votes;
	string name;
	unsigned int v;
	while(getline(f, s)){

		istringstream s_str(s);
		s_str>>name;
		s_str>>v;
		auto it = votes.find(name);
		if(it != votes.end()){
			v += it->second;
		}

		votes[name] = v;

	}

	for(auto it = votes.begin(); it != votes.end(); it++){
		out<<it->first<<" "<<it->second<<"\n";
	}

	return 0;
}
