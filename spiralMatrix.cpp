#include<iostream>
using namespace std;
int** spiralMatrix(int *a,int n,int sr,int er,int sc,int ec)
{   
    int **arr;
    static int t=0;
    // we need to variable start coloumn end coloumn start row and end row  
    // and then we need and function and then use it reccursively
    if (er<sr;ec<sc)
    {
        return 0;
    }
    else if (t==n)
    {
        return arr;
    }
    else 
    {   
        for (int i=sc;i<=ec;i++)
        {
            arr[sr][i]=a[i];
            t++;
        }
        for (int i=sr+1;i<=er;i++)
        {
            arr[i][ec]=a[n+i-1];
            t++;
        }
        for (int i=ec-1;i>=sc;i--)
        {
            arr[er][i]=a[ec-i+2*n];
            t++;
        }
        
        
        for (int i=er-1;i>sr;i--)
        {
            arr[i][sc]=a[i-er+3*n];
            t++;
        }
        sr++;sc++;er--;ec--;
        spiralMatrix(a,n,sr,er,sc,ec);
        
    }   
}
