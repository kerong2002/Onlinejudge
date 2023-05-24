#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0, n = 0, p = 0, bar = 0;
    cin >> t;
    while (t--) {
        cin >> n >> p;

        vector<int> bar(p + 1, 0);
        for (int x = 1; x <= p; ++x) {
            cin >> bar[x];
        }

        vector<vector<int>> dp(p + 1, vector<int>(n + 1, 0));
        for (int y = 1; y <= p; ++y) {
            for (int x = 1; x <= n; ++x) {
                if (bar[y] > x) {
                    dp[y][x] = dp[y-1][x];
                }
                else {
                    dp[y][x] = max(dp[y-1][x], dp[y-1][x - bar[y]] + bar[y]);
                }
            }
        }
//        for (int y = 0; y <= p; ++y) {
//            for (int x = 0; x <= n; ++x) {
//                cout << dp[y][x] << " ";
//            }
//            cout << endl;
//        }
        cout << ((dp[p][n] == n) ? "YES\n" : "NO\n");

    }

    return 0;
}
/*
1
13
5
1 2 6 8 9
*/
