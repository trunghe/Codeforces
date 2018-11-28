#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
//#define FORD(i, a, b) \
//    for (int i = (a); i >= (b); i--)

vector<int> segmentG;
vector<int> segmentS;
int n;
int maxSingleG = 0, maxDoubleG = 0;

void input() {
    int countG = 0, countS = 0;
    bool countingG = true;
    bool countedFirstG = false;
    bool doublingG = false;
    cin >> n;
    char ch;
    FOR(i, 0, n) {
        cin >> ch;
        if (countingG) {
            if (ch == 'G') {
                countedFirstG = true;
                countG++;
            } else if (countedFirstG) {

                if (doublingG) {
                    maxDoubleG = max(maxDoubleG, segmentG[segmentG.size() - 1] + countG);
                    doublingG = false;
                }

                segmentG.emplace_back(countG);
                maxSingleG = max(maxSingleG, countG);
                countG = 0;
                countingG = false;
                countS++;
            }
        } else if (countedFirstG) {// countingS
            if (ch == 'S') {
                countS++;
            } else {
                segmentS.emplace_back(countS);
                if (countS == 1) {
                    doublingG = true;
                }
                countS = 0;
                countingG = true;
                countG++;
            }
        }
    }
    if (countingG && countG > 0) {
        if (doublingG) {
            maxDoubleG = max(maxDoubleG, segmentG[segmentG.size() - 1] + countG);
        }

        segmentG.emplace_back(countG);
        maxSingleG = max(maxSingleG, countG);
    }
}

//void test() {
//    FOR(i, 0, segmentG.size()) {
//        cerr << segmentG[i] << "G";
//        if (i < segmentS.size()) {
//            cerr << segmentS[i] << "S";
//        }
//    }
//    cerr << endl << endl;
//    cerr << "maxSingleG = " << maxSingleG << endl;
//    cerr << "maxDoubleG = " << maxDoubleG << endl;
//}

void solve() {
    if (segmentG.size() < 2) {
        cout << maxSingleG << endl;
        return;
    }
    if (segmentG.size() == 2) {
        cout << max(maxSingleG + 1, maxDoubleG);
        return;
    }
    // segmentG.size() > 2
    cout << max(maxSingleG, maxDoubleG) + 1 << endl;
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie();
//    freopen("B.in", "r", stdin);
//    freopen("B.out", "w", stdout);
//    freopen("B.err", "w", stderr);

    input();
//    test();
    solve();


    return 0;
}
