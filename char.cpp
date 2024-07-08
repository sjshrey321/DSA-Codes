#include<iostream>
#include<string>
using namespace std;
int length(char arr[])
{
    int i=0;
    while (arr[i]!='\0'){i++;}
    return i;   
}
void rev(char arr[])
{
    int n=length(arr);
    for (int i=0;i<n/2;i++)
    {
        swap(arr[i],arr[n-i-1]);
    }
    
}

int main()
{
    char a[4]={'s','r','e'};
    // cin.getline(a,100,','); // it adds null at the last element this the work of the get line that it takes all the character upto the set limit in which the last element will be the null character 
    //string b;
    //cin.getline(a,100);
    //cin>>a;
    //rev(a);
    char b[4]="shr";
    cout<<strlen(a)<<endl;
    cout<<b<<endl;
    //strcpy(a,"hell"); //it copies the null char
    strncpy(a,"hello",2); //it does not copies the null character
    cout<<a<<endl;
    cout<<strcmp(a,b)<<endl;
    strcat(a,b);
    cout<<a<<endl;
    if (strcmp(a,b)==1){cout<<"equal";} 
    a[5]='y';
    cout<<strlen(a);

}