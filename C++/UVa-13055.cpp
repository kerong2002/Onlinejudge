#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    stack<string> s1;
    cin >> n;
    while (n--) {
        string line;
        cin >> line;
        if (line == "Test") {
            if (s1.size()) {
                cout << s1.top() << endl;
            }
            else {
                cout << "Not in a dream" << endl;
            }
        }
        else if (line == "Kick") {
            if(s1.size()) {
                s1.pop();
            }
        }
        else if (line == "Sleep") {
            cin >> line;
            s1.push(line);
        }
    }
    return 0;
}
