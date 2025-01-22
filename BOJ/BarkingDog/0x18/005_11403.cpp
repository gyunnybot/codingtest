#include<iostream>
using namespace std;

int n, a[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][k] && a[k][j]) {
					a[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}