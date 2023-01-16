#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, C;
ll arr[40];
vector<ll> v1;
vector<ll> v2;
ll ans;
ll sum;

void make_arr(ll cnt){
    if(cnt == N/2) { v1.push_back(sum); return;}
    make_arr(cnt+1);
    sum += arr[cnt];
    make_arr(cnt+1);
    sum -= arr[cnt];
    return;
}
void make_arr2(ll cnt){
    if(cnt == N) { v2.push_back(sum); return;}
    make_arr2(cnt+1);
    sum += arr[cnt];
    make_arr2(cnt+1);
    sum -= arr[cnt];
    return;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> C;
    for(ll i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    make_arr(0);
    make_arr2(N/2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if(v1.size()== 0){
        auto tmp = upper_bound(v2.begin(), v2.end(), C);
        ans = tmp - v2.begin();
        if(*tmp != C) ans--;
        cout << ans;
        return 0;
    }
    ll i = 0;
    ll j = v2.size()-1;
    while(i < v1.size()){
        if(j < 0){
            break;
        }
        if(v1[i] + v2[j] <= C) {
            ans += j+1;
            i++;
        }
        else{
            j--;
        }
    }
    cout << ans;
    return 0;
}