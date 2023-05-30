#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll H, W, start_r, start_c;
ll N, Q;
map<ll, vector<ll>> r_pos, c_pos;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> H >> W >> start_r >> start_c >> N;
    for(ll i = 0 ; i < N ; i++){
        ll a, b;
        cin >> a >> b;
        r_pos[a].push_back(b);
        c_pos[b].push_back(a);
    }
    for(auto iter = r_pos.begin(); iter!= r_pos.end(); iter++){
        sort(iter->second.begin(), iter->second.end());
    }
    for(auto iter = c_pos.begin(); iter!= c_pos.end(); iter++){
        sort(iter->second.begin(), iter->second.end());
    }
    cin >> Q;
    char input;
    ll howmuch;
    for(ll i = 0 ; i < Q ; i++){
        cin >> input >> howmuch;
        if(input == 'L'){
            if(r_pos.count(start_r) == 0){
                start_c-=howmuch;
                if(start_c <= 0) start_c = 1;
            }
            else{
                auto it = lower_bound(r_pos[start_r].begin(),r_pos[start_r].end(), start_c);
                if(*it > start_c|| it == r_pos[start_r].end()){
                    if(it == r_pos[start_r].begin()){
                        start_c-=howmuch;
                        if(start_c <= 0) start_c = 1;
                        cout << start_r << " " << start_c << "\n";
                        continue;
                    }
                    else {it = it-1;}
                }
                if(*it < start_c-howmuch) start_c -= howmuch;
                else{
                    start_c = *it+1;
                }
            }

        }
        else if (input == 'R'){
            if(r_pos.count(start_r) == 0){
                start_c+=howmuch;
                if(start_c >= W) start_c = W;
            }
            else{
                auto it = upper_bound(r_pos[start_r].begin(),r_pos[start_r].end(), start_c);
                if(it == r_pos[start_r].end()){
                    start_c+=howmuch;
                    if(start_c >= W) start_c = W;
                }
                else{
                    if(*it > start_c+howmuch) start_c += howmuch;
                    else{
                        start_c = *it-1;
                    }
                }
            }

        }
        else if (input == 'U'){
            if(c_pos.count(start_c) == 0){
                start_r-=howmuch;
                if(start_r <= 0) start_r = 1;
            }
            else{
                auto it = lower_bound(c_pos[start_c].begin(),c_pos[start_c].end(), start_r);
                if(*it > start_r || it == c_pos[start_c].end()){
                    if(it == c_pos[start_c].begin()){
                        start_r-=howmuch;
                        if(start_r <= 0) start_r = 1;
                        cout << start_r << " " << start_c << "\n";
                        continue;
                    }
                    else { it = it-1;}
                }
                if(*it < start_r-howmuch) start_r -= howmuch;
                else{
                    start_r = *it+1;
                }
            }
        }
        else{
            if(c_pos.count(start_c) == 0){
                start_r+=howmuch;
                if(start_r >= H) start_r = H;
            }
            else{
                auto it = upper_bound(c_pos[start_c].begin(),c_pos[start_c].end(), start_r);
                if(it == c_pos[start_c].end()){
                    start_r+=howmuch;
                    if(start_r >= H) start_r = H;
                }
                else{
                    if(*it > start_r+howmuch) start_r += howmuch;
                    else{
                        start_r = *it-1;
                    }
                }
            }
        }
        cout << start_r << " " << start_c << "\n";
    }
    return 0;
}