#include <iostream>
using namespace std;

int MAX=1e9;

struct Cow{
  int stop_time;
  int x, y;//curr coordinates
  char dir;//N or E
};

int N;
Cow C[50];

int next_event(int i, int j, int current_time){ //generates the time when i and j has an event
  Cow I = C[i], J = C[j];
  if (I.dir == J.dir) return MAX; //would not reach each other
  if (I.dir == 'E') { //assumes i is N and j is E
    swap (I.x, I.y);
    swap (J.x, J.y); 
  }
  if (J.y <= I.y) return MAX;//j is below i's path
  if (J.stop_time == MAX) {
    if (I.x < J.x - current_time || I.x >= J.x + J.y - I.y) return MAX;//i is left of j's path OR i would not be stuck in j's rut
  } else {
    if (I.x > J.x || I.x < J.x - J.stop_time) return MAX;// i is right of stationary j OR left of j's path
  } 
  return current_time + J.y - I.y;
}

int main(){
  cin>>N;
  for(int i=0; i<N; ++i){
    cin>>C[i].dir>>C[i].x>>C[i].y;
    C[i].stop_time=MAX;
  }

  int current_time=0;
  while(1){
    int T[50], minT=MAX;//T stores the time when the ith cow undergoes an event
    for(int i=0; i<N; ++i){ 
      T[i]=MAX;
      if(C[i].stop_time==MAX){
	for(int j=0; j<N; ++j){
	  int t=next_event(i, j, current_time);
	  T[i]=min(T[i], t);//compares all t to find next event for cow i
	}
	minT=min(T[i], minT);//compares all T[i] to get next event
      }
    }
    if(minT==MAX) break;//no more events
    for(int i=0; i<N; ++i){
      if(C[i].stop_time==MAX)
	if(C[i].dir=='N') C[i].y+=minT-current_time;
	else C[i].x+=minT-current_time;
      if(T[i]==minT) C[i].stop_time=minT;
    }
    current_time=minT;
  }

  for(int i=0; i<N; ++i)
    if(C[i].stop_time==MAX) cout<<"Infinity\n";
    else cout<<C[i].stop_time<<endl;			    
}
 
