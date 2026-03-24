#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n;
	queue <int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	while (q.size()>1) {
		if (q.empty()) {
			cout<< "-1";
		}
		else {
			q.pop();

			int num = q.front();
			q.pop();
			q.push(num);
		}
	}

	cout<< q.front();
	return 0;
}

