#include <bits/stdc++.h>
using namespace std;

int main() {
	int a = 0, b = 0;

	while (cin >> a >> b) {
		int cnt = 0;
		cout << "[";

		if (!a || !b) {
            cout << "0";
		}

		while (a && b) {
			if (cnt == 0 ) {
				if (a >= b ) {
					cout << a/b;
					a = a - int(a / b) * b;
				}
				else {
					cout << "0";
				}
			}
			else {
                if (cnt == 1) {
                    cout << ";";
                }
				else if(cnt >= 2){
					cout << ",";
				}
				if (a >= b) {
					cout << a / b;
					a = a - int(a / b) * b;
				}
				else {
					cout << b / a;
					b = b - int(b / a) * a;
				}
			}
			cnt++;
		}
		cout << "]\n";
	}
	return 0;
}
