#include<iostream>
#include<set>
using namespace std;

int n, ret;
string s;
set<char> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    int left = 0;
    int right = 0;

    st.insert(s[0]);

    while (left < s.size() && right < s.size()) {
        ret = max(ret, right - left + 1);

        if (st.size() <= n) {
            right++;

            if (right < s.size() && st.find(s[right]) == st.end()) {
                st.insert(s[right]); //오른쪽 인덱스의 문자를 st에 추가
            }
        }

        if (st.size() > n) {
            st.erase(s[left]);

            left++;
            right = left;

            st.clear();
            st.insert(s[left]); //새로 지정된 left, right에서 다시 시작
        }
    }

    cout << ret;

    return 0;
}
