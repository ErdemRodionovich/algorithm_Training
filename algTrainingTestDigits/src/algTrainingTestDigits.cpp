#include <map>
#include <iostream>
#include <random>
#include <set>

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
	}

	return ans;
}

int main(){

	string s1, s2;

	random_device rd;
	mt19937 gen(rd());

	bool isError = false;
	string ans, digit;
	map<int, int>ds;
	int dl=0, lim=10;
	do{

		digit = "";
		dl = generate_canonical<double, 10>(gen) * 10;
		for(int i=0; i < dl; i++){

			int a = generate_canonical<double, 10>(gen) * 10;
			//if(ds.find())

		}

		ans = maxDigit(s1, s2);

	}while(!isError);

	cout<<s1<<"\n"<<s2;

	return 0;

}
