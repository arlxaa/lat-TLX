#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Org{
	string name;
	int tpoint;
	int tpen;
};


int main(){
	int n;
	cin>>n;
	vector<Org> org(n);
	
	for (int i = 0 ; i < n ; i++){
		string name;
		int a, b, c, d;
		cin >> name>>a>>b>>c>>d;
		
		org[i].name = name;
		org[i].tpoint = a + c;
		org[i].tpen = b+d;
		
	}
	
	for (int i = 0 ; i < n-1 ; i++){
		for (int j = 0 ; j < n-1-i;j++){
			int nswap = 0;
			if (org[j].tpoint < org[j+1].tpoint){
				nswap=1;
			} else if (org[j].tpoint == org[j+1].tpoint){
				if (org[j].tpen > org[j+1].tpen){
					nswap = 1;
				} else if (org[j].tpen == org[j+1].tpen){
					if (org[j].name > org[j+1].name){
						nswap=1;
					}
				}
			}
			if (nswap==1){
				Org temp = org[j];
				org[j]= org[j+1];
				org[j+1] = temp;
			}
			
			
		}
	}
	
	for (int i = 0 ; i < n ; i++){
		cout <<org[i].name<<"\n";
	}
	
}

















