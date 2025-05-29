#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

class cmp {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }

            return a.second > b.second;
        }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int solution(vector<vector<int>> jobs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    sort(jobs.begin(), jobs.end()); //시작 시간 순으로 정렬

    int idx = 0;
    int t = 0;

    while (idx < jobs.size() || !pq.empty()) {
        while (idx < jobs.size() && jobs[idx][0] <= t) {
            pq.push({ jobs[idx][0], jobs[idx][1] });
            idx++;
        }

        if (!pq.empty()) {
            pair<int, int> cur = pq.top(); pq.pop();

            t += cur.second;
            answer += t - cur.first;
        }
        else {
            t = jobs[idx][0];
        }
    }

    answer /= jobs.size();

    return answer;
}
