#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N;
ll arr[25][25];
ll ans;

ll make_left(ll cnt){
    ll tmp = 0;
    ll total = 0;
    for(ll i = 0 ; i < N ; i++){
        ll now = 0;
        ll idx = 1;
        while(idx < N){
            if(arr[i][idx] == 0) idx++;
            else if(arr[i][now] == 0 && arr[i][idx] != 0){
                arr[i][now] = arr[i][idx];
                arr[i][idx] = 0;
                idx++;
                tmp++;
            }
            else if(arr[i][now] == arr[i][idx]){
                arr[i][now] = arr[i][now] + arr[i][idx];
                ans = max(arr[i][now] , ans);
                
                arr[i][idx] = 0;
                now++;
                idx++;
                tmp++;
            }
            else{
                now++;
                arr[i][now] = arr[i][idx];
                if(now != idx) {arr[i][idx] = 0; tmp++;}
                idx++;
            }
            total = max(arr[i][now] , total);
        }
    }
    if(pow(total, 11-cnt) < ans || tmp == 0) return 0;
    else return 1;
}
ll make_right(ll cnt){
    ll tmp = 0;
    ll total =0 ;
    for(ll i = 0 ; i < N ; i++){
        ll now = N-1;
        ll idx = N-2;
        while(idx >= 0){
            if(arr[i][idx] == 0) idx--;
            else if(arr[i][now] == 0 && arr[i][idx] != 0){
                arr[i][now] = arr[i][idx];
                arr[i][idx] = 0;
                idx--; tmp++;
            }
            else if(arr[i][now] == arr[i][idx]){
                arr[i][now] = arr[i][now] + arr[i][idx];
                arr[i][idx] = 0;
                ans = max(arr[i][now] , ans);
                
                now--;
                idx--; tmp++;
            }
            else{
                now--;
                arr[i][now] = arr[i][idx];
                if(now != idx) {arr[i][idx] = 0; tmp++;}
                idx--;
            }
            total = max(arr[i][now] , total);
        }
    }
    if(pow(total, 11-cnt) < ans || tmp == 0) return 0;
    else return 1;
}
ll make_down(ll cnt){
    ll tmp = 0;
    ll total = 0;
    for(ll i = 0 ; i < N ; i++){
        ll now = N-1;
        ll idx = N-2;
        while(idx >= 0){
            if(arr[idx][i] == 0) idx--;
            else if(arr[now][i] == 0 && arr[idx][i] != 0){
                arr[now][i] = arr[idx][i];
                arr[idx][i] = 0;
                idx--; tmp++;
            }
            else if(arr[now][i] == arr[idx][i]){
                arr[now][i] = arr[now][i] + arr[idx][i];
                arr[idx][i] = 0;
                ans = max(arr[now][i] , ans);
                total = max(arr[now][i] , total);
                now--;
                idx--; tmp++;
            }
            else{
                now--;
                arr[now][i] = arr[idx][i];
                if(now != idx){arr[idx][i] = 0; tmp++;}
                idx--;
            }
            total = max(arr[i][now] , total);
        }
    }
    if(pow(total, 11-cnt) < ans || tmp == 0) return 0;
    else return 1;
}
ll make_up(ll cnt){
    ll total = 0;
    ll tmp = 0;
    for(ll i = 0 ; i < N ; i++){
        ll now = 0;
        ll idx = 1;
        while(idx < N){
            if(arr[idx][i] == 0) idx++;
            else if(arr[now][i] == 0 && arr[idx][i] != 0){
                arr[now][i] = arr[idx][i];
                arr[idx][i] = 0;
                idx++; tmp++;
            }
            else if(arr[now][i] == arr[idx][i]){
                arr[now][i] = arr[now][i] + arr[idx][i];
                arr[idx][i] = 0;
                ans = max(arr[now][i] , ans);
                total = max(arr[now][i] , total);
                now++;
                idx++;tmp++;
            }
            else{
                now++;
                arr[now][i] = arr[idx][i];
                if(now != idx) {arr[idx][i] = 0; tmp++;}
                idx++;
            }
            total = max(arr[i][now] , total);
        }
    }
    if(pow(total, 11-cnt) < ans || tmp == 0) return 0;
    else return 1;
}
ll solve(ll cnt, ll bfins){ // 저번에 상하 = 0  좌우라면 - 1
    ll tmp = 0;
    ll checking = 1;
    if(cnt == 11){
        for(ll i = 0 ; i < N ; i++){
            for(ll j = 0 ; j < N ; j++){
                ans = max(arr[i][j] , ans); 
            }
        }
        return tmp;
    }
    ll arr3[25][25];
    for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ; j++){
            arr3[i][j] = arr[i][j];
        }
    }
        if(make_up(cnt) != 0) tmp = max(tmp, solve(cnt+1, 0));
        for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ; j++){
            arr[i][j] = arr3[i][j];
        }
        }
        if(make_down(cnt) != 0) tmp = max(tmp, solve(cnt+1, 0));
        for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ; j++){
            arr[i][j] = arr3[i][j];
        }
        }
        if(make_left(cnt) != 0) tmp = max(tmp, solve(cnt+1, 0));
        for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ; j++){
            arr[i][j] = arr3[i][j];
        }
        }
        if(make_right(cnt) != 0) tmp = max(tmp, solve(cnt+1, 0));
        for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ; j++){
            arr[i][j] = arr3[i][j];
        } 
        }
    return tmp;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(ll i = 0 ; i < N ; i++){
        for(ll j = 0 ; j < N ;j++){
            cin >> arr[i][j];
            ans = max(arr[i][j] , ans);
        }
    }
    solve(1,0);
    cout << ans;
    return 0;
}