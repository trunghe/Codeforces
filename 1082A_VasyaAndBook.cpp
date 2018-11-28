#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
//#define FORD(i, a, b) \
//    for (int i = (a); i >= (b); i--)

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie();
//    freopen("A.in", "r", stdin);
//    freopen("A.out", "w", stdout);
//    freopen("A.err", "w", stderr);
    int noTcs, n, x, y, d;
    cin >> noTcs;
    FOR(i, 0, noTcs) {
        cin >> n >> x >> y >> d;
        if (abs(y - x) % d == 0) {
            cout << abs(y - x) / d << endl;
            continue;
        }
        if ((n - y) % d == 0 && (y - 1) % d == 0) {
            if (((n - x) + (n - y)) / d <= ((x - 1) + (y - 1)) / d) {
                cout << (n - y) / d + ceil((double(n) - double(x)) / double(d)) << endl;
                continue;
            }
            cout << (y - 1) / d + ceil((double(x) - 1) / double(d)) << endl;
            continue;
        }
        if ((n - y) % d == 0) {
            cout << (n - y) / d + ceil((double(n) - double(x)) / double(d)) << endl;
            continue;
        }
        if ((y - 1) % d == 0) {
            cout << (y - 1) / d + ceil((double(x) - 1) / double(d)) << endl;
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}
