#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int now = 0;
    vector<char> wheel(n, '?');
    vector<bool> chk(26, false);
    bool flag = true;

    for (int i = 0; i < k; i++) {
        int s;
        char c;
        cin >> s >> c;

        now = (now - (s % n) + n) % n;

        if (wheel[now] == '?') {
            if (chk[c - 'A']) {
                flag = false;
            }
            else {
                wheel[now] = c;
                chk[c - 'A'] = true;
            }
        }
        else {
            if (wheel[now] != c) {
                flag = false;
            }
        }

        if (flag == false) {
            cout << "!";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << wheel[(now + i) % n];
    }

    return 0;
}