
#include <iostream>
using namespace std;

int main() {

	int n, enter, exit, ans;
	cin>>n>>enter>>exit;
	ans = min((max(enter, exit) - min(enter, exit)), (n+min(enter, exit)-max(enter, exit))) - 1;

	cout<<ans;

	return 0;
}
