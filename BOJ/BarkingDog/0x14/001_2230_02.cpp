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
		int idx = lower_bound(a, a + n, target) - a; //찾는 값이 없다면 본인이 끼어들어갈(배열의 삽입) 인덱스를 가리킴
		
		if (idx < n) {
			ret = min(ret, a[idx] - a[i]);
		}
	}

	cout << ret;

	return 0;
}