#include <bits/stdc++.h>
using namespace std;
int N, M, H;
int visited[105][105][105]; // H M N
int change_x[6] = {0 , 0 , 0 , 0 , 1 , -1};
int change_y[6] = {1 , -1 , 0 , 0 , 0 , 0};
int change_z[6] = {0 , 0 , 1 , -1 , 0 , 0};
vector<tuple<int, int ,int>> v;

void bfs(int x, int y, int z){
    queue<tuple<int, int ,int>> q;
    q.push({x,y,z});
    visited[x][y][z] = 1;
    while(!q.empty()){
        int nx = get<0>(q.front());
        int ny = get<1>(q.front());
        int nz = get<2>(q.front());
        q.pop();
        for(int i = 0 ; i < 6; i++){
            int x_pos = nx + change_x[i];
            int y_pos = ny + change_y[i];
            int z_pos = nz + change_z[i];
            if(x_pos >= 0 && y_pos >= 0 && z_pos >= 0 && x_pos<N && y_pos < M && z_pos < H){
                if(visited[x_pos][y_pos][z_pos] == 0 || visited[x_pos][y_pos][z_pos] > visited[nx][ny][nz]+1){
                    visited[x_pos][y_pos][z_pos] = visited[nx][ny][nz]+1;
                    q.push({x_pos, y_pos, z_pos});
                }
            }
        }
    }

}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M >> H;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < M ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> visited[k][j][i];
                if(visited[k][j][i] == 1) v.push_back(make_tuple(k,j,i));
            }
        }
    }
    for(int i = 0 ; i < v.size(); i++){
        bfs(get<0>(v[i]),get<1>(v[i]),get<2>(v[i]));
    }
    int ans = 0;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < M ; j++){
            for(int k = 0 ; k < N ; k++){
                if(visited[k][j][i] == 0){cout << -1; return 0;}
                ans = max(ans, visited[k][j][i]);
            }
        }
    }
    cout << ans -1;
    
    return 0;
}