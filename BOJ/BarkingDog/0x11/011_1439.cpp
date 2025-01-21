#include<iostream>
using namespace std;

string s;
int ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	char temp = s[0];

	for (int i = 1; i < s.size(); i++) {
		if (temp != s[i]) {
			ret++;
			temp = s[i];
		}
	}

	cout << (ret + 1) / 2;
  
	return 0;
}
