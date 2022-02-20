#include<bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
vector<string> ll_vec[9368]; 
vector<string> dl_vec[9368]; 
int n=9368,x,ml=0; 
string s ;
set<string>ans;
void solve(set<string> st,int idx,int l){
	 
    if(l>=ml){
        ml=l ;
    }
	if(idx>=n) return ;  
	for(int i=0;i<dl_vec[idx].size();i++) if(st.find(dl_vec[idx][i])!=st.end()) return ;
	for(int i=0;i<ll_vec[idx].size();i++) st.insert(ll_vec[idx][i]);
	for(int i=idx;i<n;i++) solve(st,i+1,l+1);
}
int main(){
	

	in>>n;

	for(int i=0;i<n;i++){
		in>>x; 
		for(int j=0;j<x;j++){
			in>>s ; 
			ll_vec[i].push_back(s);
		} 
		in>>x; 
		for(int j=0;j<x;j++){
			in>>s ; 
			dl_vec[i].push_back(s);
		} 
	}
	
	set<string> st ;
	for(int i=0;i<10;i++) {
		cout<<i<<"\n";
	    solve(st,i,0);
	}
	
	cout<<ml; 
 
}
