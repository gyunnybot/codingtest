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

		multiset<int> ms; //같은 데이터를 중복해서 받아야 하며, 정렬된 상태를 유지해 최대, 최솟값을 추출할 수 있어야 함

		while (k--) {
			cin >> oper >> num;

			if (oper == 'D') {
				if (ms.empty()) continue;

				if (num == 1) {
					ms.erase(prev(ms.end())); //multiset의 erase는 인덱스가 아닌 이터레이터를 인자로 사용한다
				}
				else {
					ms.erase(ms.begin());
				}
			}
			else {
				ms.insert(num); //insert(원소 값)
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