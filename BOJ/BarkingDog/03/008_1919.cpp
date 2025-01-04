#include<iostream>
#include<cmath> //abs
using namespace std;

int n, ret, cnt_a[28], cnt_b[28];
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (char c : a) {
		cnt_a[c - 'a']++;
	}

	for (char c : b) {
		cnt_b[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		ret += abs(cnt_a[i] - cnt_b[i]);
	}

	cout << ret;

	return 0;
}
