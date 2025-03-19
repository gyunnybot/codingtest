#include<iostream>
#include<climits> //INT_MAX
using namespace std;

int n, h, temp, a[500001], s[500001], ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> h;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (i % 2 == 0) {
			a[1]++;
			a[temp + 1]--;
		}
		else {
			a[h - temp + 1]++;
		}
	}

	for (int i = 1; i <= h; i++) {
		s[i] = s[i - 1] + a[i];
	}

	int minVal = INT_MAX;

	for (int i = 1; i <= h; i++) {
		minVal = min(minVal, s[i]);
	}

	for (int i = 1; i <= h; i++) {
		if (s[i] == minVal) {
            ret++;
        }
	}

	cout << minVal << ' ' << ret;

	return 0;
}
