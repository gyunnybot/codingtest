#include<iostream>
using namespace std;

int	n, m;
bool chae[1000001];

void era(int num) {
	chae[0] = false;
	chae[1] = false;

	for (int i = 2; i <= num; i++) {
		chae[i] = true;
	}

	for (int i = 2; i <= num; i++) {
		if (!chae[i]) continue;

		for (int j = i + i; j <= num; j += i) {
			chae[j] = false;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	era(1000000); //(1 ≤ M ≤ N ≤ 1,000,000)

	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		if (chae[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}