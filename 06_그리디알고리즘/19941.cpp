#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long answer = v[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (answer % v[i] == 0) {
            continue;
        }
        else {
            answer = (answer / v[i] + 1) * v[i];
        }
    }

    cout << answer;
    return 0;
}