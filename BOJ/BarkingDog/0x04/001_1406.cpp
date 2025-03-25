#include<iostream>
#include<list>
using namespace std;

list<char> L;
string input_str;
char ch, add;
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input_str >> n;

	for (char c : input_str) {
		L.push_back(c);
	}

	list<char>::iterator cur = L.end();

	while (n--) {
		cin >> ch;

		if (ch == 'P') {
			cin >> add;
			L.insert(cur, add); //insert(이터레이터, 값). 수행 후 다음 이터레이터를 가리킨다
		}
		else if (ch == 'L') {
			if (cur != L.begin()) {
				cur--;
			}
		}
		else if (ch == 'D') {
			if (cur != L.end()) {
				cur++;
			}
		}
		else if (ch == 'B') {
			if (cur != L.begin()) {
				cur--;
				cur = L.erase(cur); //erase(이터레이터). 값은 삭제되어도 이터레이터 위치는 유지된다
			}
		}
	}

	for (char c : L) {
		cout << c;
	}

	return 0;
}
