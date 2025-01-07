#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x = n;

	for (int i = 2; i * i <= n; i++) {
		while (x % i == 0) {
			cout << i << '\n';
			x /= i;
		}
	}
	if (x != 1){
        cout << x << '\n'; //유일하게 sqrt(n)보다 큰 소인수가 있다면 출력
    }

	return 0;
}