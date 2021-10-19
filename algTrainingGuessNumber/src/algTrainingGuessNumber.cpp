#include <sstream>
#include <iostream>
#include <set>
using namespace std;

int main() {

	long max = 0;
	string s, aug_ans = "";
	set<long>yes;
	set<long>no;
	set<long>step;
	long x;
	bool isNext = true;
	getline(cin, s);
	istringstream s_str(s);
	s_str>>max;
	bool secondYes = false;
	bool isYes = false;
	while(isNext){

		getline(cin, s);
		if(s.find("HELP") != string::npos ){
			isNext = false;
		}else{
			getline(cin, aug_ans);
			if(aug_ans.find("YES") != string::npos){
				isYes = true;
			}else{
				isYes = false;
			}
			istringstream s_str(s);
			while(s_str >> x){
				if(x <= max){
					if(isYes){
						step.insert(x);
						if(secondYes && yes.count(x) == 0){
							no.insert(x);
						}else if(!secondYes && no.count(x) == 0){
							yes.insert(x);
						}
					}else{
						no.insert(x);
						auto it = yes.find(x);
						if(it != yes.end()){
							yes.erase(it);
						}
					}
				}
			}

			if(isYes){
				auto it = yes.end();
				if(it != yes.begin()){
					it--;
					while(it != yes.begin()){
						if(step.count(*it) == 0){
							no.insert(*it);
							yes.erase(it);
						}
						it--;
					}
					if(step.count(*yes.begin()) == 0){
						yes.erase(yes.begin());
					}
					step.clear();
				}
				secondYes = true;
			}
		}

	}

	if(secondYes){
		for(auto it = yes.begin(); it != yes.end(); it++){
			cout<<*it<<" ";
		}
	}else{

		for(int i=1; i<=max; i++){
			if(no.count(i) == 0){
				cout<<i<<" ";
			}
		}

	}
	return 0;
}
