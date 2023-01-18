#include <bits/stdc++.h>
using namespace std;
int N ,M;
int s, e;
int arr[500005];

int find(int x){
    if(arr[x] == x) return x;
    return arr[x] = find(arr[x]);
}

int UNION(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a != b ){
        arr[a] = b;
    }
    else{
        return 0;
    }
    return 1;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans = 0;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        arr[i] = i;
    }
    for(int i = 0 ; i < M ; i++){
        cin >> s >> e;
        if(!UNION(s,e)){
            ans = i+1;
            break;
        }
    }
    cout << ans;
    return 0;
}