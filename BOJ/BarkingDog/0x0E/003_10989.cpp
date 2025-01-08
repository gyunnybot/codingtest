#include<iostream>
using namespace std;

int n, temp, cnt[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		cnt[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (cnt[i]--) {
			cout << i << '\n';
		}
	}

	return 0;
}
