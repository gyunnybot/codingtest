#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int n, m, team_number, quiz_type;
string team, member, temp;
unordered_map<string, string> ump;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> team >> team_number;

		for (int j = 0; j < team_number; j++) {
			cin >> member;
			ump[member] = team;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> temp >> quiz_type;

		if (quiz_type == 0) { //temp가 팀 이름일 때
			for (pair<string, string> pi : ump) {
				if (pi.second == temp) {
					cout << pi.first << '\n'; //전체 팀원 출력
				}
			}
		}
		else { //temp가 멤버 이름일 때
			cout << ump[temp] << '\n'; //멤버가 속한 팀 이름 출력
		}
	}

	return 0;
}
