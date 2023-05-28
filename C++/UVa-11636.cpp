#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    int t = 1;
    while (cin >> n) {
        if (n <= 0) {
            break;
        }
        cout << "Case " << t++ << ": ";
        cout << ceil(log(n) / log(2)) << endl;
    }
    return 0;
}
