#include <iostream>

using namespace std;

int main(){
	
	string s = "AAAAAAAAAAA";
	int n = s.size();
	
	int cntA = 0, cntB = 0, cntC = 0;
	for(int i=0; i<n; i++){
		switch(s[i]){
			case 'B': 
				cntB++;
				break;
			case 'A': 
				cntA++;
				break;
			case 'C': 
				cntC++;
				break;
		}
	}
	cout << cntA<<" "<< cntB << " " << cntC << endl;
	
	
	return 0;
}

/*
$ g++ --coverage tmp.cpp -c
$ g++ --coverage tmp.o
$ a.out
$ gcov tmp.cpp -m
*/
