#include <iostream>

using namespace std;
int n,a[100][100],p[100][100],s[100][100];
void citire()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
    cin>>a[i][j];
}
void dinamic()
{
    for(int i=n-1;i>=1;i--)
    for(int j=1;j<=i;j++)
    {
        if(s[i+1][j]>s[i+1][j+1])
        {
            s[i][j]=a[i][j]+s[i+1][j];
        p[i][j]=1;
        }
        else
        {
             s[i][j]=a[i][j]+s[i+1][j+1];
        p[i][j]=2;
        }
    }
}
void afisare()
{
    int q=1,r=1;
    cout<<"Suma maxima"<<s[1][1]<<"="<<a[1][1]<<"+";
    for(int i=1,j=1;i<n;i++)
    {
        if(p[i][j]==2)
        {
            r++;
            j++;
        }
        q++;
        cout<<a[q][r]<<"+";
    }
    cout<<"\b"<<" "<<endl;
}
int main() {
	citire();
	for(int i=1;i<=n;i++)
	s[n][i]=a[n][i];
	dinamic();
	afisare();
}
