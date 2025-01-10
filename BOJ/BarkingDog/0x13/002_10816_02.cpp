#include<iostream>
#include<map>
using namespace std;

int n, m, temp;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		mp[temp]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;

		if (mp[temp]) {
            cout << mp[temp] << ' ';
        }
		else {
            cout << 0 << ' ';
        }
	}

	return 0;
}