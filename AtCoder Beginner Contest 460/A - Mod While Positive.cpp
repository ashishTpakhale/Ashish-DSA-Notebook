#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int c=0;
  while(m){
    m=n%m;
    c++;
  }
  cout<<c<<endl;
}
