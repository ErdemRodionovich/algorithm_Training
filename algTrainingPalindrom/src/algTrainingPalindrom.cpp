#include <map>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	string s;
	int n;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	map<char, int>symbols;
	getline(cin, s);
	for(int j=0; j<s.length(); j++){
		if(symbols.find(s[j]) != symbols.end()){
			symbols[s[j]]++;
		}else{
			symbols[s[j]] = 1;
		}
	}

	string p="";
	bool symbolAddedForOdd = false;
	for(auto it=symbols.begin(); it != symbols.end(); it++){

		if(it->second > 1){
			for(int i=0; (i+2) <= it->second; i+=2){
				p += it->first;
			}
			symbols[it->first] = it->second % 2;
		}

	}

	for(auto it=symbols.begin(); it!=symbols.end() && !symbolAddedForOdd; it++){
		if(it->second > 0){
			p += it->first;
			symbolAddedForOdd = true;
		}
	}

	int i=p.length()-1;
	if(symbolAddedForOdd){
		i=p.length()-2;
	}
	while(i >= 0){
		p += p[i];
		i--;
	}

	if(p.length() == 0){
		p += symbols.begin()->first;
	}

	cout<<p;

	return 0;
}
