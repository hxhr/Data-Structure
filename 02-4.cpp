#include <iostream>
#include <vector>
#include <queue>
using namespace std;





//我真是无语了。。。有一个测试用例一直看错了，其实早就写对了，又在这浪费一个小时。。。
int n, m;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
int directions[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool isEdge(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    bool entirelyOnEdge = true;  // 假设这个区域完全位于边界上，除非找到一个反例

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        // 如果当前点不在边界上，这意味着整个区域不完全在边界上
        if (!isEdge(curr.first, curr.second)) {
            entirelyOnEdge = false;
        }

        for (int i = 0; i < 4; i++) {
            int newX = curr.first + directions[i][0];
            int newY = curr.second + directions[i][1];

            // 检查新坐标是否有效，且该点未被访问，且其值为1。
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                !visited[newX][newY] && matrix[newX][newY] == 1) {

                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }

    // 如果整个区域完全在边界上，返回0，否则返回1
    return entirelyOnEdge ? 0 : 1;
}

int main() {
    cin >> n >> m;
    matrix.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int regions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                regions += bfs(i, j);
            }
        }
    }

    cout << regions << endl;

    return 0;
}
