#include<bits/stdc++.h>
using namespace std;

struct node{
    int leng,idx;
    bool operator<(const node& other) const {
        if (leng!=other.leng) return leng<other.leng;
        return idx>other.idx;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> tbl(n);
    for(auto &i:tbl) cin>>i;
    vector<int> num,len;
    int siz=0;
    num.push_back(tbl[0]);
    len.push_back(0);
    for(int i=0;i<n;i++){
        if(tbl[i]==num[siz]) len[siz]++;
        else{
            siz++;
            num.push_back(tbl[i]);
            len.push_back(1);
        }
    }
    siz=num.size();
    vector<int> L,R,alive(siz,1);
    for(int i=0;i<siz;i++){
        L.push_back(i-1);
        R.push_back(i+1);
    }
    priority_queue<node> pq;
    for(int i=0;i<siz;i++) pq.push({len[i],i});
    int ans=0;
    while(!pq.empty()){
        auto [currentL,idx]=pq.top();
        pq.pop();

        if(!alive[idx] || currentL!=len[idx]) continue;
        ans++;
        alive[idx]=0;
        int l=L[idx],r=R[idx];
        if(l>=0) R[l]=r;
        if(r<siz) L[r]=l;

        if(l>=0 && r<siz && alive[l] && alive[r] && num[l]==num[r]){
            len[l]+=len[r];
            alive[r]=0;
            R[l]=R[r];
            if(R[r]<siz) L[R[r]]=l;
            pq.push({len[l],l});
    }}
    cout<<ans;
}
