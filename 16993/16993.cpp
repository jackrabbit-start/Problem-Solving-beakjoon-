#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, M;
ll arr[100010];
class segtree{
public:
    ll size;
    vector<ll> tree[4]; //  0 그냥 , 1 왼, 2 오, 3 최소
    segtree(ll num){
        for(size =1; size<=num ; size*=2);
        tree[0].resize(size*2);
        tree[1].resize(size*2);
        tree[2].resize(size*2);
        tree[3].resize(size*2);
    }
    ll update1(ll pos, ll val){
        ll idx = pos+size-1;
        tree[0][idx] = val;
        tree[1][idx] = val;
        tree[2][idx] = val;
        tree[3][idx] = val;
        while(idx){
            idx/=2;
            tree[0][idx] = tree[0][idx*2] + tree[0][idx*2+1];
            tree[1][idx] = max(tree[1][idx*2] , tree[1][idx*2+1] + tree[0][idx*2]);
            tree[2][idx] = max(tree[2][idx*2+1] , tree[2][idx*2] + tree[0][idx*2+1]);
            tree[3][idx] = max(max(tree[3][idx*2], tree[3][idx*2+1]), tree[1][idx*2+1] + tree[2][idx*2]);
        }
        return 0;
    }
    ll finding(ll pos, ll start, ll end, ll x, ll y){
        if(end < x || y < start) return 0;
        if(start <= x && y <= end) return tree[3][pos];
        ll mid = (x+y)/2;
        ll a = finding(pos*2, start, end, x, mid); 
        ll b = finding(pos*2+1, start, end, mid+1, y);
        ll c = 0;
        ll res = max(max(a,b), c);
        return res;
    }

};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    segtree tree(N);
    for(ll i = 1; i <= N ; i++){
        ll input; cin>> input;
        tree.update1(i,input);
    }
    cin >> M;
    while(M--){
        ll a,b;
        cin >> a >> b;
        cout << tree.finding(1,a,b,1,tree.size) << "\n";
    }
    return 0;
}