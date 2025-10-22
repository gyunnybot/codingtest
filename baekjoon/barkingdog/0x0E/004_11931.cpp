#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}

	return 0;
}
