#include <bits/stdc++.h>
using namespace std;

const int mxN=100;
int n, X[mxN], Y[mxN], x, y;
string ramp[mxN];

int main(){
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);

  cin>>n;
  for(int i=0; i<n; ++i){
    cin>>ramp[i];
    cin>>X[i]>>Y[i];
  }

  x=-1, y=1001;
  
  for(int i=n-1; i>=0; --i){
    if(ramp[i]=="none"){
      x=max(x, X[i]);
      y=min(y, Y[i]);
    }else if(ramp[i]=="on"){
      x-=Y[i];
      x=max(0, x);
      y-=X[i];
    }else if(ramp[i]=="off"){
      x+=X[i];
      y+=Y[i];
      y=min(1000, y);
    }
  }
  cout<<x<<" "<<y<<endl;

  x=-1, y=1001;

  for(int i=0; i<n; ++i){
    if(ramp[i]=="none"){
      x=max(x, X[i]);
      y=min(y, Y[i]);
    }else if(ramp[i]=="on"){
      x+=X[i];
      y+=Y[i];
      y=min(1000, y);
    }else if(ramp[i]=="off"){
      x-=Y[i];
      x=max(0, x);
      y-=X[i];
    }
  }
  cout<<x<<" "<<y;
}
