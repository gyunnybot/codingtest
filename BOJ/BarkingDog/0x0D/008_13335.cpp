#include<iostream>
#include<queue>
using namespace std;

int n, w, L, a[1001], ret;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> w >> L; //다리를 건너는 트럭의 수 n, 다리의 길이 w, 전체 하중 L

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int weight = 0;

	for (int i = 0; i < n; i++) {
		while (true) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}

			if (weight + a[i] <= L) { //여유가 된다면 탈출 후 i번째 트럭 입성
				break;
			}
			else { //여유가 되지 않으면 빈 칸으로 남긴 후 while문 진행. 여유가 생길 때까지 반복
				q.push(0);
				ret++;
			}			
		}

		q.push(a[i]);
		weight += a[i];

		ret++;
	}

	cout << ret + w; //마지막 트럭이 다리를 건너는 시간 w 추가

	return 0;
}