#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    int m = 0;
    while (cin >> n >> m) {
        bool not_true = false;
        vector<int> ans(1, n);
        if(n==0 || m==0 || m==1 || n<m) {
            cout << "Boring!" << endl;
            continue;
        }
        while (n > 1) {
            if (n % m != 0) {
                not_true = true;
                break;
            }
            n = n / m;
            ans.push_back(n);
        }
        if (not_true) {
            cout << "Boring!" << endl;
        }
        else {
            for (int x = 0; x < ans.size() - 1; ++x) {
                cout << ans[x] << " ";
            }
            cout << ans[ans.size() - 1] << endl;
        }
    }
    return 0;
}
