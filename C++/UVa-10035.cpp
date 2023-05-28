#include <bits/stdc++.h>

using namespace std;
int main() {

    string n1, n2;
    while (cin >> n1 >> n2) {
        if (n1.size() == 1 && n2.size() == 1 && n1[0] == '0' && n2[0] == '0') {
            break;
        }

        int carry = 0;
        int r1 = n1.size() - 1;
        int r2 = n2.size() - 1;
        int ans = 0;

        while (r1 >= 0 || r2 >= 0 || carry > 0) {
            int num1 = 0;
            int num2 = 0;
            if (r1 >= 0) {
                num1 = n1[r1--] - '0';
            }
            if (r2 >= 0) {
                num2 = n2[r2--] - '0';
            }
            carry = (num1 + num2 + carry) / 10;
            if (carry) {
                ans += 1;
            }
        }

        if (ans) {
            if (ans == 1) {
                cout << "1 carry operation.\n";
            }
            else {
                cout << ans << " carry operations.\n";
            }
        }
        else {
            cout << "No carry operation.\n";
        }

    }
    return 0;
}
