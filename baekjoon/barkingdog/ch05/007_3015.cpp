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

		int cnt = 1; //본인 포함 같은 키인 사람들의 수 계산하기

		while (!stk.empty() && stk.top().first <= h) { //stk.top()인 사람보다 크거나 같다면
			ret += stk.top().second; //stk.top()의 cnt만큼의 사람들을 현재 사람 또한 볼 수 있으므로 ret에 추가

			if (stk.top().first == h) { //만약 키가 정확히 같다면
				cnt += stk.top().second; //직전 사람의 cnt를 추가하여 본인의 cnt로 갱신
			}

			stk.pop(); //더 이전 사람과의 비교를 위해 pop
		}

		if (!stk.empty()) {
			ret++; //stk.top()이 본인보다 큰 경우, 가짓 수 추가(stk.top() 너머의 다른 사람은 볼 수 없으므로 1만 추가)
		}
		
		stk.push({ h, cnt }); //현재 키, 본인 포함 같은 키인 사람들의 수
	}

	cout << ret;

	return 0;
}
