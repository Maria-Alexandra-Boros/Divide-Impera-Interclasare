#include<fstream>
using namespace std;
ifstream f ("date.in");
ofstream g ("date.out");
int A[1001],n;
void citire()
{
    f>>n;
    for(int i=1; i<=n; i++)
        f>>A[i];
}
void sortare(int p, int q, int A[1001])
{
    int aux;
    if (A[p]>A[q])
    {
        aux=A[p];
        A[p]=A[q];
        A[q]=aux;
    }
}
void interclasare( int p, int q, int m, int A[1001])
{
    int b[1001], i,j,k;
    i=p;
    j=m+1;
    k=1;
    while(i<=m && j<=q)
        if(A[i]<A[j])
        {
            b[k]=A[i];
            i++;
            k++;
        }
        else
        {
            b[k]=A[j];
            j++;
            k++;
        }
    if(i<=m)
        for(int x=i; x<=m; x++)
        {
            b[k]=A[x];
            k++;
        }
    else
        for(int x=j; x<=q; x++)
        {
            b[k]=A[x];
            k++;
        }
    for(i=p,k=1; i<=q; i++,k++)
        A[i]=b[k];
}
void d_i(int p, int q, int A[1001])/// p=stanga, q=dreapta
{
    int mij;
    if(q-p<=1)
        sortare(p,q,A);
    else
    {
        mij=(p+q)/2;
        d_i(p,mij,A);
        d_i(mij+1,q,A);
        interclasare(p,q,mij,A);
    }

}
void afisare()
{
    for(int i=1; i<=n; i++)
    g<<A[i]<<' ';
}
int main ()
{
    citire();
    d_i(1,n,A);
    afisare();
    f.close();
    g.close();
    return 0;
}
