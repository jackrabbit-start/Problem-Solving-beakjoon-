#include <bits/stdc++.h>
using namespace std;
double x, y, d, t;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> x >> y >> d >> t;
    double dis = sqrt(pow(x,2) + pow(y,2));
    double ans = double((int)(dis / d))*t;
    double ans2 = double((int)(dis / d))*t +t;
    double ans3 = double((int)(dis / d))*t +t;
    if((int)(dis / d) == 0) ans3 = 2*t;
    ans += dis - (ans/t)*d;
    ans2 += (ans2/t)*d - dis;
    cout << fixed;
    cout.precision(50);
    cout << min(min(min(ans, ans2),ans3),dis);
    return 0;
}

