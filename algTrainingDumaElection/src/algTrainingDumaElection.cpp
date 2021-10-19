#include <set>
#include <iostream>
#include <fstream>
#include <tuple>
#include <sstream>
#include <map>
#include <stdio.h>

using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string s, p;
	//        number voices name
	set<tuple<int,   int,   string>>election;
	int numOfParties = 0;
	int voices=0;
	int v = 0;

	while(getline(fin, s) && s.length() > 0){

		string name="", nums="";
		bool isDigits = true;
		for(int i=s.length()-1; i>=0; i--){

			if(isDigits){
				if(!(s[i] >= 48 && s[i] <= 57)){
					isDigits = false;
				}
			}

			if(isDigits){
				nums = s[i] + nums;
			}else{
				name = s[i] + name;
			}

		}

		v=0;
		if(nums.length() > 0){
			sscanf(nums.c_str(), "%d", &v);
		}

		voices += v;
		election.insert({numOfParties, v, name});

		numOfParties++;

	}

	//	      remainder  voices  number
	set<tuple<int, 		 int,  	 int>> elResult;
	map<int, long long> seatsByIndex;
	long long rem, seats, sumOfSeats = 0, b=0;
	int i=0;

	if(voices > 0){

		for(auto it = election.begin(); it != election.end(); it++){

			b = get<1>(*it);
			seats = 450 * b / voices;
			rem = 450 * b % voices;
			i = get<0>(*it);
			elResult.insert({rem, b, i});
			seatsByIndex[i] = seats;
			sumOfSeats += seats;

		}

		if(sumOfSeats < 450){

			auto it = elResult.end();
			do{

				it--;
				i = get<2>(*it);
				seatsByIndex[i] = seatsByIndex[i] + 1;
				sumOfSeats++;

			}while(it != elResult.begin() && sumOfSeats < 450);
		}

		for(auto it = election.begin(); it != election.end(); it++){

			fout<<get<2>(*it)<<seatsByIndex[get<0>(*it)]<<"\n";

		}

	}

	return 0;
}
