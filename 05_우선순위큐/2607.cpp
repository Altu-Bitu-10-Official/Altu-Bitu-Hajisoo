#include <iostream>
#include <queue>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;
    string first, word;
    cin >> first;

    int base[26] = { 0 };
    for (int i = 0; i < first.length(); i++) {
        base[first[i] - 'A']++;
    }
    for (int i = 1; i < n; i++) {

        cin >> word;
        int check[26] = { 0 };
        for (int j = 0; j < word.length(); j++) 
            check[word[j] - 'A']++; 
        int diff = 0;
        for (int j = 0; j < 26; j++)
            diff += abs(base[j] - check[j]);

        if (abs((int)first.length() - (int)word.length()) <= 1 && diff <= 2) {
            answer++;
        }
    }
    cout << answer;
    return 0;
}