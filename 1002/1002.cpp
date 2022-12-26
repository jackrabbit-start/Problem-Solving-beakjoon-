#include <bits/stdc++.h>
using namespace std;

int T;
long long int x_1, x_2, y_1, y_2;
long long int r_1, r_2;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >>r_2;
        long long int distanceturret = (x_2-x_1)*(x_2-x_1) + (y_2-y_1)*(y_2-y_1);
        long long int distancetarget = (r_1+r_2)*(r_1+r_2);
        long long int distancetarget2 = (r_1-r_2)*(r_1-r_2);
        //cout << distancetarget << " " << distanceturret<<"\n";
        if(x_1 == x_2 && y_1 == y_2){
                if(r_1 == r_2) cout << "-1\n";
                else cout <<"0\n";
        }
        else if(distancetarget2 == distanceturret){
            cout <<"1\n";
        }
        else if(distanceturret == distancetarget){
            cout << "1\n";
        }
        else if(distanceturret > distancetarget){
            cout << "0\n";
        }
        else if(distanceturret < distancetarget2){
            cout << "0\n";
        }
        else{
            cout <<"2\n";
        }
    }

    return 0;
}