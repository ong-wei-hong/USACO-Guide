#include <iostream>
#include <string>
using namespace std;

int N, seen[26*26*26*26];

int index(string s){
  int index = 0;
  for(char& c : s)
    index = index * 26 + c - 'A';
  return index;
}

int main(){
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);

  cin >> N;
  int ans = 0;
  for(int i=0; i < N; ++i) {
    string city, code;
    cin >> city >> code;
    city = city.substr(0, 2);
    if(city != code)
      ans += seen[index(city + code)];
    ++seen[index(code + city)];
  }
  cout<<ans;
}
