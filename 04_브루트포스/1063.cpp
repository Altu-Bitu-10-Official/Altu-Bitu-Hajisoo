#include <iostream>
using namespace std;

void ChangeL(string st, char& c, int& r) {
    char bc = c;
    int br = r;

    if (st == "R") {
        bc++;
    }
    else if (st == "L") {
        bc--;
    }
    else if (st == "B") {
        br--;
    }
    else if (st == "T") {
        br++;
    }
    else if (st == "RT") {
        bc++;
        br++;
    }
    else if (st == "LT") {
        bc--;
        br++;
    }
    else if (st == "RB") {
        bc++;
        br--;
    }
    else if (st == "LB") {
        bc--;
        br--;
    }

    if (bc >= 'A' && bc <= 'H' && br >= 1 && br <= 8) {
        c = bc;
        r = br;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char kc, sc;
    int kr, sr;
    int n;
    string move;

    cin >> kc >> kr >> sc >> sr >> n;

    while (n--) {
        cin >> move;

        char nkc = kc;
        int nkr = kr;
        ChangeL(move, nkc, nkr);

        if (nkc == kc && nkr == kr) {
            continue;
        }

        if (nkc == sc && nkr == sr) {
            char nsc = sc;
            int nsr = sr;
            ChangeL(move, nsc, nsr);

            if (nsc == sc && nsr == sr) {
                continue;
            }

            kc = nkc;
            kr = nkr;
            sc = nsc;
            sr = nsr;
        }
        else {
            kc = nkc;
            kr = nkr;
        }
    }

    cout << kc << kr << "\n" << sc << sr;
    return 0;
}