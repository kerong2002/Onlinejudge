#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    int from = 0;
    int to = 0;

    while (cin >> line >> from >> to) {
        long long int number = 0;
        int bonus = 1;

        for (int x = line.size()-1; x >= 0; --x) {
            if (line[x] >= '0' && line[x] <= '9') {
                number += bonus * (line[x]-'0');
            }
            else if(line[x] >= 'A' && line[x] <= 'F') {
                number += bonus * (line[x]-'A' + 10);
            }
            bonus *= from;
        }

        if (number == 0) {
            cout << setw(7) << 0 << endl;
            continue;
        }

        vector<char> ans;
        int take = 0;
        while (number) {
            take = number % to;
            if(take >= 10) {
                ans.push_back(take - 10 + 'A');
            }
            else {
                ans.push_back(take + '0');
            }
            number /= to;
        }

        if (ans.size() > 7) {
            cout << setw(7) << "ERROR" << endl;
        }
        else {
            for (int x = ans.size(); x<7; ++x) {
                cout << " ";
            }
            for (int x = ans.size() - 1; x>=0; --x){
                cout << ans[x];
            }
            cout << endl;
        }
    }
    return 0;
}
