#include<iostream>
#include<deque>
using namespace std;

int n, m, cnt, val, pos;
deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	for (int i = 0; i < m; i++) {
		cin >> val;

		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == val) {
				pos = j;
				break;
			}
		}

		if (pos <= dq.size() / 2) {
			while (val != dq.front()) {
				dq.push_back(dq.front());
				dq.pop_front();

				cnt++;
			}

			dq.pop_front();
		}
		else {
			while (val != dq.front()) {
				dq.push_front(dq.back());
				dq.pop_back();

				cnt++;
			}

			dq.pop_front();
		}
	}

	cout << cnt;

	return 0;
}
