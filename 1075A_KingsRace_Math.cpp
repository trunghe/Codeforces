/*
 * https://codeforces.com/problemset/problem/1075/A
 * Category: Math
 * 
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);
    ll n, x, y;
    cin >> n >> x >> y;
    if (x + y > n + 1) {
        cout << "Black";
    } else {
        cout << "White";
    }
    cout << endl;

    return 0;
}
