#include<iostream>
#include<algorithm> //sort
#include<vector>
using namespace std;

int n, a[1001];
vector<int> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			b.push_back(a[i] + a[j]);
		}
	}

	sort(b.begin(), b.end());

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(b.begin(), b.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}

	return 0;
}