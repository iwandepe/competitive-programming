#include <bits/stdc++.h>
using namespace std;
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",&t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int64 i,j,k;
int64 res;

void merge(int64 A[], int64 l, int64 m, int64 r){
    int64 n1 = m-l+1;
    int64 n2 = r-m;

    int64 L[n1],R[n2];
    FOR(i,0,n1,1)
        L[i]=A[l+i];
    FOR(j,0,n2,1)
        R[j]=A[m+1+j];

    i=0,j=0,k=l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
            res+=n1-i;
            // print64f("res-temp = %d\n", res);
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int64 A[], int64 l, int64 r){
    if(l>=r) return;
    int64 m = (l+r-1)/2;
    mergeSort(A,l,m);
    mergeSort(A,m+1,r);
    merge(A,l,m,r);
}

int main(){
    int64 tc,n;
    SCLLD(tc);
    while(tc--){
        SCLLD(n);
        int64 A[n];
        res=0;
        FOR(i,0,n,1){
            SCLLD(A[i]);
        }
        mergeSort(A,0,n-1);
        printf("%lld\n", res);
    }
    return 0;
}