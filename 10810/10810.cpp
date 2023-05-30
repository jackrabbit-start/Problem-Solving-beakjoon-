#include <bits/stdc++.h>
using namespace std;
int N, M;
int a, b, c;
int arr[3000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N ; i++){
        arr[i] = i;
    }
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        swap(arr[a], arr[b]);
    }
    for(int i = 1; i <= N ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}