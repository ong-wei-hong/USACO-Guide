#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int n;
  cin>>n;
  array<int, 26> ans{};
  while(n--){
    string s1, s2;
    cin>>s1>>s2;
    array<int, 26> freq1{}, freq2{};
    for(char c: s1)
      ++freq1[c-'a'];
    for(char c: s2)
      ++freq2[c-'a'];
    for(int i=0; i<26; ++i)
      ans[i]+=max(freq1[i], freq2[i]);
  }
  for(int i: ans)
    cout<<i<<endl;
}
