#include <bits/stdc++.h>
using namespace std;
long long int A;
long long int B;
long long int C;
long long int tmp;
long long int tmp2;

long long int divide_conquer(long long int N, long long int index){
    if(index == 0) return 1;
    if(index == 1){
        return N % C;
    }
    else if(index == 2){
        return (N*N)%C;
    }
    else{
        tmp = divide_conquer(N, index/2)%C;
        tmp2 = divide_conquer(N, index%2)%C;
        return (((tmp*tmp)%C)*tmp2)%C;
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> A >> B >> C;
    cout << divide_conquer(A%C, B);


    return 0;
    
}