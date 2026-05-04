#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K
    string table;
    cin >> table;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (table[i] == 'P') {
            int start = i - K;
            int end = i + K;

            if (start < 0) start = 0;
            if (end >= N) end = N - 1;

            for (int j = start; j <= end; j++) {
                if (table[j] == 'H') {
                    table[j] = 'X';
                    answer++;
                    break;
                }
            }
        }
    }
    cout << answer;
    return 0;
}