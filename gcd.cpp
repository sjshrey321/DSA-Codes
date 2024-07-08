#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if (b==0 ){return a;}
    else
    {
        if (a<b)
        {
            swap(a,b);
        }
        return gcd(b,a%b);
    }
}
int lcm(int a,int b)
{
    return a*b;
}
/*int main()
{
    int t;
    cin>>t;
    int ans[t];
    for (int q=0;q<t;q++)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        sort(arr,arr+n,greater<int>());
        for (int i=0;i<n-1;i++)
        {
            arr[i]=gcd(arr[i],arr[i+1]);
            //cout<<arr[i];
        }
        //cout<<arr[n-1];
        //cout<<endl;
        int sum=0;
        for (int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        ans[q]=sum;
        
        

    }
    for (int i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
}*/