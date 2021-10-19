#include <sstream>
#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {

	int n, k;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	s_str>>k;
	getline(cin, s);

	set<char>firstSymbols;
	map<char, int>countOfFirstSymbols;
	map<char, set<char>>firstSymbolsBySecond;

	string ps;
	for(int i=0; i<k; i++){

		getline(cin, ps);
		firstSymbols.insert(ps[0]);
		countOfFirstSymbols[ps[0]]=0;
		if(firstSymbolsBySecond.find(ps[1]) != firstSymbolsBySecond.end()){
			firstSymbolsBySecond[ps[1]].insert(ps[0]);
		}else{
			set<char>fSms;
			fSms.insert(ps[0]);
			firstSymbolsBySecond[ps[1]]=fSms;
		}

	}

	int countOfPairs = 0;
	char c;
	for(int i=0; i<s.length(); i++){

		c = s[i];
		auto fsBySecond = firstSymbolsBySecond.find(c);
		if(fsBySecond != firstSymbolsBySecond.end()){

			for(auto it = fsBySecond->second.begin(); it != fsBySecond->second.end(); it++){
				countOfPairs += countOfFirstSymbols[*it];
			}

		}

		if(firstSymbols.find(c) != firstSymbols.end()){
			countOfFirstSymbols[c]++;
		}

	}

	cout<<countOfPairs;

	return 0;
}
