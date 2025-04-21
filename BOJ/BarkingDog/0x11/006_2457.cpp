#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, ret;
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

	int end_date = 301;

	if (flower[0].first > end_date) {
		cout << 0;
		return 0;
	}
	
	int i = 0;
	int temp_date = 0;

	while (end_date <= 1130) {
		bool flag = false;

		while (i < n && flower[i].first <= end_date) {
			if (temp_date < flower[i].second) {
				temp_date = flower[i].second;
				flag = true;
			}

			i++; //다음 꽃의 날짜 확인하기
		}

		if (flag) {
			end_date = temp_date;
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
