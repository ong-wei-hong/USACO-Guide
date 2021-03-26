#include <iostream>
using namespace std;

int main(){
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
  int ans=0;
  string s;
  cin>>s;
  for(int i=0; i<52; ++i)
    for(int j=i+1; j<52; ++j)
      for (int k=j+1; k<52; ++k)
	for(int m=k+1; m<52; ++m)
	  ans+=s[i]==s[k]&&s[j]==s[m];
  cout<<ans;
}
