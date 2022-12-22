#include <bits/stdc++.h>
using namespace std;


int x, y, w, h;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> x >> y >> w >> h;
    int ans = 10000;
    ans = min(w-x,x);
    ans = min(ans,y);
    ans = min(ans,h-y);
    cout << ans;

    return 0;
}