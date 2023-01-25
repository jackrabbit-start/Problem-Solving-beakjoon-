#include <bits/stdc++.h>
using namespace std;
int x_1, x_2, x_3, y_1, y_2, y_3;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> x_1 >> y_1;
    cin >> x_2 >> y_2;
    cin >> x_3 >> y_3;
    int xx1 = x_2 - x_1;
    int yy1 = y_2 - y_1;
    int xx2 = x_3 - x_1;
    int yy2 = y_3 - y_1;
    if((xx1 * yy2) - (yy1 * xx2) > 0) cout << 1;
    else if ((xx1 * yy2) - (yy1 * xx2) < 0) cout << -1;
    else cout << 0;
    return 0;
}