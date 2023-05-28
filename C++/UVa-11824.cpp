#include <bits/stdc++.h>

#define MAX_VALUE 5000000

using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	int L = 0;

	cin >> t;
	while (t--) {


		vector<int> line;
		while (true) {
			cin >> L;
			if (L == 0) {
				break;
			}
			line.push_back(L);
		}

		sort(line.begin(), line.end(), compare);
		int ans = 0;
		int bonus = 1;
		for (int x = 0; x < line.size(); ++x) {
            if (ans >= MAX_VALUE) {
                break;
            }
			ans += 2 * static_cast<int> (pow(line[x], bonus++));
		}

		if (ans < MAX_VALUE) {
			cout << ans << endl;
		}
		else {
			cout << "Too expensive" << endl;
		}

	}
	return 0;
}
