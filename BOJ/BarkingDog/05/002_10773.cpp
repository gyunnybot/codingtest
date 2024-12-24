#include<iostream>
#include<stack>
using namespace std;

int k, n, ret;
stack<int> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	while (k--) {
		cin >> n;

		if (n == 0) {
			if (!stk.empty()) {
				stk.pop();
			}
		}
		else {
			stk.push(n);
		}
	}

	while (!stk.empty()) {
		ret += stk.top();
		stk.pop();
	}

	cout << ret;

	return 0;
}
