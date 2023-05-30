#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
ll N, K, D;
ll arr[100100];
class segtree{
public:
    ll size;
    vector<ll> tree[20];
    segtree(ll num){
        for(size  = 1; size <= num; size*=2);
        for(ll i = 0 ; i <= K; i++){
            tree[i].resize(size*2);
        }
    }
    ll update(ll pos, ll val, ll height, ll start, ll end, ll x, ll y){
        if(end < x || start > y) return tree[height][pos];
        if(start <= x && y <= end) return tree[height][pos] += val%MOD;
        ll mid = (x+y)/2;
        tree[height][pos] = (update(pos*2, val,height, start,end, x, mid) + update(pos*2+1, val,height, start, end, mid+1, y))%MOD;
        return tree[height][pos]%MOD;
    }
    ll ll_sum(ll pos, ll height, ll start, ll end, ll x, ll y){
        if(end < x || start > y) return 0;
        if(start <= x && y <= end) return tree[height][pos]%MOD;
        ll mid = (x+y)/2;
        return (ll_sum(pos*2,height, start,end, x, mid) + ll_sum(pos*2+1,height, start, end, mid+1, y))%MOD;
    }
};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> K;
    segtree tree(N);
    for(ll i =1; i <= N ; i++){
        cin >> arr[i];
    }
    for(ll i = 1 ; i <= N ; i++){
        for(ll j = 0; j < K; j++){
            ll tmp;
            if(j == 0) tmp = 1;
            else tmp = tree.ll_sum(1, j-1, 1, arr[i]-1, 1, tree.size);
            tree.update(1,tmp,j,arr[i],arr[i] , 1,tree.size);
        }
    }
    cout << tree.ll_sum(1,K-1,1,N, 1, tree.size)%MOD << "\n";
    return 0;
}