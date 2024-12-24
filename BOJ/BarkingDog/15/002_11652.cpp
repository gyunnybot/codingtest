#include<iostream>
#include<algorithm> //sort
using namespace std;
typedef long long ll;

int n, ret;
ll a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	ll ret = a[0]; //가장 많이 나온 수 구하기. 첫번째 원소에서 시작해 순차적으로 비교 후 계산

	int maxVal = 1; //숫자 카드의 개수 N (1 ≤ N ≤ 100,000)
	int cnt = 1; //a[0]을 기준으로 잡아 1부터 시작

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}

		if (maxVal < cnt) {
			maxVal = cnt;
			ret = a[i];
		}
	}

	cout << ret;

	return 0;
}
