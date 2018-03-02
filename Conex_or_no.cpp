#include <iostream>
#include <fstream>
using namespace std;
 int M[100][100]={{0, 1, 0, 0, 1},{1, 0, 1, 0, 1},{0, 1, 0, 1, 0},{0, 0, 1, 0, 1},{1, 1, 0, 1, 0}};
// int M[100][100]={{0, 0, 0, 0, 0},{0, 0, 1, 0, 1},{0, 1, 0, 1, 0},{0, 0, 1, 0, 1},{0, 1, 0, 1, 0}};
// int M[100][100]={{0, 1, 0, 0, 0},{1, 0, 1, 0, 0},{0, 1, 0, 0, 0},{0, 0, 0, 0, 1},{0, 0, 0, 1, 0}};
int n = 5;
int ST[100];
int varf;
int ultim;

/*
int read_data()
{
ifstream f;
f.open("input.dat");
f>>n;
for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
       {f>>M[i][j];}
    }
    f.close();
}
*/

int tipar(int ST[100],int varf)
{
    return 1;
}

int solutie(int ST[100], int varf) {
    return varf == n;
}

int succesor(int ST[100], int varf) {
    for(int i = ultim; i < n; i++) {
        if(M[ST[varf-1]][i]) {
            ST[varf] = i;
            return 1;
        }
    }
    return 0;
}

int valid(int ST[100], int varf) {
    for(int i = 0; i < varf; i++) {
        if(ST[varf] == ST[i]) {
            ultim = ST[varf]+1;
            return 0;
        }
    }
    return 1;
}

int init(int ST[100], int varf) {
    ultim = 0;
}

int DFS_REC(int ST[100],int varf) {
    if (solutie(ST,varf)) { return tipar(ST,varf); }
    while ( succesor(ST,varf) ) {
        if (valid(ST,varf)) {
            init(ST,varf+1);
            return DFS_REC(ST,varf+1);
        }
    }
    return 0;
}


int main() {
    ST[0] = 0;
    varf = 1;
    cout << DFS_REC(ST, varf);
    return 0;
}
