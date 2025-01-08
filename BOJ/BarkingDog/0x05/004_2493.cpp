#include<iostream>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;
int n, height;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	stk.push({ 100000001,0 }); //탑들의 높이는 1 이상 100,000,000 이하의 정수이다

	for (int i = 1; i <= n; i++) {
		cin >> height;

		while (!stk.empty() && stk.top().first <= height) {
			stk.pop();
		}

		cout << stk.top().second << ' '; //본인보다 높은 탑의 인덱스 출력

		stk.push({ height,i });
	}

	return 0;
}
