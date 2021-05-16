#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string cows[8]={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<int> beside[8];
bool done[8]={0};

int getIndex(string s){
	for(int i=0; i<8; ++i)
		if(cows[i]==s)
			return i;
	return -1;
}

int main(){
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	
	sort(cows, cows+8); //sort the cows to alphabetical order
	
	cin>>N;

	string a, b, temp;
	for(int i=0; i<N; ++i){
		cin>>a>>temp>>temp>>temp>>temp>>b;
		int aa=getIndex(a); //convert the strings to num 0..7
		int bb=getIndex(b);
		beside[aa].push_back(bb);
		beside[bb].push_back(aa);
	}

	vector<int> ans;

	for(int i=0; i<8; ++i){
		if(!done[i] && size(beside[i])<=1){ //find an edge or standalone cow
			int curr=i;
			while(size(beside[curr])==1){ //iterates through the path
				ans.push_back(curr);
				done[curr]=1;
				int next=beside[curr][0];
				beside[next].erase(find(beside[next].begin(), beside[next].end(), curr)); //remove curr so it does not repeat
				curr=next;
			}
			ans.push_back(curr);//handles the other edge / standalone cow
			done[curr]=1;
		}
	}

	for(int &i: ans)
		cout<<cows[i]<<"\n";
}
