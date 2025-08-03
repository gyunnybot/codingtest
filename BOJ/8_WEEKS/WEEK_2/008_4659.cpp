#include<iostream>
using namespace std;

string s;

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> s) {
		if (s == "end") {
			break;
		}

		int vcnt = 0;
		int ccnt = 0;

		bool isIncludedVowel = 0;
		bool flag = 0;

		char prev = 0;

		for (char c : s) {
			if (isVowel(c)) {
				vcnt++;
				ccnt = 0;

				isIncludedVowel = true;
			}
			else {
				vcnt = 0;
				ccnt++;
			}

			if (vcnt == 3 || ccnt == 3) { //조건 2
				flag = true;
			}

			if (prev == c && c != 'e' && c != 'o') { //조건 3
				flag = true;
			}

			prev = c;
		}

		if (!isIncludedVowel) { //조건 1
			flag = true;
		}

		if (flag) {
			cout << "<" << s << "> is not acceptable.\n";
		}
		else {
			cout << "<" << s << "> is acceptable.\n";
		}
	}

	return 0;
}
