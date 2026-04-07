#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void Operation(string st, int index, vector<int>& arr) {
	if (st == "add") {
		if (arr[index] !=index)
			arr[index] = index;
	}
	else if(st == "remove") {
		if(arr[index]==index)
			arr[index] = 0;
	}
	else if (st == "check") {
		if (arr[index] == index)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	else if (st == "toggle") {
		if (arr[index] == index)
			arr[index] = 0;
		else {
			arr[index] = index;
		}
	}
	else if (st == "all") {
		for (int i = 1; i <= 20; i++) {
			arr[i] = i;
		}
	}
	else if (st == "empty") {
		for (int i = 1; i <= 20; i++) {
			arr[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(21,0);
	string st;
	int index;
	while (n--) {
		cin >> st;
		if (st == "all" || st == "empty")
			Operation(st, 0, arr);
		else {
			cin >> index;
			Operation(st, index, arr);
		}
	}

	return 0;
}