#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int DP[105][105][105];

int w(int aa, int bb, int cc){
    if(aa <= 0 || bb <= 0 || cc <= 0) return 1;
    if(aa > 20 || bb > 20 || cc > 20){
        return w(20,20,20);
    }
    if(DP[aa][bb][cc] != -1) return DP[aa][bb][cc];
    if(aa < bb && bb < cc){
        DP[aa][bb][cc] = w(aa,bb,cc-1) +  w(aa,bb-1,cc-1) -  w(aa,bb-1,cc);
        return DP[aa][bb][cc];
    }
    else{
        DP[aa][bb][cc] = w(aa-1, bb, cc) + w(aa-1, bb-1, cc) + w(aa-1, bb, cc-1) - w(aa-1, bb-1, cc-1);
        return DP[aa][bb][cc];
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i = 1 ; i <= 50 ;i++){
        for(int j= 1 ; j <= 50 ;j++){
        for(int k = 1 ; k <= 50 ;k++){
            DP[i][j][k] = -1;
    }
    }
    }
    while(1){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c== -1) break;
        else{
            cout << "w(" << a <<", " << b <<", " << c << ") = " << w(a,b,c) << "\n";
        }
    
    }

    return 0;
}