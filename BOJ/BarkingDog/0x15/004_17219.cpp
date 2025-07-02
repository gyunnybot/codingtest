#include<iostream>
#include<unordered_map>
using namespace std;

int n, m;
string a, b;
unordered_map<string, string> ump;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ump[a] = b;
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		cout << ump[a] << '\n';
	}

	return 0;
}
