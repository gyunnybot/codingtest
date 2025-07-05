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

    //레드-블랙 트리 자료구조 map. O(logN)
	for (int i = 0; i < m; i++) {
		cin >> temp;

		if (mp[temp]) {
            cout << 1 << ' ';
        }
		else {
            cout << 0 << ' ';
        }
	}

	return 0;
}
