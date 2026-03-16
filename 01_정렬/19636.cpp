#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void diet(int w0, int i0, int i, int a, int d, int t, int& w1, int& w2, int& m2) {
    w1 = w0;
    w2 = w0;
    m2 = i0;
    int m1 = i0;

    for (int day = 0; day < d; day++) {
        w1 += (i - (m1 + a));
        w2 += (i - (m2 + a));

        int diff = i - (m2 + a);
        if (abs(diff) > t) {
            m2 += diff / 2;
        }
    }
}

int main() {
    int w0, i0, t;
    int d, i, a;
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    int w1, w2, m2;
    diet(w0, i0, i, a, d, t, w1, w2, m2);

    if (w1 <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << w1 << " " << i0 << "\n";
    }

    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet";
    }
    else {
        cout << w2 << " " << m2 << " ";
        if (m2 < i0) {
            cout << "YOYO";
        }
        else {
            cout << "NO";
        }
    }

    return 0;
}