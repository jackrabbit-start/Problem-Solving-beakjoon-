#include <bits/stdc++.h>
using namespace std;
int N;
int arr[50][50];
int visited[100];
int start = 0;
int link = 0;
int ans = 987654321;
void dfs(int cnt, int idx){
    if(cnt == N/2){
        start =0;
        link = 0;
        for(int i = 1; i <= N-1; i++){
            for(int j = i+1 ; j <= N; j++){
                if(visited[i] == 0 && visited[j] == 0) start += arr[i][j] + arr[j][i];
                if(visited[i] == 1 && visited[j] == 1) link += arr[i][j] + arr[j][i];
            }
        }
        //cout << start << link;
        if(ans > abs(start-link)) ans = abs(start-link);
        return;
    }
    for(int i = idx; i <= N ; i++){ //백트레킹 dfs돌릴땐 2중첩 for문하면 시간이 존나많이 늘어나니까 최대한 for문 한번만 사용하기
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(cnt+1, i+1);
            visited[i] = 0;
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> arr[i][j];
        }
    }
    start = 0;
    link = 0;
    dfs(0,1);
    cout << ans;

    return 0;
}