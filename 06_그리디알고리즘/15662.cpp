#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> gear(T);
    for (int i = 0; i < T; i++) {
        cin >> gear[i];
    }
    int K;
    cin >> K;
    while (K--) {
        int num, dir;
        cin >> num >> dir;
        num--;

        vector<int> d(T, 0);
        d[num] = dir;

        for (int i = num; i > 0; i--) {
            if (gear[i][6] != gear[i - 1][2]) {
                d[i - 1] = -d[i];
            }
            else {
                break;
            }
        }

        for (int i = num; i < T - 1; i++) {
            if (gear[i][2] != gear[i + 1][6]) {
                d[i + 1] = -d[i];
            }
            else {
                break;
            }
        }

        for (int i = 0; i < T; i++) {
            if (d[i] == 1) {
                char temp = gear[i][7];
                for (int j = 7; j > 0; j--) {
                    gear[i][j] = gear[i][j - 1];
                }
                gear[i][0] = temp;
            }
            else if (d[i] == -1) {
                char temp = gear[i][0];
                for (int j = 0; j < 7; j++) {
                    gear[i][j] = gear[i][j + 1];
                }
                gear[i][7] = temp;
            }
        }
    }
    int answer = 0;

    for (int i = 0; i < T; i++) {
        if (gear[i][0] == '1') answer++;
    }
    cout << answer;
    return 0;
}