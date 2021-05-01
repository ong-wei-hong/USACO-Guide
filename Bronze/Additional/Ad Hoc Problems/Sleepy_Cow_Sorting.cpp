#include <iostream>
using namespace std;

int N, cows[100];

/*ans is the element at which the decreasing sequence stops from the back
the first (N-ans) elements will be sloted after the (ans) elements such that it forms a continuous sequence*/

int main(){
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);
  cin>>N;
  for(int i=0; i<N; ++i)
    cin>>cows[i];
  int ans=N-1;
  while(cows[ans-1]<cows[ans]){
    --ans;
  }
  cout<<max(0, ans); //min ans is 0
}
