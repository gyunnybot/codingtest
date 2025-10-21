#include<iostream>
#include<vector>
#include<algorithm> //sort
using namespace std;

const int dy[] = { -1,-1,-1,0,1,1,1,0 };
const int dx[] = { -1,0,1,1,1,0,-1,-1 };
int n, m, k, a[11][11], soil[11][11], x, y, z, ret;
vector<int> tree[11][11];

void spring_summer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tree[i][j].size()) {
                sort(tree[i][j].begin(), tree[i][j].end());

                vector<int> grown_tree;
                int dead_tree = 0;

                for (int tre : tree[i][j]) {
                    if (soil[i][j] >= tre) {
                        soil[i][j] -= tre;
                        grown_tree.push_back(tre + 1);
                    }
                    else {
                        dead_tree += (tre / 2);
                    }
                }

                tree[i][j] = grown_tree; //deep copy

                //summer
                soil[i][j] += dead_tree;
            }
        }
    }

    return;
}

void fall() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (tree[y][x].size()) {
                for (int tre : tree[y][x]) {
                    if (tre % 5 == 0) {
                        for (int dir = 0; dir < 8; dir++) {
                            int ny = y + dy[dir];
                            int nx = x + dx[dir];

                            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                            tree[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
    }

    return;
}

void winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soil[i][j] += a[i][j];
        }
    }

    return;
}

void check_trees() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += tree[i][j].size();
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soil[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> y >> x >> z;
        tree[y - 1][x - 1].push_back(z); //좌표 주의!
    }

    while (k--) {
        spring_summer();
        fall();
        winter();
    }

    check_trees();

    cout << ret;

    return 0;
}
