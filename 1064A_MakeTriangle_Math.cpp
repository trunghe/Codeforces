#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
        swap(a, b);
    }
    if (a > c) {
        swap(a, c);
    }
    if (b > c) {
        swap(b, c);
    }
//    cerr << a << " " << b << " " << c << endl;
    int diff = c - b - a;
    if (diff < 0) {
        cout << 0;
    } else {
        cout << diff + 1;
    }
    cout << endl;
    return 0;
}
