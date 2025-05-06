#include<iostream>
#include<map>
using namespace std;

int n;
string a, b;
map<string, string, greater<>> mp; //사전순의 역순 = 내림차순 greater<>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mp[a] = b;
	}

	for (pair<string, string> pi : mp) {
		if (pi.second == "enter") {
			cout << pi.first << '\n';
		}
	}

	return 0;
}
