#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    int r = 0;
    while (cin >> n) {
        vector<long long int> equation(n + 1, 0);
        vector<int> root;
        for (int x = 0; x < n; x ++) {
            cin >> r;
            root.push_back(r);
        }
        equation[1] = 1;
        equation[0] = -root[0];
        for (int y = 1; y < n ; ++y) {
            equation[y + 1] = 1;
            for (int x = y; x >= 0; --x) {
                if (x > 0) {
                    equation[x] = (-root[y]) * equation[x] + equation[x - 1];
                }
                else {
                    equation[x] = (-root[y]) * equation[x];
                }

            }
        }

        for (int x = n; x >= 0; --x) {
            if (x == n) {
                if (n == 1) {
                    cout << "x";
                }
                else {
                    cout << "x^" << x;
                }
            }
            else if (x >=2) {
                if (equation[x] > 1) {
                    cout << " + " << equation[x];
                }
                else if (equation[x] == 1) {
                    cout << " + ";
                }
                else if (equation[x] == -1) {
                    cout << " - ";
                }
                else if (equation[x] < 0) {
                    cout << " - " << abs(equation[x]);
                }
                if (equation[x]) {
                    cout << "x^" << x;
                }
            }
            else if (x == 1) {
                if (equation[x] > 1) {
                    cout << " + " << equation[x];
                }
                else if (equation[x] == 1) {
                    cout << " + ";
                }
                else if (equation[x] == -1) {
                    cout << " - ";
                }
                else if (equation[x] < 0) {
                    cout << " - " << abs(equation[x]);
                }
                if (equation[x]) {
                    cout << "x";
                }
            }
            else if(x == 0) {
                if (equation[x] >= 0) {
                    cout << " + " << equation[x];
                }
                else if (equation[x] < 0) {
                    cout << " - " << abs(equation[x]);
                }
            }
        }
        cout << " = 0\n";
    }
    return 0;
}
