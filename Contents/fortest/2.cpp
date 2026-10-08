#include<bits/stdc++.h>
using namespace std;
multiset<int> l,r;
int tbl[200005];
void resort(){
	while(l.size()<r.size()){
		l.insert(*r.begin());
        r.erase(r.begin());
	}
	while(l.size()>r.size()+1){
		r.insert(*l.rbegin());
        l.erase(prev(l.end()));
	}
}
void insert_num(int num){
	if(l.empty() || num<=*l.rbegin()) l.insert(num);
	else r.insert(num);
	resort();
}
void erase_num(int num){
	if(l.find(num)!=l.end()) l.erase(l.find(num));
	else r.erase(r.find(num));
	resort();
}
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>tbl[i];
	for(int i=0;i<x;i++) insert_num(tbl[i]);
	cout<<*l.rbegin()<<" ";
	for(int i=x;i<n;i++){
		insert_num(tbl[i]);
		erase_num(tbl[i-x]);
		cout<<*l.rbegin()<<" ";
	}}