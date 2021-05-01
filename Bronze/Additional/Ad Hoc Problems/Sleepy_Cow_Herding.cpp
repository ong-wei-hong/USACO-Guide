#include <iostream>
#include <algorithm>
using namespace std;

#define a cows[0]
#define b cows[1]
#define c cows[2]

int main(){
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  int cows[3];
  cin >> cows[0] >> cows[1] >> cows[2];
  sort(cows, cows + 3);
  
  if(c==a + 2) //cows are adjacent
    cout << 0 << endl;
  else if(c==b+2 || b==a+2) //cows are next to another with 1 space in between
    cout << 1 << endl;
  else //move 1 cow one space away from another, then move the other cow into the gap
    cout << 2 << endl;
  cout << max(b-a, c-b) - 1;
}
