#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, Q;
ll arr[100010];
ll suming[100010];

class segtree{
public:
    ll size;
    vector<ll> tree;
    vector<ll> lazy;
    vector<ll> lazy2;
    segtree(ll num){
        for(size = 1; size<=num; size*=2);
        tree.resize(size*2);
        lazy.resize(size*2);
        lazy2.resize(size*2);
    }
    ll update(ll pos, ll start, ll end, ll x, ll y){
        if(lazy[pos]){
            tree[pos] += lazy[pos];
            if(pos < size){
                ll tmp = lazy[pos];
                ll q = suming[y-x+1]*lazy2[pos];
                ll t = tmp - q;
                t /= 2;
                lazy[pos*2] += suming[(y-x+1)/2]*lazy2[pos] + t;
                lazy[pos*2+1] += suming[(y-x+1)/2]*lazy2[pos] + t + ((y-x+1)/2)*((y-x+1)/2)*lazy2[pos]; 
                lazy2[pos*2] += lazy2[pos];
                lazy2[pos*2+1] += lazy2[pos];
            }
            lazy[pos] = 0;
            lazy2[pos] = 0;
        }
        if(end < x || y < start) return tree[pos];
        if(start <= x && y <= end){
            ll tmp = suming[y-x+1];
            ll h = x-start;
            tmp += h*(y-x+1);
            tree[pos]+=tmp;
            if(pos < size){
                ll q = suming[y-x+1];
                ll t = tmp - q;
                t /= 2;
                lazy[pos*2] += suming[(y-x+1)/2] + t;
                lazy2[pos*2]++;
                lazy[pos*2+1] += suming[(y-x+1)/2] + t + ((y-x+1)/2)*((y-x+1)/2);
                lazy2[pos*2+1]++;
            }
            return tree[pos];
        }
        ll mid = (x+y)/2;
        tree[pos] = update(pos*2,start, end, x,mid) + update(pos*2+1,start, end, mid+1, y);
        return tree[pos];
    }
    ll cal_sum(ll pos, ll start, ll end, ll x, ll y){
        if(lazy[pos]){
            tree[pos] += lazy[pos];
            if(pos < size){
                ll tmp = lazy[pos];
                ll q = suming[y-x+1]*lazy2[pos];
                ll t = tmp - q;
                t /= 2;
                lazy[pos*2] += suming[(y-x+1)/2]*lazy2[pos] + t;
                lazy[pos*2+1] += suming[(y-x+1)/2]*lazy2[pos] + t + ((y-x+1)/2)*((y-x+1)/2)*lazy2[pos]; 
                lazy2[pos*2] += lazy2[pos];
                lazy2[pos*2+1] += lazy2[pos];
            }
            lazy[pos] = 0;
            lazy2[pos] = 0;
        }
        if(end < x || y < start) return 0;
        if(start <= x && y <= end) return tree[pos];
        ll mid = (x+y)/2;
        return cal_sum(pos*2,start, end, x,mid) + cal_sum(pos*2+1,start, end, mid+1, y);
    }
};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 1; i <= N ; i++){
        cin >> arr[i];
    }
    for(ll i = 1; i <= N ; i++){
        suming[i] = suming[i-1]+ i;
    }
    cin >> Q;
    segtree tree(N);
    while(Q--){
        ll input;
        cin >> input;
        if(input == 1){
            ll a, b;
            cin >> a >> b;
            tree.update(1,a,b,1,tree.size);
        }
        else{
            ll a;
            cin >> a;
            cout << tree.cal_sum(1,a,a,1,tree.size)+arr[a] << "\n";
        }
    }
    return 0;
}