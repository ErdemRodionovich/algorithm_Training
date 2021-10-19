#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int findMaxDepths(map<int, vector<int>>*tree, int root, int *maxSum){

	int maxDepth = 0;
	auto it = tree->find(root);
	if(it != tree->end()){

		int maxDepth1=0, maxDepth2=0;
		for(auto sonPtr = it->second.begin(); sonPtr != it->second.end(); sonPtr++){

			int childDepth = findMaxDepths(tree, (*sonPtr), maxSum) + 1;
			if(maxDepth1 < maxDepth2){
				if(maxDepth1 < childDepth){
					maxDepth1 = childDepth;
				}
			}else{
				if(maxDepth2 < childDepth){
					maxDepth2 = childDepth;
				}
			}

		}

		if(maxDepth1 < maxDepth2){
			maxDepth = maxDepth2;
		}else{
			maxDepth = maxDepth1;
		}

		int count = maxDepth1 + maxDepth2 + 1;
		if(count > (*maxSum)){
			*maxSum = count;
		}

	}

	return maxDepth;

}

int main() {

	int n;
	string s;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	getline(fin, s);
	istringstream s_str(s);
	s_str>>n;
	//	parent	sons
	map<int, 	vector<int>>tree;
	set<int> roots;
	int el1, el2, root;
	bool rootSetted = false;
	for(int i=0; i<n-1; i++){
		getline(fin, s);
		s_str.str(s);
		s_str.clear();
		s_str>>el1;
		s_str>>el2;
		auto it = tree.find(el1);
		if(it == tree.end()){
			it = tree.find(el2);
			if(it == tree.end()){
				vector<int>sons;
				sons.push_back(el2);
				tree[el1] = sons;
				roots.insert(el1);
				if(!rootSetted){
					root = el1;
					rootSetted = true;
				}
				vector<int>sons2;
				tree[el2] = sons2;
			}else{
				it->second.push_back(el1);
				vector<int>sons2;
				tree[el1] = sons2;
			}
		}else{
			auto it_2 = tree.find(el2);
			if(it_2 == tree.end()){
				it->second.push_back(el2);
				vector<int>sons2;
				tree[el2] = sons2;
			}else{

				bool firstIsRoot = roots.find(el1) != roots.end();
				if(firstIsRoot){
					it_2->second.push_back(el1);
					roots.erase(el1);
				}else{
					it->second.push_back(el2);
					if(roots.find(el2) != roots.end()){
						roots.erase(el2);
					}
				}

			}
		}
	}

	int maxSum=0;
	findMaxDepths(&tree, root, &maxSum);
	fout<<maxSum;

	return 0;
}
