#include <iostream>
#include <algorithm>
using namespace std;

const int mxN=100;
int N, x[mxN], y[mxN], t[1001];//x is the start, y the end and t is the time when the cow start and end their shifts

int main(){
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  cin>>N;
  for(int i=0; i<N; ++i){
    cin>>x[i]>>y[i];
    ++t[x[i]];
    --t[y[i]];
  }
  int ans=-1;
  for(int i=0; i<N; ++i){
    --t[x[i]];
    ++t[y[i]];
    int curr=0, curr_guards=0;//curr records the time while curr_guards is the number of guards on duty
    for(int j=0; j<=1000; ++j){
      curr_guards+=t[j];
      if(curr_guards)
	++curr;
    }
    ans=max(ans, curr);
    ++t[x[i]];
    --t[y[i]];
  }
  cout<<ans;
}
