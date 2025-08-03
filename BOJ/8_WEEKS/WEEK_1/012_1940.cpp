#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, m, cnt, a[15001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//고유한 번호 a[i]는 10만 이하이므로, 두 개의 재료는 20만 이하여야 한다
	if (m > 200000) {
		cout << 0;
	}
	else {
		sort(a, a + n);

		//two pointer
		int st = 0; int ed = n - 1;

		while (st < ed) {
			int sum = a[st] + a[ed];

			if (sum == m) {
				cnt++;

				//각각 고유한 번호이므로 st, ed 모두 조절
				st++;
				ed--;
			}
			else if (sum > m) {
				ed--;
			}
			else {
				st++;
			}
		}

		cout << cnt;
	}

	return 0;
}
