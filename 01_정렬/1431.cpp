#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNum(string serial) {
	int sum = 0;
	for (int i = 0; i < serial.size(); i++) {
		if (isdigit(serial[i])) {
			sum += serial[i]-'0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	if (sumNum(a) != sumNum(b)) {
		return sumNum(a) < sumNum(b);
	}
}
int main() {
	int n;
	cin >> n;
	vector<string> guitar(n);
	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}
	sort(guitar.begin(), guitar.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << guitar[i] << '\n';
	}

	return 0;
}
