#include <iostream>
using namespace std;

const int MxN = 100;
string bessie, elsie, mother[MxN], daughter[MxN];
int N;

string find_mother(string cow){
	for(int i=0; i<N; ++i)
		if(daughter[i] == cow)
			return mother[i];
	return "";
}

int ancestor(string cow1, string cow2){ //find if cow1 is cow2 mother and returns many generations apart
	int count = 0;
	while(cow2 != ""){
		if(cow1 == cow2)
			return count;
		cow2 = find_mother(cow2);
		++count;
	}
	return -1;
}

int main(){
	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);

	cin >> N >> bessie >> elsie;
	
	for(int i=0; i<N; ++i)
		cin >> mother[i] >> daughter[i];

	string cow = bessie;
	int b = 0;
	while(cow != ""){ //finds the closest common ancestor, by seeing if cow's (bessie's) mother is an ancestor of elsie
		if(ancestor(cow, elsie) != -1)
			break;
		cow = find_mother(cow);
		++b;
	}
	if(cow == ""){
		cout << "NOT RELATED\n";
		return 0;
	}
	int a = ancestor(cow, elsie);
	if(a == 1 && b == 1) cout << "SIBLINGS\n"; //if the closest common ancestor is 1 mother away, they are siblings
	else if(a > 1 && b > 1) cout << "COUSINS\n"; //if the closest common ancestor is >1 mother away, they are cousins
	else{
		if(a > b) swap(elsie, bessie), swap(a, b); //swap due sentence structure
		cout<< elsie << " is the ";
		for(int i=0; i<b-2; ++i) cout << "great-";
		if(b > 1 && a == 0) cout << "grand-";
		if(a == 0) cout << "mother"; //is the closest common ancestor is 0 mothers away, bessie is the mother
		else cout << "aunt";
		cout << " of " << bessie << "\n";
	}
}
