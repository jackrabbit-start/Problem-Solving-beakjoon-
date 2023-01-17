#include <bits/stdc++.h>
using namespace std;
int N, W;
tuple<int ,int ,int ,int ,int> DP[1005][1005];
int DP2[1005][1005];
int trace[1005][1005];
vector<pair<int, int>> arr;
deque<int> ans;
deque<int> ans2;

int solve(){ // bottom-up
    int tmp;
    for(int i = 0 ; i < W ; i++){
        for(int j = 0 ; j < W; j++){
            if(i != 0 && i == j) continue;
            tmp = max(i,j);
            int a = get<0>(DP[i][j]) + abs(get<3>(DP[i][j]) - arr[tmp+1].first) + abs(get<4>(DP[i][j]) - arr[tmp+1].second);
            int b = get<0>(DP[i][j]) + abs(get<1>(DP[i][j]) - arr[tmp+1].first) + abs(get<2>(DP[i][j]) - arr[tmp+1].second);
            if(get<0>(DP[i][tmp+1]) > a ){
                DP[i][tmp+1] = make_tuple(a,get<1>(DP[i][j]),get<2>(DP[i][j]),arr[tmp+1].first,arr[tmp+1].second);
            }
            if(get<0>(DP[tmp+1][j]) > b ){
                DP[tmp+1][j] = make_tuple(b, arr[tmp+1].first , arr[tmp+1].second, get<3>(DP[i][j]), get<4>(DP[i][j]));
            }
        }
    }
    return 0;
}

int solve2(int x, int y){ // top-bottom
    if(DP2[x][y] != -1) return DP2[x][y];
    if(x-y == 1){
        int tmp = INT_MAX;
        tmp = solve2(0,y) + abs(1-arr[x].first) + abs(1-arr[x].second);
        for(int i = 1 ; i < y ; i++){
            tmp = min(tmp , solve2(i,y) + abs(arr[x].first - arr[i].first) + abs(arr[x].second - arr[i].second));
        }
        DP2[x][y] = tmp;
    }
    else if(y-x == 1){
        int tmp = INT_MAX;
        tmp = solve2(x,0) + abs(N-arr[y].first) + abs(N-arr[y].second);
        for(int i = 1 ; i < x ; i++){
            tmp = min(tmp , solve2(x,i) + abs(arr[y].first - arr[i].first) + abs(arr[y].second - arr[i].second));
        }
        DP2[x][y] = tmp;
    }
    else{
        if(x > y){
            DP2[x][y] = solve2(x-1, y) + abs(arr[x].first - arr[x-1].first) + abs(arr[x].second - arr[x-1].second);
        }
        else if(x < y){
            DP2[x][y] = solve2(x, y-1)+ abs(arr[y].first - arr[y-1].first) + abs(arr[y].second - arr[y-1].second);
        }
    }
    return DP2[x][y];
}
void back_trace2(int x, int y){
    if( x == 0 ){
        for(int i = 0 ; i < y ; i++){
            ans.push_front(2);
        }
    }
    else if( y == 0 ){
        for(int i = 0 ; i < x ; i++){
            ans.push_front(1);
        }
    }
    else if( x > y ){
        for(int i = 0 ; i < (x-y-1); i++){
            ans.push_front(1);
        }
        ans.push_front(1);
        for(int i = 0 ; i < y; i++){
            if(i == 0 && DP2[y+1][y] == DP2[i][y] + abs(arr[y+1].first - 1) + abs(arr[y+1].second - 1)){
                back_trace2(i , y);
                break;
            }
            else if(DP2[y+1][y] == DP2[i][y] + abs(arr[y+1].first - arr[i].first) + abs(arr[y+1].second - arr[i].second)){
                back_trace2(i , y);
                break;
            }
        }
    }
    else if(x < y){
        for(int i = 0 ; i < (y-x-1); i++){
            ans.push_front(2);
        }
        ans.push_front(2);
        for(int i = 0 ; i < x; i++){
            if(i == 0 && DP2[x][x+1] == DP2[x][i] + abs(arr[x+1].first - N) + abs(arr[x+1].second - N)){
                back_trace2(x , i);
                break;
            }
            if(DP2[x][x+1] == DP2[x][i] + abs(arr[x+1].first - arr[i].first) + abs(arr[x+1].second - arr[i].second)){
                back_trace2(x , i);
                break;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    cin >> W;
    int a, b;
    fill(&DP2[0][0] , &DP2[1002][1002] , -1);
    arr.push_back({0,0});
    for(int i = 0 ; i < W; i++){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    DP2[0][0] = 0;
    for(int i = 0 ; i <= W ; i++){
        for(int j = 0 ; j <= W; j++){
            get<0>(DP[i][j]) = INT_MAX;
        }
    }
    DP[0][0] = make_tuple(0,1,1,N,N);
    int answer = INT_MAX;
    for(int i = 0 ; i < W ; i++){
        answer = min(solve2(W, i), answer);
        answer = min(solve2(i, W), answer);
    }
    for(int i = 0 ; i < W; i++){
        if(answer == solve2(W, i)){
            back_trace2(W, i);
            break;
        }
        else if(answer == solve2(i, W)){
            back_trace2(i, W);
            break;
        }
    }
    cout << answer << "\n";
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
    solve();
    return 0;
}