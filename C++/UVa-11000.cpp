#include <bits/stdc++.h>
using namespace std;
void f(vector<long long int> &dp) {
    int cnt = 1;
    while (true) {
        if(dp[cnt] + dp[cnt - 1] > INT_MAX) {
            break;
        }
        dp.push_back(dp[cnt] + dp[cnt-1]);
        cnt += 1;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<long long int> dp(2, 1);
    f(dp);

    vector<long long int> ans(1, 0);
    for (int x = 0; x < dp.size(); ++x) {
        ans.push_back(dp[x] + ans[x]);
    }

    int n = 0;
    while (cin >> n) {
        if (n < 0) {
            break;
        }
        cout << ans[n] << " " << ans[n + 1] << endl;
    }
    return 0;
}
