#include<iostream>
#include<cmath>
#include<climits>
#define askint(n) long n; cin>>n;
#define askstring(s) string s; cin>>s;
#define askarr(a,n) int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define showarr(a, n) for(int i=0; i<n ; i++) cout<<a[i]<<' '; cout <<endl;
#define foi(a,b) for(int i=a; i<b; i++)
#define foir(a,b) for(int i=a; i>=b; i--)
#define fojr(a,b) for(int j=a; j>=b; j--)
#define foj(a,b) for(int j=a; j<b; j++)
#define ll long long int 
using namespace std;

int main(){
    askint(t);
    while(t--){
        long n,k; 
        cin>>n>>k;
        int size=n;
        if(k>1) size=2*n; 
        int arr[size];
        long currsum=0; 
        long arrsum=0;
        long Maxsum=LONG_MIN; 
        for(long i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if (size==2*n)
        { 
            for(long i=n; i<size; i++)
            {
                arr[i]=arr[i-n];
            }
        }
        for(long i=0; i<size;i++)
        {
            currsum+=arr[i];
            Maxsum=max(currsum,Maxsum);
            if(currsum<0) currsum=0;
        }
        for(long i=0;i<n;i++)
        {
            arrsum+=arr[i];
        }
        if ( arrsum>0 && k>1) cout<< Maxsum+(k-2)*arrsum<<endl;
        else cout<<Maxsum<<endl;
    }
    return 0;
}