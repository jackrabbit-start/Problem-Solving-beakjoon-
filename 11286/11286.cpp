#include <bits/stdc++.h>
using namespace std;
int N;
struct cmp{
    bool operator()(int &t, int &c){
        if(abs(t) == abs(c)) return t>c;
        return abs(t) > abs(c);
    }
};
priority_queue<int, vector<int>, cmp> pq;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int x;
    for(int i = 0 ; i < N ; i++){
        cin >> x;
        if( x == 0){
            if(pq.empty()){
                cout << "0\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);

        }
        
    }
    return 0;
}