#include <iostream>
#include <algorithm>
using namespace std;

const int mxN=100, mxT=250;
int N, T, cow1[mxT+1], cow2[mxT+1];//cow1[t] shook cow2[t] at time t
bool valid_N[mxN+1]={0}, valid_K[mxT+1]={0};
string infected_end;

bool valid(int i, int K){ //simulates ith cow as patient 0 with K shakes
  bool infected[mxN+1]={0};
  int num_shakes[mxN+1]={0};
  infected[i]=1;
  for(int t=0; t<=250; ++t){
    if(cow1[t]>0){
      if(infected[cow1[t]]) ++num_shakes[cow1[t]];
      if(infected[cow2[t]]) ++num_shakes[cow2[t]];
      if(num_shakes[cow1[t]]<=K&&infected[cow1[t]]) infected[cow2[t]]=1;
      if(num_shakes[cow2[t]]<=K&&infected[cow2[t]]) infected[cow1[t]]=1;
    }
  }

  for(int i=1; i<=N; ++i)
    if(infected[i]!=(infected_end[i-1]=='1')) return 0;
  return 1;
}
int main(){
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);
  cin>>N>>T>>infected_end;
  for(int i=0; i<T; ++i){
    int t;
    cin>>t>>cow1[t]>>cow2[t];
  }
  for(int i=1; i<=N; ++i){
    for(int K=0; K<251; ++K){
      if(valid(i, K)){
	valid_N[i]=1;
	valid_K[K]=1;
      }
    }
  }

  int lower_K=251, upper_K=0, num_valid_N=0;
  for(int i=0; i<=250; ++i){
    if(valid_K[i]){
      lower_K=min(lower_K, i);
      upper_K=max(upper_K, i);
    }
  }
  for(int i=1; i<=N; ++i) num_valid_N+=valid_N[i];

  cout<<num_valid_N<<" "<<lower_K<<" ";
  if(upper_K==250) cout<<"Infinity";
  else cout<<upper_K;
}
