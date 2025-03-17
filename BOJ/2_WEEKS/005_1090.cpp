#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n, x, y;
vector<int> xpos, ypos;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		xpos.push_back(x);
		ypos.push_back(y);
		v.push_back({ x,y });
	}

	vector<int> ret(n, -1); //계산 후 거리가 0이 나오는 경우와 구분하기 위해 -1로 초기화

	for (int x : xpos) {
		for (int y : ypos) {
			vector<int> dist;

			for (pair<int, int> i : v) {
				int d = abs(i.first - x) + abs(i.second - y);
				dist.push_back(d);
			}

			sort(dist.begin(), dist.end());

			int temp = 0;

			for (int i = 0; i < n; i++) {
				temp += dist[i];

				if (ret[i] == -1) {
					ret[i] = temp;
				}
				else {
					ret[i] = min(ret[i], temp);
				}
			}
		}
	}

	for (int i : ret) {
		cout << i << ' ';
	}

	return 0;
}
