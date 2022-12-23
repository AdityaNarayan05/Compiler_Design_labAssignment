#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vi>
#define vvc vector<vc>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
// #define ff first
// #define ss second
const int N=1e5+2;

set<char> ss;
map<char,vvc> mp;

//for first
bool dfs(char i,char org,char last,map<char,vvc> &mp){
    bool rake=false;
    for(auto r:mp[i]){
        bool take=true;
        for(auto s:r){
            if(s==i) break;
            if(!take) break;

            if(!(s>='A' and  s<='Z') and s!='e'){
                ss.insert(s);
                break;            
            }
            else if (s=='e'){
                if(org==i or i==last)
                ss.insert(s);
                rake=true;
                break;
            }
            else{
                take=dfs(s,org,r[r.size()-1],mp);
                rake |=take;
            }
        }
    }
    return rake;
}

//for Follow:
map<int,map<char,set<pair<deque<char>,deque<char>>>>> f;
map<int,vector<pair<int,char>>> g;
int num = -1;
void dfs2(char c, char way, int last, pair<deque<char>,deque<char>> curr){
    map<char,set<pair<deque<char>,deque<char>>>> mp2;
    int rep = -2;
    if(last != -1){
        for(auto q : g[last]){
            if(q.second == way){
                rep = q.first;
                mp2 = f[q.first];
            }
        }
    }
    mp2[c].insert(curr);
    int count = 10;
    while(count--){
        for(auto q : mp2){
            for(auto r : q.second){
                if(!r.second.empty()){
                    if(r.second.front()>='A'&&r.second.front()<='Z'){
                        for(auto s : mp[r.second.front()]){
                            deque<char> st,emp;
                            for(auto t : s) st.push_back(t);
                            mp2[r.second.front()].insert({emp,st});
                        }
                    }
                }
            }
        }
    }
    for(auto q : f){
        if(q.second == mp2){
            g[last].push_back({q.first,way});
            return;
        }
    }
    if(rep == -2){
        f[++num] = mp2;
        if(last != -1)
        g[last].push_back({num,way});
    }
    else{
        f[rep] = mp2;
    }
    int cc = num;
    for(auto q : mp2){
        for(auto r : q.second){
            if(!r.second.empty()){
                r.first.push_back(r.second.front());
                r.second.pop_front();
                dfs2(q.first,r.first.back(),cc,r);
            }
        }
    }
}

map<int,map<char,set<pair<deque

int main(){
    int i;
    int j;
    ifstream fin("input.txt");
    string num;
    vi fs;
    vvi a;
    char start;
    bool flag=0;
    cout<<"Grammar:"<<endl;
    while(getline(fin,num)){
        if(flag==0){
            start=num[0];
            flag=1;
        }
        cout<<num<<endl;
        vc temp;
        char s=num[0];
        for(int i=3;i<num.size();++i){
            if(num[i]=='|'){
                mp[s].push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(num[i]);
            }
            mp[s].push_back(temp);
        }
    }
    map<char,set<char>> fmp;
    for(auto q:mp){
        ss.clear();
        dfs(q.first,q.first,q.first,mp);
        for(auto g:ss){
            fmp[q.first].insert(g);
        }
    }

    cout<<endl;
    cout<<"First:"<<endl;
    for(auto q:fmp){
        string ans="";
        ans+=q.first;
        ans+="={";
        for(char r:q.second){
            ans+=r;
            ans+=',';
        }
        ans.pop_back();
        ans+="}";
        cout<<ans<<endl;
    }

    map<char,set<char>> gmp;
    gmp[start].insert('$');
    int count = 10;
    while(count--){
        for(auto q : mp){
            for(auto r : q.second){
                for(i=0;i<r.size()-1;i++){
                    if(r[i]>='A'&&r[i]<='Z'){
                        if(!(r[i+1]>='A'&&r[i+1]<='Z')) gmp[r[i]].insert(r[i+1]);
                        else {
                            char temp = r[i+1];
                            int j = i+1;
                            while(temp>='A'&&temp<='Z'){
                                if(*fmp[temp].begin()=='e'){
                                    for(auto g : fmp[temp]){
                                        if(g=='e') continue;
                                        gmp[r[i]].insert(g);
                                    }
                                    j++;
                                    if(j<r.size()){
                                        temp = r[j];
                                        if(!(temp>='A'&&temp<='Z')){
                                            gmp[r[i]].insert(temp);
                                            break;
                                        }
                                    }
                                    else{
                                        for(auto g : gmp[q.first]) gmp[r[i]].insert(g);
                                        break;
                                    }
                                }
                                else{
                                    for(auto g : fmp[temp]){
                                        gmp[r[i]].insert(g);
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
                if(r[r.size()-1]>='A'&&r[r.size()-1]<='Z'){
                    for(auto g : gmp[q.first]) gmp[r[i]].insert(g);
                }
            }
        }
    }

    cout<<endl;
    cout<<"FOLLOW: "<<endl;
    for(auto q : gmp){
        string ans = "";
        ans += q.first;
        ans += " = {";
        for(char r : q.second){
            ans += r;
            ans += ',';
        }
        ans.pop_back();
        ans+="}";
        cout<<ans<<endl;
    }

    string t="";
    t+=',';
    t+=start;
    
    deque<char> emp,st;
    st.push_back(start);
    dfs2('!','k',-1,{emp,st});

    return 0;
}