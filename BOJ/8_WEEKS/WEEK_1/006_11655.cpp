#include<iostream>
#include<string> //getline
using namespace std;

string s, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/**
	 * cin >> s; //hello world!를 입력했다면 s에는 hello만 저장되고, 입력 버퍼에 " world\n" 저장
	 * getline(cin, s); //s에는 hello world!가 저장되고, 입력 버퍼는 비어있다
	 */
	getline(cin, s); //공백을 포함한 문자열 입력. 개행마저 모조리 읽은 후 개행 직전까지의 문자열을 s에 저장한다
	
	for (char c : s) {
		if ('a' <= c && c <= 'z') {
			if (c + 13 > 'z') {
				c -= 13;
			}
			else {
				c += 13;
			}
		}
		else if ('A' <= c && c <= 'Z') {
			if (c + 13 > 'Z') {
				c -= 13;
			}
			else {
				c += 13;
			}
		}

		ret += c;
	}

	cout << ret;

	return 0;
}
