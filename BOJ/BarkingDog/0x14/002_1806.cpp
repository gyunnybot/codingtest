#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, s, a[100001], sum;
int ret = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//컨테이너의 연결성(길이)이 중요할 때 사용되는 투 포인터 반복문 형식
	int ed = 0;

	for (int st = 0; st < n; st++) {
		while (ed <= n && sum < s) { //투 포인터: 범위를 꼼꼼히 살핀다
			sum += a[ed];
			ed++;
		}

		if (ed == n + 1) break;

		ret = min(ret, ed - st);
		sum -= a[st];
	}

	cout << (ret == INT_MAX ? 0 : ret);

	return 0;
}
