#include<iostream>
#include<algorithm> //reverse
using namespace std;

string s, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	temp = s;

	reverse(s.begin(), s.end());

	if (temp == s) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}
