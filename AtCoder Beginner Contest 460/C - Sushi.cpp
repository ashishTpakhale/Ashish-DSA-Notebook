#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  vector<int>b(m);
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]*=2;
  }
  for(int i=0;i<m;i++)cin>>b[i];
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int i=0,j=0,c=0;
  while(i<n && j<m){
    if(b[j]<=a[i]){
      i++;
      j++;
      c++;
    }
    else i++;
  }
  cout<<c<<endl;
  
}
