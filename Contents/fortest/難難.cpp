#include <bits/stdc++.h>
using namespace std;
#define int long long

struct carstatus{
    int lasttime;
    int dis;
    int id;
    bool operator>(const carstatus &other) const{
        return lasttime > other.lasttime;
    }
};

struct avlcar{
    int lasttime;
    int id;
    bool operator<(const avlcar &other) const{
        if(lasttime!=other.lasttime)return lasttime < other.lasttime;
        return id<other.id;
    }
};

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    int tmp;
    map<int,set<avlcar> > available;//dis lasttime id
    for(int i=1;i<=k;i++){
        cin>>tmp;
        available[tmp].insert({0,i});
    }

    priority_queue<carstatus,vector<carstatus>,greater<carstatus>> busy;
    int t,f,e;
    while(m--){
        cin>>t>>f>>e;

        while(!busy.empty() && busy.top().lasttime<=t){
            available[busy.top().dis].insert({busy.top().lasttime,busy.top().id});
            busy.pop();
        }

        if(available.empty()){
            int near=busy.top().lasttime;
            while(!busy.empty() && busy.top().lasttime==near){
                available[busy.top().dis].insert({busy.top().lasttime,busy.top().id});
                busy.pop();
            }
        }

        auto it=available.lower_bound(f);
        vector<pair<int,avlcar>> cdd;
        if(it!=available.end() && !it->second.empty()){
            cdd.push_back({it->first,*it->second.begin()});
        }
        if(it!=available.begin() && !prev(it)->second.empty()){
            cdd.push_back({prev(it)->first,*prev(it)->second.begin()});
        }

        pair<int,avlcar> best=cdd[0];
        for(auto i:cdd){
            int d1=llabs(best.first-f);
            int d2=llabs(i.first-f);

            if(d2<d1) best=i;
            if(d2==d1){
                if(i.second.lasttime<best.second.lasttime) best=i;
                else if(i.second.lasttime==best.second.lasttime && i.second.id<best.second.id) best=i;
            }
        }

        int wait=llabs(best.first-f);
        if(best.second.lasttime>t) wait+=llabs(best.second.lasttime-t);
        int run=llabs(f-e);
        cout<<best.second.id<<" "<<wait<<endl;

        busy.push({t+wait+run,e,best.second.id});
        available[best.first].erase(best.second);
        if (available[best.first].empty()) available.erase(best.first);
    }
}
