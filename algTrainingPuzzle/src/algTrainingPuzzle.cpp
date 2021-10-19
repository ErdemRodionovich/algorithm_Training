#include <sstream>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

vector<vector<char>> reb;
vector<vector<int>> d;
vector<string>words;
map<int, vector<set<pair<int, int>>>>wordsPlacements;

bool findWord(string curWord, int x, int y, int posOfSymbol, set<pair<int, int>>*positionsOfWord, int indWord){

	bool symbolFound = false;
	int cx, cy;
	vector<set<pair<int, int>>>ways;
	for(int r=0; r<4; r++){

		cx = x + d[r][0];
		cy = y + d[r][1];

		if(curWord[posOfSymbol] == reb[cx][cy]){
			if(positionsOfWord->find({cx, cy}) == positionsOfWord->end()){

				set<pair<int, int>> childWay;
				for(auto posIt = positionsOfWord->begin(); posIt != positionsOfWord->end(); posIt++){
					childWay.insert({posIt->first, posIt->second});
				}
				childWay.insert({cx, cy});
				if(posOfSymbol+1 < curWord.length()){
					if(findWord(curWord, cx, cy, posOfSymbol+1, &childWay, indWord)){
						symbolFound = true;
						ways.push_back(childWay);
					}
				}else{
					symbolFound = true;
					ways.push_back(childWay);
				}

			}
		}

	}

	if(symbolFound){

		for(auto it = ways[0].begin(); it != ways[0].end(); it++){
			positionsOfWord->insert({it->first, it->second});
		}

		for(int i=1; i < ways.size(); i++){
			wordsPlacements[indWord].push_back(ways[i]);
		}

	}

	return symbolFound;

}

bool findNonIntersectPlacement(int indWord, set<pair<int, int>>*positionsOfWord){

	bool findPlacement = false;

	for(int i=0; i < wordsPlacements[indWord].size() && !findPlacement; i++){

		bool hasPlacement = true;
		for(auto it = wordsPlacements[indWord][i].begin(); it != wordsPlacements[indWord][i].end() && hasPlacement; it++){
			if(positionsOfWord->find({it->first, it->second}) != positionsOfWord->end()){
				hasPlacement = false;
			}
		}

		if(hasPlacement){

			if(indWord+1 < words.size()){

				set<pair<int, int>>childPlacement;
				for(auto it = wordsPlacements[indWord][i].begin(); it != wordsPlacements[indWord][i].end() && hasPlacement; it++){
					childPlacement.insert({it->first, it->second});
				}
				for(auto it = positionsOfWord->begin(); it != positionsOfWord->end(); it++){
					childPlacement.insert({it->first, it->second});
				}

				if(!findNonIntersectPlacement(indWord+1, &childPlacement)){
					hasPlacement = false;
				}else{
					for(auto it = childPlacement.begin(); it != childPlacement.end(); it++){
						positionsOfWord->insert({it->first, it->second});
					}
				}
			}else{
				for(auto it = wordsPlacements[indWord][i].begin(); it != wordsPlacements[indWord][i].end() && hasPlacement; it++){
					positionsOfWord->insert({it->first, it->second});
				}
			}

			if(hasPlacement){
				findPlacement = true;
			}

		}

	}

	return findPlacement;

}

void addVector(int i, int j){

	vector<int>d1;
	d1.push_back(i);
	d1.push_back(j);
	d.push_back(d1);

}

void printReb(){

	cout<<"\nReb=\n";
	for(auto it=reb.begin(); it!=reb.end(); it++){
		for(auto ic = it->begin(); ic != it->end(); ic++){
			cout<<*ic;
		}
		cout<<"\n";
	}

}

int main() {

	int n, m;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>n;
	s_str>>m;

	for(int i=0; i<=n+1; i++){
		vector<char>vc;
		for(int j=0; j<=n+1; j++){
			vc.push_back(0);
		}
		reb.push_back(vc);
	}

	for(int i=1; i<=n; i++){

		getline(cin, s);
		for(int j=0; j<n; j++){
			reb[i][j+1]=s[j];
		}

	}

	//printReb();

	for(int i=0; i<m; i++){
		getline(cin, s);
		words.push_back(s);
	}

	set<pair<int, int>>positionsOfWord;
	addVector(0, 1);
	addVector(1, 0);
	addVector(0, -1);
	addVector(-1, 0);

	for(int w=0; w < words.size(); w++){

		bool wordFound = false;
		if(wordsPlacements.find(w) == wordsPlacements.end()){
			vector<set<pair<int, int>>> pls;
			wordsPlacements[w] = pls;
		}
		string curWord = words[w];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){

				if(curWord[0] == reb[i][j]){

					positionsOfWord.insert({i, j});
					if(findWord(curWord, i, j, 1, &positionsOfWord, w)){

						wordFound = true;
						wordsPlacements[w].push_back(positionsOfWord);
						positionsOfWord.clear();

					}else{
						positionsOfWord.erase({i, j});
					}

				}

			}
		}

		if(!wordFound){
			//cout<<"\nWord "<<curWord<<" NOT FOUND!";
		}

		positionsOfWord.clear();

	}

	/*for(auto it = wordsPlacements.begin(); it != wordsPlacements.end(); it++){

		for(int i=0; i < it->second.size(); i++){
			cout<<words[it->first];
			for(auto plIt = it->second[i].begin(); plIt != it->second[i].end(); plIt++){
				cout<<" "<<plIt->first<<","<<plIt->second;
			}
			cout<<"\n";
		}
	}*/

	findNonIntersectPlacement(0, &positionsOfWord);
	for(auto it = positionsOfWord.begin(); it != positionsOfWord.end(); it++){
		reb[it->first][it->second] = 0;
	}

	//printReb();

	map<char, int>sms;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(reb[i][j] != 0){
				if(sms.find(reb[i][j]) == sms.end()){
					sms[reb[i][j]] = 0;
				}
				sms[reb[i][j]]++;
			}
		}
	}

	for(auto it=sms.begin(); it!=sms.end(); it++){
		for(int i=0; i < it->second; i++){
			cout<<it->first;
		}
	}

	return 0;
}
