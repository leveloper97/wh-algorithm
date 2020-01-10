/* 
** BOJ 1926
** ???? ???? : BFS
** ???? ???? : ??? 
** https://www.acmicpc.net/problem/1926
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX = 502; // ????, ???? ??? 500????. (?��????????����? ??? +2) 

int n = 0; // ???? ???
int m = 0; // ???? ???

int map[MAX][MAX]; // ??? ???? ?��?? ????????. 
bool visited[MAX][MAX] = {false}; // ?�� ??? ?��?? ?�� ????????. 

// ???????????? ???????? ???? ?��????. 
int dx[4]={1, 0, 0, -1};
int dy[4]={0, 1, -1, 0};

int bfs(int x, int y) {	
	int area = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y)); 
	visited[x][y] = true;
	while(q.empty() == false) {
		auto cur = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nextX = cur.first + dx[i];
			int nextY = cur.second + dy[i];
			
			if (nextX < 0 || n < nextX) {
				cout << "???? ??? ?????????? ???? ???????" << endl;
				continue; 
			}
			if (nextY < 0 || m < nextY) {
				cout << "???? ??? ????????? ???? ???????" << endl;
				continue;
			}
			
			if (map[nextX][nextY] == 1 && visited[nextX][nextY] == false) {
				q.push(make_pair(nextX, nextY));
				visited[nextX][nextY] = true;
				area++;
	//			area += bfs(x + dx[i], y + dy[i]);
			}
			else {
				cout << "???? ???????." << endl;
			}
		}	
	}
	return area;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> m; // ????, ???? ?????? ??? ??????.

    int max = 0; // ??? ???? 
    int cnt = 0; // ??? ?? ????
    
    // ????? ?????? ??? ??????.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    // ????? ???????.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	// ?????? ???? 1??? ?��???? ???? ???? ?��????. 
   	        if (map[i][j] == 1 && visited[i][j] == true) {
   	        	// ??? ????? ???? ????????. 
				int temp = bfs(i, j); 
   	        	max = max < temp? temp:max;
   	        	cnt++;
   	        }
        }
    }
    
    cout << cnt << endl;
    cout << max << endl;
    
    return 0;
}