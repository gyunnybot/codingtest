#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n;
vector<pair<int, int>> flower;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		flower.push_back({ a * 100 + b,c * 100 + d });
	}

	sort(flower.begin(), flower.end());

	int date = 301;
	int temp = 0;
	int ret = 0;
	int i = -1;
	bool flag = false;

	while (date <= 1130 && i < n) {
		flag = false;
		i++;

		for (int j = i; j < n; j++) {
			if (flower[j].first > date) {
				break;
			}

			if (temp < flower[j].second) {
				temp = flower[j].second;
				flag = true;
				i = j;
			}
		}

		if (flag) {
			date = temp;
			ret++;
		}
		else {
			cout << 0;
			return 0;
		}
	}

	cout << ret;

	return 0;
}
