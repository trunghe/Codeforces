#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
//#define FORD(i, a, b) \
//    for (int i = (a); i >= (b); i--)

bool compareVi(vi v1, vi v2) {
    return v1.size() > v2.size();
}

bool compareInt(int i1, int i2) {
    return i1 > i2;
}

//void test(vvi lists) {
//    FOR(i, 0, lists.size()) {
//        cerr << "Subject " << i << ":";
//        FOR(j, 0, lists[i].size()) {
//            cerr << " " << lists[i][j];
//        }
//        cerr << endl;
//    }
//
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("C.in", "r", stdin);
//    freopen("C.out", "w", stdout);
//    freopen("C.err", "w", stderr);

    int n, m;
    cin >> n >> m;
    vvi listsBySubject(m);
    FOR(i, 0, n) {
        int subjectId;
        cin >> subjectId;
        int r;
        cin >> r;
        listsBySubject[subjectId - 1].emplace_back(r);
    }
    int maxSubject = 1;
    FOR(i, 0, m) {
        sort(listsBySubject[i].begin(),
             listsBySubject[i].end(), compareInt);
        maxSubject = max(maxSubject, (int) listsBySubject[i].size());
    }
    sort(listsBySubject.begin(), listsBySubject.end(), compareVi);

//    test(listsBySubject);

    int maxSum = 0;
    int sum[m];
    FOR(i, 0, m) {
        sum[i] = 0;
    }
    FOR(i, 0, maxSubject) {
        int maxCurrentSum = 0;
        FOR(k, 0, m) {
            if (i < listsBySubject[k].size()) {
                sum[k] += listsBySubject[k][i];
                maxCurrentSum = max(maxCurrentSum, maxCurrentSum + sum[k]);
            } else {
                break;
            }
        }
        maxSum = max(maxSum, maxCurrentSum);
    }
    cout << maxSum << endl;
    return 0;
}
