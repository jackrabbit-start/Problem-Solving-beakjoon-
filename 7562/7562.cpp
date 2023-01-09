#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int from_x, from_y , to_x, to_y;
int visited[305][305];
int change_x[8] = {1, 2, 1 , 2, -1, -2, -1, -2};
int change_y[8] = {2, 1, -2, -1, 2, 1, -2, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i = 0 ; i < 8 ; i++){
            int x_pos = nx + change_x[i];
            int y_pos = ny + change_y[i];
            if(x_pos >= 0 && y_pos >=0 && x_pos <N && y_pos <N){
                if(!visited[x_pos][y_pos]){
                    visited[x_pos][y_pos] = visited[nx][ny] + 1;
                    q.push({x_pos, y_pos});
                }
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        fill(&visited[0][0] , &visited[303][303], 0);
        cin >> N;
        cin >> from_x >> from_y;
        cin >> to_x >> to_y;
        bfs(from_x, from_y);
        cout << visited[to_x][to_y]-1 << "\n";
    }
    return 0;
}