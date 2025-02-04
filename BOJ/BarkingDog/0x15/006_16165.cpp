#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n, m, team_number, quiz_type;
string team, member, temp;
map<string, string> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> team >> team_number;

		for (int j = 0; j < team_number; j++) {
			cin >> member;
			mp[member] = team;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> temp >> quiz_type;

		if (quiz_type == 0) { //temp가 팀 이름일 때
			for (pair<string, string> pi : mp) {
				if (pi.second == temp) {
					cout << pi.first << '\n'; //팀원들 전부 출력
				}
			}
		}
		else { //temp가 멤버 이름일 때
			cout << mp[temp] << '\n'; //멤버가 속한 팀 이름 출력
		}
	}

	return 0;
}
