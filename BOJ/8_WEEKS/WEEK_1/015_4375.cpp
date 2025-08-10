#include<iostream>
#include<string> //to_string
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n) {
		int ret = 1;
		int cnt = 1;

		while (true) {
			if (ret % n == 0) {
				cout << cnt << '\n';
				break;
			}
			else {
				ret = ret * 10 + 1;
				ret %= n; //mod 연산

				cnt++;
			}
		}
	}

	return 0;
}
