#include <bits/stdc++.h>
using namespace std;
int N;
int ans;
vector<int> v;
vector<int> answer;

int solve(int cnt, int now){
    if(cnt > ans) return 0;
    if(now == 1){
        answer.clear();
        for(int i = 0 ; i < v.size(); i++){
            answer.push_back(v[i]);
        }
        ans = cnt;
        return 0;
    }
    v.push_back(now);
    if(now % 3 == 0){
        solve(cnt+1, now/3);

    }
    if(now % 2 == 0){
        solve(cnt+1, now/2);
    }
    solve(cnt+1, now-1);
    v.pop_back();
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ans = INT_MAX;
    cin >> N;
    solve(0,N);
    cout << ans << "\n";
    for(int i = 0 ; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << 1;
    return 0;
}