#include<iostream>
using namespace std;
typedef unsigned long long ll;

int n, a[1000001], leader, teammate;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; // 식당의 수

	for (int i = 0; i < n; i++) {
		cin >> a[i]; // 고객의 수
	}

	cin >> leader >> teammate; // 팀장 최대 할당량, 팀원 최대 할당량

	ll ret = n;
	
	for (int i = 0; i < n; i++) {
		if (a[i] <= leader) continue;

		a[i] -= leader;
		ret += a[i] / teammate;

		if (a[i] % teammate) ret += 1;
	}

	cout << ret;

	return 0;
}
