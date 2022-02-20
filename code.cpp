#include<bits/stdc++.h>
using namespace std;
ifstream in("arr.txt");
ofstream out("test.txt");
ofstream out1("ans.txt");
struct T {
	string name ;
	int ll,dl;
};
bool compareByLength(const T &a, const T &b)
{
	if(a.ll != b.ll)
    return (a.ll > b.ll);
    return (a.dl < b.dl);
}
bool compareByLength2(const T &a, const T &b)
{
    return (a.ll-a.dl) > (b.ll - b.dl);
}
int testCheck(map<string,int> &mp){
    ifstream in1("arr.txt");
    int   n,x1,x2 , cn= 0  ;
    string s ; 
    in1>>n ; 
	for(int i=0;i<n;i++){
		in1>>x1; 
		int l1 = 0 ; 
		for(int j=0;j<x1;j++){
			in1>>s ; 
            if(mp[s]>0) l1++; 
		} 
		in1>>x2; 
		int l2 = 0 ;
		for(int j=0;j<x2;j++){
			in1>>s ; 
            if(mp[s]>0) l2++; 
		} 
		if(l1==x1 && l2==0) cn++; 
	}

    in1.close();
    return cn; 

}
int main(){

    int x,n; in>>n ; 
    string s ;
    map<string,int> ll , dl  ;
	for(int i=0;i<n;i++){
		in>>x; 
		for(int j=0;j<x;j++){
			in>>s ; 
		    ll[s]++;
		} 
		in>>x; 
		for(int j=0;j<x;j++){
			in>>s ; 
			dl[s]++;
		} 
	}
    vector<T>tmp ;     
	map<string,int> mp ;

	for(auto x: ll) 
		tmp.push_back({x.first,x.second,dl[x.first]});

    sort(tmp.begin(), tmp.end(), compareByLength);	
	int l1=0 ;	
    for(auto x:tmp){
     	//if(x.ll>x.dl) out<<x.name<<" "<<x.ll<<" "<<x.dl<<endl;
    	 if(x.dl==0) { 
			 l1++;    
			 mp[x.name]=1; 
		    // out1<<x.name<<" ";   
		
		 }
    } 
  
    int k = testCheck(mp);
    sort(tmp.begin(), tmp.end(), compareByLength2);	
	for(auto x:tmp){
	     out<<x.name<<" "<<x.ll<<" "<<x.dl<<endl;
    	 if(x.dl!=0) { 
			 mp[x.name] = 1;  
			 int l = testCheck(mp) ;
			 if(l-k>1){
				 k=l ;
				 l1++;
			     cout<<k<<" "; 
				 continue ; 
			 }
		     mp[x.name] = 0;  
	    }
    } 

     
    cout<<l1;
	for(auto x:mp) {
		if(x.second>0) out1<<x.first<<" "; 
	}
 
}
