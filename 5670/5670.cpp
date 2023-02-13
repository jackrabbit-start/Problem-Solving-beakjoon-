#include <bits/stdc++.h>
using namespace std;
int ans;
int N;

typedef struct node{
    char c;
    int cnt;
    map<char, node*> mp;
    node(char d){
        c = d;
        cnt = 0;
    }
}node;

int printans(node* a, int tmp){
    if(tmp == 1) ans += a->cnt;
    if(a->mp.size() == 0){
    }
    else if(a->mp.size() == 1){
        for(auto iter = a->mp.begin() ; iter != a->mp.end(); iter++){
            if(iter->second->cnt != a->cnt){
                printans(iter->second,1);
            }
            else{
                printans(iter->second,0);
            }
            
        }
    }
    else{
        for(auto iter = a->mp.begin() ; iter != a->mp.end(); iter++){
            printans(iter->second,1);
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    while(cin >> N){
        vector<string> v;
        map<char, node*> roots;
        string s;
        ans = 0;
        for(int i = 0 ; i < N ; i++){
            cin >> s;
            v.push_back(s);
        }
        for(int i = 0 ; i < N ; i++){
            s = v[i];
            node* root = roots[s[0]];
            if(root == NULL){
                root = new node(s[0]);
                roots[s[0]] = root;
            }
            node* from = root;
            from->cnt+=1;
            for(int j = 1 ; j < s.size() ;j++){
                node* to = from->mp[s[j]];
                if(to == NULL){
                    to = new node(s[j]);
                    from->mp[s[j]]= to;
                }
                to->cnt+=1;
                from = to;
            }
        }
        for(auto iter = roots.begin() ; iter!= roots.end() ; iter++){
            printans(iter->second, 1);
        }
        cout<<fixed;
        cout.precision(2);
        double answer = round((((double)(ans)*100)/(double)(N)))/100;
        cout << answer << "\n";
    }
    return 0;
}