#include<iostream>
using namespace std;

int n, m, a[1025][1025], s[1025][1025];
int a1, a2, b1, b2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a1 >> b1 >> a2 >> b2;
		cout << s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1] << '\n';
	}

	return 0;
}
