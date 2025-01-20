#include<iostream>
#include<map>
using namespace std;

map<string, string> mp;
int n, m;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		mp[a] = b;
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		cout << mp[a] << '\n';
	}
	return 0;
}
