#include <bits/stdc++.h>
using namespace std;

int main() {
	int row = 0;
	int col = 0;
	int t = 0;
	while (cin >> row >> col) {
		if (!row && !col ) {
			break;
		}
        if (t) {
            cout << endl;
        }
        cout << "Spreadsheet #" << ++t << endl;

		vector<vector<int>> graph(row, vector<int>(col, 0));
		for (int y = 0; y < row; ++y) {
			for (int x = 0; x < col; ++x) {
				graph[y][x] = y * col + x;
			}
		}

		int op_time = 0;
		int run_time = 0;
		int run_number = 0;
		int c1 = 0, c2 = 0, r1 = 0, r2 = 0;
		cin >> op_time;
		string operation;
		while (op_time--) {
			cin >> operation;
			if (operation == "DR") {
				cin >> run_time;

				vector<int> DR;
				for (int y = 0; y < run_time; ++y) {
                    cin >> run_number;
                    DR.push_back(run_number);
				}
                sort(DR.begin(), DR.end());

				for (int x = run_time - 1; x >= 0; --x) {
					graph.erase(graph.begin() + DR[x] - 1);
				}
			}
			else if (operation == "DC") {
				cin >> run_time;
				vector<int> DC;
				for (int y = 0; y < run_time; ++y) {
                    cin >> run_number;
                    DC.push_back(run_number);
				}
				sort(DC.begin(), DC.end());

				for (int x = run_time - 1; x >= 0; --x) {
					for (int y = 0; y < graph.size(); ++y) {
						graph[y].erase(graph[y].begin() + DC[x] - 1);
					}
				}
			}
			else if (operation == "IR") {
				cin >> run_time;
				vector<int> IR;
				for (int y = 0; y < run_time; ++y) {
                    cin >> run_number;
                    IR.push_back(run_number);
				}
				sort(IR.begin(), IR.end());

				for (int x = run_time - 1; x >= 0; --x) {
					graph.insert(graph.begin() + IR[x] - 1, vector<int>(graph[0].size(), -1));
				}
			}
			else if (operation == "IC") {
				cin >> run_time;
				vector<int> IC;
				for (int y = 0; y < run_time; ++y) {
                    cin >> run_number;
                    IC.push_back(run_number);
				}
                sort(IC.begin(), IC.end());

				for (int x = run_time - 1; x >= 0; --x) {
					for (int y = 0; y < graph.size(); ++y){
                        graph[y].insert(graph[y].begin() + IC[x]- 1, -1);
					}
				}
			}
			else if (operation == "EX") {
                cin >> r1 >> c1 >> r2 >> c2;
                swap(graph[r1-1][c1-1], graph[r2-1][c2-1]);
			}
		}

		cin >> op_time;
		while (op_time--) {
            cin >> r1 >> c1;
            int key = (r1 - 1) * col + c1 - 1;
            bool find_key = false;
            for (int y = 0; y < graph.size(); ++y) {
                for (int x = 0; x < graph[0].size(); ++x) {
                    if (graph[y][x] == key) {
                        find_key = true;
                        r2 = y;
                        c2 = x;
                    }
                }
            }
            cout << "Cell data in (" << r1 << "," << c1 << ") ";
            if (find_key) {
                cout << "moved to (" << r2 + 1 << "," << c2 + 1 << ")" << endl;
            }
            else {
                cout << "GONE" << endl;
            }
		}
	}

	return 0;
}
