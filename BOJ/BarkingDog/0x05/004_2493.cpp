#include<iostream>
#include<stack>
using namespace std;

int n, height[500001], ret[500001];
stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}

	stk.push({ 100000000,0 });

	for (int i = 1; i <= n; i++) {
		while (!stk.empty() && stk.top().first < height[i]) {
			stk.pop();
		}

		ret[i] = stk.top().second;
		stk.push({ height[i],i });
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}
