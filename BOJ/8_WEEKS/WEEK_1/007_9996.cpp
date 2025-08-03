#include<iostream>
using namespace std;

string pattern, pre, post, s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> pattern;

	pre = pattern.substr(0, pattern.find("*")); //string.substr(시작 인덱스, 추출할 문자 개수)
	post = pattern.substr(pattern.find("*") + 1); //string.substr(시작 인덱스) : 시작 인덱스부터 끝까지 반환

	while (n--) {
		cin >> s;

		if (s.size() < pre.size() + post.size()) {
			cout << "NE" << '\n';
		}
		else {
			if (s.substr(0, pre.size()) == pre && s.substr(s.size() - post.size()) == post) {
				cout << "DA" << '\n';
			}
			else {
				cout << "NE" << '\n';
			}
		}
	}

	return 0;
}
