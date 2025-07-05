#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, s, b;
int ret = INT_MAX;
vector<pair<int, int>> ingre;

void recur(int idx, int sour, int bitter, int used) {
	if (idx == n) {
		if (used > 0) {
			ret = min(ret, abs(sour - bitter));
		}

		return;
	}

	recur(idx + 1, sour * ingre[idx].first, bitter + ingre[idx].second, used + 1);
	recur(idx + 1, sour, bitter, used);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> b;
		ingre.push_back({ s,b });
	}

	recur(0, 1, 0, 0); //신 맛은 곱 연산이므로 1로 초기화

	cout << ret;

	return 0;
}
