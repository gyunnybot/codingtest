#include<iostream>
using namespace std;

int n, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	//백색 깃발이 위로 보이려면 깃발이 바뀌는 횟수가 홀수여야 한다
	//어떤 수의 제곱근이 정수라면 그 수에서 반드시 홀수 횟수를 가진다. 이는 또한 모든 경우의 수를 포함한다
	//제곱근이 정수면서 n 이하가 되는 수의 개수를 계산한다
	for (int i = 1; i * i <= n; i++) {
		ret++;
	}

	cout << ret;

	return 0;
}
