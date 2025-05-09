#include<iostream>
using namespace std;
typedef long long ll;

int n;
ll s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		bool flag = true;

		for (int i = 2; i <= 1000000; i++) {
			if (s % i == 0) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
