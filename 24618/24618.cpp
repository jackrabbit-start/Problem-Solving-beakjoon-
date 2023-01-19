#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
vector<pair<ll ,ll>> v;
ll xx, yy;
ll to_x, to_y;
vector<tuple<ll, ll,ll>> arr1;
map<tuple<ll ,ll, ll>, ll> arr2;
ll ans[50];
ll ending;

int dfs(ll cnt, ll x, ll y, ll num, ll arrray){
    if(cnt == ending) {
        if(arrray == 1) {
            arr1.push_back(make_tuple(x,y,num));
        }
        else {
            if(arr2.count(make_tuple(x,y,num)) != 0){
                arr2[make_tuple(x, y, num)]++;
            }
            else arr2[make_tuple(x, y, num)] = 1;
        }
        return 0;
    }
    dfs(cnt+1 , x , y, num, arrray);
    x += v[cnt].first;
    y += v[cnt].second;
    dfs(cnt+1 , x, y, num+1, arrray);
    return 1;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    cin >> to_x >> to_y;
    for(ll i = 0 ; i < N; i++){
        cin >> xx >> yy;
        v.push_back(make_pair(xx, yy));
    }
    ending = N/2;
    dfs(0, 0, 0 ,0 ,1);
    ending = N;
    dfs(N/2, 0, 0 ,0 ,2);
    for(ll i = 0 ; i < arr1.size(); i++){
            ll nx = to_x - get<0>(arr1[i]);
            ll ny = to_y - get<1>(arr1[i]);
            for(ll j = 0 ; j <= N ; j++){
                if(arr2.count(make_tuple(nx,ny,j)) != 0){
                    ans[j + get<2>(arr1[i])] += arr2[make_tuple(nx,ny,j)];
                }
            }
    }
    for(ll i = 1 ; i <= N ; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}