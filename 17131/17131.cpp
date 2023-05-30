#include <bits/stdc++.h>
using namespace std;
#define MODNN 1000000007
#define MAXN 500000
typedef long long int ll;
typedef pair<ll , ll> P;
ll N;
vector<P> v;
class segtree{
public:
    ll size;
    vector<ll> tree;
    segtree(){
        for(size =1 ; size < MAXN; size *=2);
        tree.resize(size*2);
    }
    void update(ll val){
        ll idx = val + size;
        tree[idx]++;
        idx /= 2;
        while(idx){
            tree[idx] = tree[idx*2] + tree[idx*2+1];
            idx/=2;
        }
    }
    ll sum(ll s, ll e, ll pos, ll x, ll y){
        if(s > y || e < x) return 0;
        if(s <= x && y <= e) { return tree[pos];}
        ll mid = (x+y)/2;
        return sum(s,e,pos*2, x, mid) + sum(s, e, pos*2+1, mid+1, y);
    }
};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    segtree tree;
    for(ll i = 0 ; i < N ; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back({x+200000,y+200000});
    }
    sort(v.begin(), v.end(), [](P &a, P &b){
        return a.second > b.second;
    });
    ll answer = 0;
    vector<P> tmp;
    for(ll i = 0 ; i < N ; i++){
        answer += tree.sum(0,v[i].first-1 , 1, 0,tree.size-1) * tree.sum(v[i].first+1,401000, 1, 0,tree.size-1);
        answer %= MODNN;
        if((i != N-1) && v[i].second == v[i+1].second) tmp.push_back(v[i]);
        else{
            for(ll j = 0 ; j < tmp.size(); j++){
                tree.update(tmp[j].first);
            }
            tree.update(v[i].first);
            tmp.clear();
        }
    }
    cout << answer;

    return 0;
}