#include<iostream>
#include<deque>
using namespace std;

int n, val;
string s;
deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;

		if (s == "push_front") {
			cin >> val;
			dq.push_front(val);
		}
		else if (s == "push_back") {
			cin >> val;
			dq.push_back(val);
		}
		else if (s == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			cout << dq.size() << '\n';
		}
		else if (s == "empty") {
			if (dq.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (s == "front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}
