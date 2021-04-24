#include <iostream>
#include <map>
using namespace std;

int N;
string animals[12]={"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, int> year; //year[a] = b means cow a is born in year b (relative to bessie = 0)

//commented my code as answer is faster

/*int getAnimal(string animal){
  for(int i=0; i<12; ++i)
    if(animals[i]==animal)
      return i;
  return -1;
  }*/

string getAnimal(int year){
  int index=0, y=0;
  while(y<year){
    ++y;
    ++index;
    if(index==12) index=0;
  }
  while(y>year){
    --y;
    --index;
    if(index==-1) index=11;
  }
  return animals[index];
}

int main(){
  cin>>N;
  year["Bessie"]=0;
  /*while(!year.count("Elsie")){
    string cow1, time, animal, cow2, temp;
    cin>>cow1>>temp>>temp>>time>>animal>>temp>>temp>>cow2; //Mildred born in previous Dragon year from Bessie
    if(time=="previous"){
      int diff=year[cow2]-getAnimal(animal);
      while(diff<=0)
	diff+=12;
      while(diff>12)
	diff-=12;
      year[cow1]=year[cow2]-diff;
    }else{ //time=="next"
      int diff=getAnimal(animal)-year[cow2];
      while(diff<=0)
	diff+=12;
      while(diff>12)
	diff-=12;
      year[cow1]=year[cow2]+diff;
    }
    }*/
  string cow1, time, animal, cow2, temp;
  for(int i=0; i<N; ++i){
    cin>>cow1>>temp>>temp>>time>>animal>>temp>>temp>>cow2; //Mildred born in previous Dragon year from Bessie
    year[cow1]=year[cow2];
    do{
      if(time=="previous") --year[cow1];
      else ++year[cow1];
    }while(getAnimal(year[cow1])!=animal);
  }
  cout<<abs(year["Elsie"]);
}
