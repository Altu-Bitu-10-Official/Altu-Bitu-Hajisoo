#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	string st;


	while (true) {
		bool check = true;
		getline(cin, st);

		if (st == ".") {
			break;
		}
		stack<char> s;
		for (int i = 0; i < st.size(); i++) {
			if (st[i] == '(' || st[i] == '[' || st[i] == '{') {
				s.push(st[i]);
			}
			else if (st[i] == ')') {
				if (s.empty() || s.top() != '(') {
					check = false;
					break;

				}
				else {
					s.pop();
				}

			}
			else if (st[i] == ']') {
				if (s.empty() || s.top() != '[') {
					check = false;
					break;
				}
				else {
					s.pop();
				}

			}
			else if (st[i] == '}') {
				if (s.empty() || s.top() != '{') {
					check = false;
					break;
				}
				else {
					s.pop();
				}

			}
		}
		if (!s.empty()) {
			check = false;
		}
		if (check == true) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;

}