#include<iostream>
#include<queue> //priority_queue
using namespace std;

int n, temp;
priority_queue<int, vector<int>, greater<int>> pq; //우선순위 큐는 오름차순(최소 힙)
//sort(a.begin(), a.end(), greater<int>()); //내림차순
//map<int, int, greater<>> mp; //내림차순
//set<int, greater<>> st; //내림차순

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> temp;
		pq.push(temp);
	}

	int ret = 0;

	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		ret += a + b;
		pq.push(a + b);
	}

	cout << ret;

	return 0;
}
