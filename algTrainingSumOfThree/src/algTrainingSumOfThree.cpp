#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <chrono>

using namespace std;

vector<set<pair<int, int>>>all_indexes;

void printTime(string event, chrono::system_clock::time_point prevTime){

	auto readed = chrono::system_clock::now();
	chrono::duration<double> dif = readed - prevTime;
	cout<<event<<" "<<dif.count()<<"\n";

}

bool findNumber(vector<set<pair<long long, int>>>*nums, set<pair<int, int>>*indexes, long long s, int startInd){

	bool numberFound = false;
	set<pair<long long, int>>*m;
	m = &(*nums)[startInd];

	if(startInd < nums->size() - 1){

		cout<<"goto find\n";

		long long sumMin = 0, sumMax = 0;
		for(int i = 0; i<nums->size(); i++){

			if(i != startInd){
				set<pair<long long, int>>*r = &(*nums)[i];
				sumMin += r->begin()->first;
				auto it = r->end();
				it--;
				sumMax += it->first;
			}
		}

		if(s < sumMin + m->begin()->first){
			//cannot find
		}else{

			long long cr = s - sumMin;
			long long cl = max(s - sumMax, m->begin()->first);

			for(auto it = m->lower_bound({cl, 0}); it != m->end() && it->first <= cr && !numberFound; it++){

				if(s > it->first && findNumber(nums, indexes, s - it->first, startInd+1)){
					numberFound = true;
					indexes->insert({startInd, it->second});
				}

			}
		}

	}else if(startInd < nums->size()){

		auto it = m->lower_bound({s, 0});
		if(it != m->end() && it->first == s){
			numberFound = true;
			indexes->insert({startInd, it->second});
			all_indexes.push_back(*indexes);
		}

	}

	return numberFound;

}

int main() {

	auto start = chrono::system_clock::now();

	ifstream fin("threesum.in");
	ofstream fout("threesum.out");
	long long s;
	string str;
	getline(fin, str);
	istringstream s_s(str);
	s_s>>s;
	vector<set<pair<long long, int>>>nums;
	while(getline(fin, str)){

		set<pair<long long, int>>m;
		istringstream s_2(str);
		int n;
		long long d;
		s_2>>n;
		for(int i=0; i<n; i++){

			s_2>>d;
			auto it = m.lower_bound({d, 0});
			if(it == m.end() || it->first != d){
				m.insert({d, i});
			}
		}

		if(m.size() > 0){
			nums.push_back(m);
		}

	}

	auto readed = chrono::system_clock::now();
	printTime("readed", start);

	set<pair<int, int>>indexes;
	long long check = 0;
	for(int i=0; i < nums.size(); i++){

		auto it = nums[i].end();
		it--;
		check += it->first;
		indexes.insert({i, it->second});

	}

	if(check > s){

		indexes.clear();
		if(findNumber(&nums, &indexes, s, 0)){

			printTime("founded", readed);

			vector<int>minInd;
			for(int i=0; i < nums.size(); i++){

				int min = -1;
				bool minSetted = false;
				for(int j=0; j < all_indexes.size(); j++){

					bool canTake = true;
					int lmin = -1;
					set<pair<int, int>> *mi = &all_indexes[j];

					for(auto it = mi->begin(); it != mi->end() && canTake && it->first <= i; it++){

						for(int k=0; k < i && canTake; k++){
							if(k == it->first && minInd[k] != it->second){
								canTake = false;
							}
						}

						if(i == it->first){
							lmin = it->second;
						}

					}

					if(canTake && (min > lmin || !minSetted)){
						min = lmin;
						minSetted = true;
					}

				}

				minInd.push_back(min);

			}

			for(int i=0; i < minInd.size(); i++){
				fout<<minInd[i]<<" ";
			}

		}else{

			printTime("not founded", readed);

			fout<<"-1";
		}


	}else if(check == s){
		for(auto it = indexes.begin(); it != indexes.end(); it++){
			fout<<it->second<<" ";
		}
	}else{
		fout<<"-1";
	}

	return 0;
}
