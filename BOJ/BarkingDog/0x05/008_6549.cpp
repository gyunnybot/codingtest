#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, h, idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}

		stack<pair<ll, ll>> stk;
		ll ret = 0;

		for (int i = 0; i < n; i++) {
			cin >> h;

			idx = i;

			while (!stk.empty() && stk.top().first >= h) { //입력된 높이가 직전 높이보다 작다면 중간 검사 실행
				//직전 위치에서부터 만들 수 있는 직사각형을 역순으로 조사 후 최대값 갱신
				ret = max(ret, (i - stk.top().second) * stk.top().first);

				idx = stk.top().second;
				stk.pop();
			}

			stk.push({ h,idx });
		}

		while (!stk.empty()) { //마지막 기둥 검사
			ret = max(ret, (n - stk.top().second) * stk.top().first);
			stk.pop();
		}

		cout << ret << '\n';
	}

	return 0;
}
