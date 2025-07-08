#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;
    int w = 0;

    for (int i = 0; i < truck_weights.size(); i++) {
        while (true) {
            if (q.size() == bridge_length) {
                w -= q.front();
                q.pop();
            }

            if (w + truck_weights[i] <= weight) {
                break;
            }
            else {
                q.push(0);
                answer++;
            }
        }

        w += truck_weights[i];

        q.push(truck_weights[i]);
        answer++;
    }

    return answer + bridge_length;
}
