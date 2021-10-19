#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	map<string, unsigned int> words;
	string s, w;
	unsigned int c;
	ifstream fin("input.txt");
	ofstream out("output.txt");
	while(getline(fin, s)){

		istringstream s_str(s);
		while(s_str >> w){

			c = 1;
			auto it = words.find(w);
			if(it != words.end()){
				c += it->second;
			}
			words[w] = c;

		}

	}

	set<pair<unsigned int, string>>ordered_words;
	set<unsigned int>counts;
	for(auto it = words.begin(); it != words.end(); it++){
		ordered_words.insert({it->second, it->first});
		counts.insert(it->second);
	}

	if(!ordered_words.empty()){

		map<unsigned int, set<string>>freq;
		auto it_count = counts.end();
		while(it_count != counts.begin()){

			it_count--;
			string c_word = "";
			set<string> cur_words;
			auto it = ordered_words.upper_bound({*it_count, c_word});
			while(it != ordered_words.end() &&  it->first == *it_count){

				c_word = it->second;
				cur_words.insert(c_word);

				it = ordered_words.upper_bound({*it_count, c_word});
			}

			freq[*it_count] = cur_words;

		}

		auto iter = freq.end();
		while(iter != freq.begin()){
			iter--;
			for(auto itc = iter->second.begin(); itc != iter->second.end(); itc++){
				out<<*itc<<"\n";
			}
		}

	}

	return 0;

}
