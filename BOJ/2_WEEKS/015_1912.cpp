#include<iostream>
#include<climits> //INT_MIN
using namespace std;

int n, temp, s[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		s[i] = max(s[i - 1] + temp, temp);
	}

	int maxVal = INT_MIN;

	for (int i = 1; i <= n; i++) {
		maxVal = max(maxVal, s[i]);
	}

	cout << maxVal;

	return 0;
}
