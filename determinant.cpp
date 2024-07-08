#include<iostream>
#include<cmath>
using namespace std;
int det(int **a,int n) // so i have the ptr to an multi d array and the order of that matrix
{
    if (n==1)
    {
        return a[0][0];
    }
    else
    {
       /* first loop for all the elements except 0th row and 0th col and another loop for converting them to array  */  
        int d=0;
        for (int i=0;i<n;i++) //i is for the row for the first, row.
        {
            // now we need another for the particular column;
            int arr[n-1][n-1];
            // col!=0;
            int row=0;int t1=0;int t2=0;
            while (t1<n-1 and t2<n-1)
            {
                if (row==i)
                {
                    row++;
                }
                else if (t1==t2) 
                {
                    arr[t1][t2]=arr[row][t2+1];
                    t1++;
                    row++;// 
                }
                else if (t1>t2)
                {
                    arr[t1][t2]=arr[row][t2+1];
                    t2++;
                    row++;
                }
            }
            int *temp[n-1];
            for (int t=0;t<n-1;t++)
            {
                temp[t]=arr[t];
            }
            d+=a[i][0]*det(temp,n-1)*(pow(-1,i));
            
        }
        return d;
    }
}