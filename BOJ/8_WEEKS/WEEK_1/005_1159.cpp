#include<iostream>
#include<algorithm> //reverse
using namespace std;

string s, ret;
int n, cnt[26];
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> s;

		cnt[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			ret += (char)(i + 97);

			flag = true;
		}
	}

	if (flag) {
		cout << ret;
	}
	else {
		cout << "PREDAJA";
	}

	return 0;
}
