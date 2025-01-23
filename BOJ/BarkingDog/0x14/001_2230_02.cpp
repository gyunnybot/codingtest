#include<iostream>
#include<algorithm> //sort
#include<climits> //INT_MAX
using namespace std;

int n, m, a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int ret = INT_MAX;

	for (int i = 0; i < n; i++) {
		int target = a[i] + m;
		int idx = lower_bound(a, a + n, target) - a; //lower_bound : 찾는 값이 없다면 끼어들어갈 이터레이터 반환
		
		if (idx < n) {
			ret = min(ret, a[idx] - a[i]);
		}
	}

	cout << ret;

	return 0;
}