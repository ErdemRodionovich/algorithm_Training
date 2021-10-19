#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

using namespace std;

void collectCodes(vector<tuple<int, int, int, int>>*tree, string currentCode, vector<string>*codes, int root){

	int parent, type, left, right;
	tie(parent, type, left, right) = (*tree)[root];
	if(left != -1){
		collectCodes(tree, currentCode+"0", codes, left);
	}
	if(right != -1){
		collectCodes(tree, currentCode+"1", codes, right);
	}
	if(left == -1 && right == -1){
		codes->push_back(currentCode);
	}

}

int main() {

	int n;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	getline(fin, s);
	istringstream s_str(s);
	s_str>>n;
	//				parent	type	left	right
	vector<tuple<	int, 	int, 	int, 	int>>tree;
	vector<string>codes;
	for(int i=0; i<n; i++){

		getline(fin, s);
		int root = tree.size();
		int now = root;
		int parent, type, left, right;
		tree.push_back({-1, 0, -1, -1});
		for(int j=0; j<s.length(); j++){

			tie(parent, type, left, right) = tree[now];
			if(s[j] == 'D'){

				int nn = tree.size();
				if(left == -1){
					tree.push_back({now, 0, -1, -1});
					left = nn;
				}else{
					tree.push_back({now, 1, -1, -1});
					right = nn;
				}
				tree[now] = {parent, type, left, right};
				now = nn;

			}else if(s[j] == 'U'){

				int typeBefore = type;
				do{
					typeBefore = type;
					now = parent;
					tie(parent, type, left, right) = tree[now];
				}while(typeBefore == 1);

				if(typeBefore == 0){
					if(right == -1){
						right = tree.size();
						tree.push_back({now, 1, -1, -1});
						tree[now] = {parent, type, left, right};
						now = right;
					}else{
						now = right;
					}
				}

			}

		}

		collectCodes(&tree, "", &codes, root);
		fout<<codes.size()<<"\n";
		for(int k=0; k<codes.size(); k++){
			fout<<codes[k]<<"\n";
		}

		codes.clear();
		tree.clear();

	}


	return 0;
}
