#include<iostream>
#include<algorithm> //sort
using namespace std;

int n, cnt, a[51];

int getGCD(int a, int b) {
	if (a == 0) {
        return b;
    }
    
	return getGCD(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n - 1; i++) {
		if (getGCD(a[i], a[i + 1]) == 1) continue;

		for (int j = a[i] + 1; j < a[i + 1]; j++) {
			if (getGCD(a[i], j) == 1) {
				if (getGCD(j, a[i + 1]) == 1) {
					cnt++; // 1개의 수로 공약수열 완성
					break;
				}
			}

			//j가 끝에 도달했지만 공약수열이 완성되지 않는 경우
			if (j == a[i + 1] - 1) {
				cnt += 2; //https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}
