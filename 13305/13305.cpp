#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long int> node;
vector<long long int> edge;
long long int answer;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    long long int input;
    for(long long int i = 0 ; i < N-1; i++){
        cin >> input;
        edge.push_back(input);
    }
    for(long long int i = 0 ; i < N; i++){
        cin >> input;
        node.push_back(input);
    }
    long long int cost = node[0];
    for(long long int i = 0 ; i < N; i++){
        cost = min(node[i], cost);
        answer += cost * edge[i];
    }
    cout << answer;
    


    return 0;
}