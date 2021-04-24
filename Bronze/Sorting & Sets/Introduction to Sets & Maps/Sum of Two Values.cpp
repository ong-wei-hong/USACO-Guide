#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int n, x;

int main(){
  cin>>n>>x;

  for(int i=0; i<n; ++i){
    int a;
    cin>>a;
    if(m.count(x-a)){
      cout<<m[x-a]+1<<" "<<i+1;
      return 0;
    }
    m[a]=i;
  }
  cout<<"IMPOSSIBLE";
}
