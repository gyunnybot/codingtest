#include<iostream>
#include<stack>
using namespace std;

int n, num;
string s;
stack<int> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		if (s == "push") {
			cin >> num;
			stk.push(num);
		}
		else if (s == "pop") {
			if (!stk.empty()) {
				cout << stk.top() << '\n';
				stk.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			cout << stk.size() << '\n';
		}
		else if (s == "empty") {
			if (!stk.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else if (s == "top") {
			if (!stk.empty()) {
				cout << stk.top() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}
