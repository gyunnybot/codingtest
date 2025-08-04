#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;
int n, a[1000001], ret[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(&ret[0], &ret[0] + n, -1);

	for (int i = 0; i < n; i++) {
		cin >> a[i];

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
