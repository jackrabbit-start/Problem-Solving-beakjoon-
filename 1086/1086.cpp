#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, K;
vector<string> v;
string tmp;
ll DP[1<<16][106];
ll arr[50];
ll len[50];
ll tenmodule[101];
ll answer;

ll findmodule(ll num, string a){
    ll answer = num;
    for(ll i = 0 ; i < a.size(); i++){
        answer = (answer * 10 + (a[i] - '0'))%K;
    }
    return answer;
}


ll dfs(ll num, ll visited){
    if(visited == (1<<N)-1) {
        if(num) return DP[visited][num] = 0;
        else return DP[visited][num] = 1;
    }
    if(DP[visited][num] != -1) return DP[visited][num];
    DP[visited][num] = 0;
    for(int i = 0 ; i < N ; i++){
        if((visited&(1<<i)) != 0) continue;
        ll total = (num*tenmodule[len[i]] + arr[i]) %K;
        DP[visited][num] += dfs(total, visited|(1<<i));
    }
    return DP[visited][num];
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    string s;
    for(ll i = 0 ; i < N ; i++){
        cin >> s;
        v.push_back(s); 
    }
    cin >> K;
    for(ll i = 0 ; i < N ; i++){
        len[i] = v[i].size();
        arr[i] = findmodule(0,v[i]);
    }
    tenmodule[0] = 1%K;
    fill(&DP[0][0] , &DP[(1<<16)-1][101], -1);
    for(ll i = 1 ; i < 100; i++) tenmodule[i] = (tenmodule[i-1]*10) %K;
    answer = dfs(0,0);
    ll ans = 1;
    if(answer == 0) cout << "0/1";
    else{
        for(ll i = 1; i <= N ; i++) ans*= i;
        ll tmp = __gcd(ans,answer);
        answer/=tmp;
        ans /= tmp;
        cout << answer << "/" << ans;
    }

    return 0;
}