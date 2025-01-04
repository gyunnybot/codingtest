#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, a[1000001], x, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	cin >> x;

	//two pointer
	int l = 0;
	int r = n - 1;

	//ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수
	while (l < r) {
		if (a[l] + a[r] == x) {
			ret++;

			//n개의 서로 다른 양의 정수
			l++;
			r--;
		}
		else if (a[l] + a[r] < x) {
			l++;
		}
		else if (a[l] + a[r] > x) {
			r--;
		}
	}

	cout << ret;

	return 0;
}
