#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque <int> da;
	deque <int> db;
	deque <int> dsum;

	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		da.push_back(a[i] - '0');
	for (int i = 0; i < b.size(); i++)
		db.push_back(b[i] - '0');
	int carry = 0;
	while (!da.empty() || !db.empty() || carry) {
		int sum = carry;
		if (!da.empty()) {
			sum += da.back();
			da.pop_back();
		}
		if (!db.empty()) {
			sum += db.back();
			db.pop_back();
		}
		dsum.push_front(sum % 10);
		carry = sum / 10;
	}
	
	for (int i = 0; i < dsum.size(); i++) {
		cout << dsum[i];
	}
	return 0;

}