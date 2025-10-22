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

	list<char>::iterator cur = L.end(); //가리키는 이터레이터 앞에 커서가 깜빡거린다고 가정

	while (n--) {
		cin >> ch;

		if (ch == 'P') {
			cin >> add;
			L.insert(cur, add); //insert(이터레이터, 값). cur 위치에 원소 추가 후 다음 이터레이터를 가리킴
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
				cur = L.erase(cur); //erase(이터레이터). cur에 위치한 원소 삭제 후 다음 이터레이터를 가리킴
			}
		}
	}

	for (char c : L) {
		cout << c;
	}

	return 0;
}
