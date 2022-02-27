#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

struct memManager{
	int len;
	vector<string> mem;
};

memManager *crearManejador( int len );
int reservar( memManager *manager, string name, int len );
int liberar( memManager *manager, string name );
void show( memManager *manager );
