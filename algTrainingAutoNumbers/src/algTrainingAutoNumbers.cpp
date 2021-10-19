#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {

	int sc;
	set<pair<char,int>>ps;
	vector<int> count_sym_s;
	set<char>smbs;
	string s;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>sc;

	int count_s;
	for(int i=0; i<sc; i++){
		getline(cin, s);
		smbs.clear();
		for(int j=0; j<s.length(); j++){
			ps.insert({s[j], i});
			smbs.insert(s[j]);
		}
		count_s = 0;
		for(auto it=smbs.begin(); it!= smbs.end(); it++){
			count_s++;
		}
		count_sym_s.push_back(count_s);
	}

	int max = 0;
	set<pair<int, int>>cs;
	int cs_cs = 0;
	int c_max = 0;
	vector<string>s_max;
	int n;
	getline(cin, s);
	istringstream s_str2(s);
	s_str2>>n;

	for(int i=0; i<n; i++){

		getline(cin, s);
		smbs.clear();
		cs.clear();

		for(int j=0; j<s.length(); j++){
			char sym = s[j];
			smbs.insert(sym);
		}

		for(auto c_sym=smbs.begin(); c_sym!=smbs.end(); c_sym++){

			auto it = ps.lower_bound({*c_sym, 0});
			while(it != ps.end() && it->first == *c_sym){

				auto ics = cs.lower_bound({it->second, 0});
				cs_cs =0;
				if(ics != cs.end() && ics->first == it->second){
					cs_cs = ics->second;
					cs.erase(ics);
				}
				cs.insert({it->second, cs_cs+1});

				it = ps.lower_bound({*c_sym, it->second+1});
			}
		}

		c_max = 0;
		for(auto it = cs.begin(); it != cs.end(); it++){
			if(count_sym_s[it->first] == it->second){
				c_max++;
			}
		}

		if(c_max > max){
			max = c_max;
			s_max.clear();
			s_max.push_back(s);
		}
		else if(c_max == max){
			s_max.push_back(s);
		}

	}

	for(auto it=s_max.begin(); it != s_max.end(); it++){
		cout<<*it<<"\n";
	}

	return 0;
}
