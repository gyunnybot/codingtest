#include<iostream>
#include<stack>
using namespace std;

string s;
int n, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;

		stack<int> stk;

		for (char c : s) {
			if (stk.empty()) {
				stk.push(c);
			}
			else {
				if (stk.top() == c) {
					stk.pop();
				}
				else {
					stk.push(c);
				}
			}
		}

		if (stk.empty()) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
