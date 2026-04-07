#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        bool found = false;
        for (int a = 3; a <= n / 2; a += 2) {
            if (isPrime[a] && isPrime[n - a]) {
                cout << n << " = " << a << " + " << n - a << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}