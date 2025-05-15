#include <string>
#include <vector>
#include <queue> //priority_queue
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; //pq greater = 최소 힙
int temp;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int sc : scoville) {
        pq.push(sc);
    }
    
    while(!pq.empty() && pq.top() < K){
        if(pq.size() >= 2){
            temp = pq.top(); pq.pop();        
            temp += 2 * pq.top(); pq.pop();
            
            pq.push(temp);

            answer++;
        }
        else{
            answer = -1;
            break;
        }
    }
    
    return answer;
}
