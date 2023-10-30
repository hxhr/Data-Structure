#include <iostream>
#include <vector>
#include <queue>
using namespace std;





//�����������ˡ�������һ����������һֱ�����ˣ���ʵ���д���ˣ��������˷�һ��Сʱ������
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

    bool entirelyOnEdge = true;  // �������������ȫλ�ڱ߽��ϣ������ҵ�һ������

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        // �����ǰ�㲻�ڱ߽��ϣ�����ζ������������ȫ�ڱ߽���
        if (!isEdge(curr.first, curr.second)) {
            entirelyOnEdge = false;
        }

        for (int i = 0; i < 4; i++) {
            int newX = curr.first + directions[i][0];
            int newY = curr.second + directions[i][1];

            // ����������Ƿ���Ч���Ҹõ�δ�����ʣ�����ֵΪ1��
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                !visited[newX][newY] && matrix[newX][newY] == 1) {

                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }

    // �������������ȫ�ڱ߽��ϣ�����0�����򷵻�1
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
