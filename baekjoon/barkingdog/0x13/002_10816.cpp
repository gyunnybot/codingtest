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
		ret.push_back(upper_bound(a.begin(), a.end(), temp) - lower_bound(a.begin(), a.end(), temp));
	}

	for (int i : ret) {
		cout << i << ' ';
	}

	return 0;
}
