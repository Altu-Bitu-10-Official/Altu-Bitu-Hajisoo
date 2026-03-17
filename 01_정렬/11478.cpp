#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int check(string st) {
	set<string> s;
	int len = st.length();
	for (int i = 0; i < len; i++) {
		for (int j = len - i; j >= 1; j--) {
		for (int j = 1; j <= len - i; j++) {
			string substring = st.substr(i, j);
			s.insert(substring);
		}
	}
	return s.size();

}
int main() {
	string str;
	cin >> str;
	cout << check(str);

	return 0;
}
