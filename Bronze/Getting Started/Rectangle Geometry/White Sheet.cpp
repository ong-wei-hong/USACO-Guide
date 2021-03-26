#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define x first
#define y second
#define ll long long

pair<ii, ii> intersect(ii a, ii b, ii c, ii d){
  int l, r, u, d2;
  l=max(min(a.x, b.x), min(c.x, d.x));
  r=min(max(a.x, b.x), max(c.x, d.x));
  u=min(max(a.y, b.y), max(c.y, d.y));
  d2=max(min(a.y, b.y), min(c.y, d.y));

  if(r<=l||u<=d2)
    return{{0, 0}, {0, 0}};
  
  return {{l, d2}, {r, u}};
}

ll area(ii a, ii b){
  ll val=1LL * abs(a.x-b.x) * abs(a.y-b.y);
  return val;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<ii> p(6);
  for(int i=0; i<6; ++i)
    cin>>p[i].x>>p[i].y;

  pair<ii, ii> i1=intersect(p[0], p[1], p[2], p[3]);
  pair<ii, ii> i2=intersect(p[0], p[1], p[4], p[5]);
  pair<ii, ii> i3=intersect(i1.x, i1.y, i2.x, i2.y);

  ll areawhite=area(p[0], p[1]);
  ll areai1=area(i1.x, i1.y);
  ll areai2=area(i2.x, i2.y);
  ll areai3=area(i3.x, i3.y);

  if(areawhite>areai1+areai2-areai3) //if the area of white is more than the intersection of the intersection with black 1 and white and the intersection between black 2 and white, white can be seen
    cout<<"YES";
  else
    cout<<"NO";
}
