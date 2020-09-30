#include<bits/stdc++.h>
using namespace std;

void parenthesis(int i,int j,int n,int* brackets,char &symbol)
{
    if(i==j)
    {
        cout<<symbol++;
        return;
    }
    cout<<"(";
    parenthesis(i,*((brackets+i*n)+j),n,brackets,symbol);
    parenthesis(*((brackets+i*n)+j)+1,j,n,brackets,symbol);
    cout<<")";
}

void order(int p[],int n)
{
    int arr[n][n];
    int brackets[n][n];
    for(int i=1;i<n;i++)
    {
        arr[i][i]=0;
    }
    for (int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            arr[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=arr[i][k]+arr[k+1][j]+p[i-1]*p[k]*p[j];
                if (q<arr[i][j])
                {
                    arr[i][j]=q;
                    brackets[i][j]=k;
                }
            }
        }
    }
    char symbol='A';
    cout<<"Optimal Parenthesization is: ";
    parenthesis(1,n-1,n,(int*) brackets,symbol);
    cout<<"\nOptimal Cost is: "<<arr[1][n-1];
}

int main()
{
    int arr[100000];
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    cout<<"Enter the dimensions of matrices: ";
    for(int i=0;i<n+1;i++) {
        cin>>arr[i];
    }
    order(arr,n+1);
    return 0;
}