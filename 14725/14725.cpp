#include <bits/stdc++.h>
using namespace std;
int N;
int K;
string u, v;


typedef struct node{
    string s;
    int depth;
    map<string, node*> nodes;
    node(string a, int cnt){
        s = a;
        depth = cnt;
    }
}Node;

bool compare(node* a, node*b){
    return a->s < b->s;
}

void printtree(node* now){
    for(int i = 0 ; i < now->depth;i++) cout << "--";
    cout << now->s << "\n";
    if(now->nodes.size() == 0) return;
    for(auto iter = now->nodes.begin() ; iter != now->nodes.end() ;iter++){
        printtree(iter->second);
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    map<string, node*>roots;
    for(int i = 0 ; i < N ; i++){
        cin >> K;
        cin >> u;
        Node* root = roots[u];
        if(root == NULL) {root = new Node(u,0);}
        roots[u] = root;
        Node* from = root;
        for(int i = 1 ; i < K ; i++){
            cin >> v;
            Node* to;
            if(from->nodes[v] == NULL){
                to = new Node(v,i);
                from->nodes[v] = to;
            }
            else{
                to = from->nodes[v];
            }
            from = to;
        }
    }
    for(auto iter = roots.begin() ; iter != roots.end(); iter++){
        printtree(iter->second);
    }
    return 0;
}