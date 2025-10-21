#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, m, temp;
vector<int> a, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;

		if (binary_search(a.begin(), a.end(), temp)) {
			ret.push_back(1);
		}
		else {
			ret.push_back(0);
		}
	}

	for (int i : ret) {
		cout << i << '\n';
	}

	return 0;
}
