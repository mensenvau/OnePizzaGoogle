#include<bits/stdc++.h>
using namespace std ; 

int main(int argc, char const *argv[])
{
    ifstream in("ans.txt");
    ifstream in1("arr.txt");
    int N , n,x1,x2 , cn= 0  ;
    string s ; 
    map<string,int> mp; 
    in>>N;
    for(int i=0;i<N;i++){
        in>>s ; 
        mp[s] = 1; 
    } 
  
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

	cout<<cn ; 
}
