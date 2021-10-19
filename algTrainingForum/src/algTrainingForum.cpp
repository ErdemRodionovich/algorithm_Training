#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	int n;
	string s;
	getline(cin, s);
	istringstream s_s(s);
	s_s>>n;
	int msgTopics[n+1];
	vector<string> topics;
	vector<int> cntMsgsByTopics;

	int num;

	for(int i=1; i<=n; i++){

		getline(cin, s);
		istringstream s_str(s);
		s_str>>num;

		if(num == 0){

			getline(cin, s);
			msgTopics[i] = topics.size();
			topics.push_back(s);
			cntMsgsByTopics.push_back(1);

		}else{

			int topicIndex = msgTopics[num];
			msgTopics[i] = topicIndex;
			cntMsgsByTopics[topicIndex]++;

		}

		getline(cin, s);

	}

	if(cntMsgsByTopics.size() > 0){

		int maxCnt = 0;
		int topIndex = 0;
		for(int i=0; i<cntMsgsByTopics.size(); i++){
			if(maxCnt < cntMsgsByTopics[i]){
				maxCnt = cntMsgsByTopics[i];
				topIndex = i;
			}
		}

		cout<<topics[topIndex];

	}


	return 0;
}
