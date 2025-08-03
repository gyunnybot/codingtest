#include<iostream>
using namespace std;

string s, mid, ret;
int cnt[26], flag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (char c : s) {
		cnt[c - 'A']++;
	}

	for (char i = 'Z'; i >= 'A'; i--) {
		if (cnt[i - 'A'] % 2) {
			mid = i; //중앙에 올 알파벳 확정
			
			cnt[i - 'A']--;

			flag++;
		}

		if (flag >= 2) break; //중앙에 와야하는 알파벳이 두 개 이상이라면

		for (int j = 0; j < cnt[i - 'A']; j += 2) {			
			ret = i + ret;
			ret = ret + i;
		}
	}

	if (mid.size()) {
		ret.insert(ret.size() / 2, mid); //string.insert(삽입할 위치의 인덱스, 문자열)
	}

	if (flag >= 2) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		cout << ret;
	}

	return 0;
}
