#include<iostream>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;
int n, height;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	stk.push({ 100000001,0 }); //높이가 1억인 가상의 0번 탑 설정

	for (int i = 1; i <= n; i++) {
		cin >> height;

		while (!stk.empty() && stk.top().first <= height) {
			stk.pop();
		}

		cout << stk.top().second << ' ';

		stk.push({ height,i });
	}

	return 0;
}
