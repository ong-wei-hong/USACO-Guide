#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string s, t, ans;
  cin>>s>>t;

  for(char c: s){
    ans+=c;
    //check if the last portion is t
    if(ans.size()>=t.size()&&ans.substr(ans.size()-t.size())==t){
      ans.resize(ans.size()-t.size());
    }
  }
  cout<<ans;
}

