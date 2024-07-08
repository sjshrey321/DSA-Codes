// same differences codeforces 
#include<iostream>
#include<cmath>
#include<unordered_map>
#define askint(n) int n; cin>>n;
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
        int n ;
        cin>>n; 
        askarr(arr,n);
        int ans=0;
        unordered_map<int,int> mp; 
        foi(0,n)
        {
            if(mp.find(arr[i]-i)!=mp.end())
            {
                ans+=mp[arr[i]-i]%1000000007;
            }
            mp[arr[i]-i]+=1;
        }
        cout<<ans%1000000007<<endl;

    }
    return 0;
}