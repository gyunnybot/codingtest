#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
int n, a[1000001], ret[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(&ret[0], &ret[0] + n, -1); //문제에서 요구하는 초기화

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		//Ai의 오큰수는 오른쪽에 있으면서(stack 활용) Ai보다 큰 수 중에서 가장 왼쪽에 있는 수(stk.top())를 의미한다
		while (!stk.empty() && a[stk.top()] < a[i]) {
			ret[stk.top()] = a[i];
			stk.pop();
		}
		
		stk.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}
