#include<iostream>
#include<algorithm> //sort
using namespace std;

int n;
string s[51];

int chk(string s) {
	int ret = 0;

	for (char c : s) {
		if ('0' <= c && c <= '9') {
			ret += c - '0';
		}
	}
	
	return ret;
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		if (chk(a) == chk(b)) {
			return a < b;
		}
		else {
			return chk(a) < chk(b);
		}
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}

	return 0;
}
