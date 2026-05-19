#include<iostream>
#include<queue> 
#include<cstring>

using namespace std;

int board[20][20];

int dr[4] = { 0, 1, 1, -1 };
int dc[4] = { 1, 0, 1, 1 };

int main() {
    for (int r = 1; r <= 19; r++) {
        for (int c = 1; c <= 19; c++) {
            cin >> board[r][c];
        }
    }

    for (int r = 1; r <= 19; r++) {
        for (int c = 1; c <= 19; c++) {
            if (board[r][c] == 0) continue;

            int color = board[r][c];

            for (int d = 0; d < 4; d++) {
                int prevR = r - dr[d];
                int prevC = c - dc[d];

                if (prevR >= 1 && prevR <= 19 && prevC >= 1 && prevC <= 19) {
                    if (board[prevR][prevC] == color) continue;
                }

                int cnt = 1;
                int nr = r + dr[d];
                int nc = c + dc[d];

                while (nr >= 1 && nr <= 19 && nc >= 1 && nc <= 19) {
                    if (board[nr][nc] != color) break;

                    cnt++;
                    nr += dr[d];
                    nc += dc[d];
                }

                if (cnt == 5) {
                    cout << color << "\n";
                    cout << r << " " << c << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}