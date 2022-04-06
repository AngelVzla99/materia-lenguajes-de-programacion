#include <bits/stdc++.h>

#define FOR(i,n,m) for(int i=n; i<m; i++)

using namespace std;

struct tipo{
    string name;
    int rep, ali;
    string tipo, subTipo;
    vector<string> listStruct;
};

bool haveBeenDeclare( string name );
int addAtomic( string name, int representacion, int alineacion );
int addStruct( string name, vector<string> lista );
int addArray( string name, string t, int tamano );
int getEnd( string t, int op, int &cu );
int getDesperdicio( string name, int po );