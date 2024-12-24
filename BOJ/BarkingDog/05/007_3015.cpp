#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int n, h;
ll ret;
stack<pair<int, int>> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> h; //현재 키 입력

		int cnt = 1; //본인 포함 같은 키인 사람들의 수

		while (!stk.empty() && stk.top().first <= h) { //스택에 저장된 키보다 크다면(직전 사람부터 역순으로 계산)
			ret += stk.top().second; //직전 사람들의 cnt만큼의 사람들을 현재 사람도 볼 수 있으므로 가짓 수 추가

			if (stk.top().first == h) { //키가 정확히 같다면
				cnt += stk.top().second; //현재 본인의 cnt에 스택 cnt를 추가하여 갱신
			}

			stk.pop(); //더 이전 사람과의 비교를 위해 pop
		}

		if (!stk.empty()) {
			ret++;
		}

		stk.push({ h, cnt }); //현재 키, 본인 포함 같은 키인 사람들의 수
	}

	cout << ret;

	return 0;
}
