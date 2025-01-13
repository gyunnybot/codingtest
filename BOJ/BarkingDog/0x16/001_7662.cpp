#include<iostream>
#include<set> //multiset
using namespace std;

int t, k, num;
char oper;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> k;

		multiset<int> ms;

		while (k--) {
			cin >> oper >> num;

			if (oper == 'D') {
				if (ms.empty()) continue;

				if (num == 1) {
					ms.erase(prev(ms.end())); //multiset의 erase는 인덱스가 아닌 이터레이터가 필요하다
				}
				else {
					ms.erase(ms.begin());
				}
			}
			else {
				ms.insert(num);
			}
		}

		if (!ms.empty()) {
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
		}
		else {
			cout << "EMPTY" << '\n';
		}
	}

	return 0;
}