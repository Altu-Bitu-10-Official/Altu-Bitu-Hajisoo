#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	int n, s;
	cin >> n >> s;  

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int D = 0;

	for (int i = 0; i < n; i++) {
		int dis = abs(a[i] - s);
		D = gcd(D, dis);
	}

	cout << D;
	return 0;
}