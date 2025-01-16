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

	for (int i = n - 1; i > 0; i--) { //k번째 수가 최대가 되도록 하는 것이 목적이므로 역순으로 탐색
		for (int j = 0; j < i; j++) {
			if (binary_search(b.begin(), b.end(), a[i] - a[j])) {
				cout << a[i]; //a[i]는 k번째 수의 최댓값이 된다
				return 0;
			}
		}
	}

	return 0;
}