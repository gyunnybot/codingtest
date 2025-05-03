#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

int n;
string temp;
vector<string> v;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		reverse(temp.begin(), temp.end());

		//0 지우기. 입력되는 모든 원소가 양의 정수이므로 반드시 탈출
		while (true) {
			if (temp[0] == '0') {
				temp.erase(0, 1); //string.erase(시작 인덱스 번호, 지울 갯수)
			}
			else {
				break;
			}
		}

		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);

	for (string s : v) {
		cout << s << '\n';
	}

	return 0;
}
