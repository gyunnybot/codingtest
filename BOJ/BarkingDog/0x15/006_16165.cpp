#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n, m, num;
string team, mem, temp;
map<string, string> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> team >> num;

		for (int j = 0; j < num; j++) {
			cin >> mem;
			mp[mem] = team;

		}
	}

	for (int i = 0; i < m; i++) {
		cin >> temp >> num;

		if (num == 0) {
			for (pair<string, string> i : mp) {
				if (i.second == temp) {
					cout << i.first << '\n';
				}
			}
		}
		else {
			cout << mp[temp] << '\n';
		}
	}
  
	return 0;
}
