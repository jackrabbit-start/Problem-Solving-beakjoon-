#include <bits/stdc++.h>
using namespace std;

void make_star(int x, int y, int N){
    if(N == 0) cout << "*";
    else if((x/N)%3 == 1 && (y/N)%3 == 1){
        cout <<" ";
    }
    else{
        make_star(x,y,N/3);
    }
}

int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j= 0 ; j < N ;j++){
            make_star(i,j,N);
        }
        cout <<"\n";
    }

    return 0;
}