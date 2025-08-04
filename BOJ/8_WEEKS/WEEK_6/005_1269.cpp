#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> ump;
int n, m, temp, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		cin >> temp;

		ump[temp]++;
	}

	for (pair<int, int> i : ump) {
		if (i.second == 1) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
