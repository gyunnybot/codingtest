#include<iostream>
using namespace std;

int n, k, comb[1001][1001];
int mod = 10007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//파스칼의 법칙을 활용해 가능한 모든 조합 결과를 배열에 저장한다. N <= 1000이므로 통과
	for (int n = 1; n <= 1000; n++) {
		comb[n][0] = 1; //nC0 = 1
		comb[n][n] = 1; //nCn = 1

		for (int k = 1; k < n; k++) { //nCk = n-1Ck-1 + n-1Ck
			comb[n][k] = (comb[n - 1][k - 1] + comb[n - 1][k]);
			comb[n][k] %= mod;
		}
	}

	cin >> n >> k;

	cout << comb[n][k];

	return 0;
}