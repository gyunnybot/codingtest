#include<iostream>
#include<unordered_map>
using namespace std;

int n, m, temp;
unordered_map<int, int> ump;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		ump[temp]++;
	}

	cin >> m;

    //해시 테이블 기반의 자료구조 unordered_map. 최선 O(1), 최악 O(N)
	for (int i = 0; i < m; i++) {
		cin >> temp;

		if (ump[temp]) {
            cout << 1 << ' ';
        }
		else {
            cout << 0 << ' ';
        }
	}

	return 0;
}
