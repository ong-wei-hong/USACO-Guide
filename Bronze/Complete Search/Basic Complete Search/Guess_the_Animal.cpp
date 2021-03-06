#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N;
set<string> characteristics[100];

int main(){
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  cin>>N;
  for(int i=0; i<N; ++i){
    string animal, character;
    int K;
    cin>>animal>>K;
    for(int j=0; j<K; ++j){
      cin>>character;
      characteristics[i].insert(character);
    }
  }
  int ans=-1;
  for(int i=0; i<N; ++i){
    for(int j=i+1; j<N; ++j){
      int curr=0;
      for(string character: characteristics[i]){
	if(characteristics[j].find(character)!=characteristics[j].end())
	  ++curr;
      }
      ans=max(curr+1, ans);
    }
  }
  cout<<ans;
}
