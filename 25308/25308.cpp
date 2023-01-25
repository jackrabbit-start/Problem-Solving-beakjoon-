#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<double> v;
int used[10];
int ans;
double calculation(double past, double nows){
    double past2 = past*sqrt(2);
    double k = past*nows;
    double l = past2-nows;
    double t = k / l;
    return t;
}
int backtracking(int cnt, int idx, double past, double now){ // idx 최대수 , past 전수, now 현재수
    double tmp = calculation(past, now);
    if(cnt == 7) {
        if(tmp < 0) ans++;
        else if(v[0] <= tmp) ans++;
        return 0;
    }
    int index = 8;
    for(int i = 1 ;  i < 8 ; i++){
        if(v[i] <= tmp){
            index = i;
            break;
        }
    }
    if(tmp < 0) index = 1;
    for(int i = index ; i < 8; i++){
        if(!used[i]){
            used[i] = 1;
            backtracking(cnt+1, index, now, v[i]);
            used[i] = 0;
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    double input;
    for(int i = 0 ; i < 8 ; i++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.rbegin(), v.rend());
    used[0] = 1;
    for(int i = 1; i < 8 ; i++) {
        used[i] = 1;
        backtracking(1 , 1, v[0], v[i]);
        used[i] = 0;
    }
    cout << ans*8;
    return 0;
}