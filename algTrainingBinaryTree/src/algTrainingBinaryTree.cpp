#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;

string add(vector<tuple<int, int, int>>*tree, int value, int root){

	string result = "DONE";

	if(tree->size() == 0){
		tree->push_back({value, -1, -1});
	}else{

		int valueOfRootNode = get<0>((*tree)[root]);
		if(valueOfRootNode == value){
			result = "ALREADY";
		}else if(value < valueOfRootNode){
			int left = get<1>((*tree)[root]);
			if(left == -1){
				left = tree->size();
				tree->push_back({value, -1, -1});
				(*tree)[root] = {valueOfRootNode, left, get<2>((*tree)[root])};
			}else{
				result = add(tree, value, left);
			}
		}else{
			int right = get<2>((*tree)[root]);
			if(right == -1){
				right = tree->size();
				tree->push_back({value, -1, -1});
				(*tree)[root] = {valueOfRootNode, get<1>((*tree)[root]), right};
			}else{
				result = add(tree, value, right);
			}
		}

	}

	return result;

}

string search(vector<tuple<int, int, int>>*tree, int value, int root){

	string result = "NO";

	if(tree->size() != 0){

		int valueOfRootNode = get<0>((*tree)[root]);
		if(valueOfRootNode == value){
			result = "YES";
		}else{
			if(value < valueOfRootNode){
				int left = get<1>((*tree)[root]);
				if(left != -1){
					result = search(tree, value, left);
				}
			}else{
				int right = get<2>((*tree)[root]);
				if(right != -1){
					result = search(tree, value, right);
				}
			}

		}

	}

	return result;

}

string print_tree(vector<tuple<int, int, int>>*tree, int root, int depth=0){

	string result = "";
	int left = get<1>((*tree)[root]);
	if(left != -1){
		result += print_tree(tree, left, depth + 1)+"\n";
	}
	for(int i=0; i<depth; i++){
		result += ".";
	}
	int valueOfRootNode = get<0>((*tree)[root]);
	result += to_string(valueOfRootNode);
	int right = get<2>((*tree)[root]);
	if(right != -1){
		result += "\n"+print_tree(tree, right, depth+1);
	}

	return result;

}

int main() {

	//				value	left	right
	vector<tuple<	int, 	int, 	int>>tree;

	string s, command;
	int value;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	while(getline(fin, s)){

		if(s.find("ADD") != string::npos){
			istringstream s_str(s);
			s_str>>command;
			s_str>>value;
			fout<<add(&tree, value, 0)<<"\n";
		}else if(s.find("SEARCH") != string::npos){
			istringstream s_str(s);
			s_str>>command;
			s_str>>value;
			fout<<search(&tree, value, 0)<<"\n";
		}else if(s.find("PRINTTREE") != string::npos){
			fout<<print_tree(&tree, 0, 0)<<"\n";
		}

	}

	return 0;
}
