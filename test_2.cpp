#include<bits/stdc++.h>
using namespace std;
ifstream in("ans.txt");
 ofstream out1("ans1.txt");
int main(){
    string s ; 
    int l1=0; 
  
    while(!in.eof()){
        in>>s;
        l1++;
        cout<<l1<<" "<<s<<" "<<endl; 
        out1<<s<<" ";
    }

    cout<<l1;

  
   
   
}