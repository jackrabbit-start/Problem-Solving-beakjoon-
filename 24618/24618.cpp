#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
pair<ll ,ll> v[50];
ll xx, yy;
ll to_x, to_y;
map<tuple<ll ,ll, ll>, ll> arr1;
map<tuple<ll ,ll, ll>, ll> arr2;
ll ans[50];
ll ending;

void dfs(ll cnt, ll x, ll y, ll num, ll arrray){
    if(cnt == ending) {
        if(arrray == 1) {
            arr1[{x, y, num}]++;
        }
        else {
            arr2[{x, y, num}]++;
        }
        return;
    }
    dfs(cnt+1 , x , y, num, arrray);
    x += v[cnt].first;
    y += v[cnt].second;
    dfs(cnt+1 , x, y, num+1, arrray);
    return;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    cin >> to_x >> to_y;
    for(ll i = 0 ; i < N; i++){
        cin >> xx >> yy;
        v[i].first = xx;
        v[i].second = yy;
    }
    
    ending = N/2;
    dfs(0, 0, 0 ,0 ,1);
    ending = N;
    dfs(N/2, 0, 0 ,0 ,2);
    for(auto iter = arr1.begin() ; iter != arr1.end(); iter++){
            ll nx = to_x - get<0>(iter->first);
            ll ny = to_y - get<1>(iter->first);
            auto tmp = arr2.lower_bound({nx,ny,0});
            auto tmp2 = arr2.lower_bound({nx,ny,N});
            for(tmp ; tmp != tmp2; tmp++){
                ans[get<2>(tmp->first) + get<2>(iter->first)] += tmp->second * iter->second;
            }
    }
    for(ll i = 1 ; i <= N ; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}