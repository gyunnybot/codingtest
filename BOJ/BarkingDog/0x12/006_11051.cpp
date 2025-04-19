#include<iostream>
using namespace std;

int n, k, comb[1001][1001];
int mod = 10007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//N <= 1000이므로 파스칼의 법칙을 활용하면 가능한 모든 조합을 배열로 완성할 수 있다
	for (int n = 1; n <= 1000; n++) {
		comb[n][0] = 1; //nC0 = 1
		comb[n][n] = 1; //nCn = 1

		for (int k = 1; k < n; k++) {
			comb[n][k] = (comb[n - 1][k] + comb[n - 1][k - 1]);
			comb[n][k] %= mod;
		}
	}

	cin >> n >> k;

	cout << comb[n][k];

	return 0;
}