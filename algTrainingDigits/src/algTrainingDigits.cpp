#include <map>
#include <iostream>

using namespace std;

string maxDigit(string s1, string s2) {

	map<char, int>smbs1;
	map<char, int>smbs2;

	for(int i=0; i<s1.length(); i++){
		if(smbs1.find(s1[i]) == smbs1.end()){
			smbs1[s1[i]]=0;
		}
		smbs1[s1[i]]++;
	}

	for(int i=0; i<s2.length(); i++){
		if(smbs2.find(s2[i]) == smbs2.end()){
			smbs2[s2[i]]=0;
		}
		smbs2[s2[i]]++;
	}

	bool isDigits = false;
	string ans="";
	auto it=smbs1.end();
	do{
		it--;
		if(smbs2.find(it->first) != smbs2.end()){
			for(int i=0; i < min(it->second, smbs2[it->first]); i++){
				ans+=it->first;
				isDigits=true;
			}
		}
	}while(it != smbs1.begin());

	if(!isDigits){
		ans="-1";
	}else{
		bool isNuls = true;
		for(int i=0; i<ans.length() && isNuls; i++){
			if(ans[i] != '0'){
				isNuls = false;
			}
		}
		if(isNuls){
			ans = "0";
		}
	}

	return ans;
}

int main(){

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	cout<<maxDigit(s1, s2);

	return 0;

}
