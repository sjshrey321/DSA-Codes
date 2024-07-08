#include<iostream>
#include<vector>
#include<string> 
using namespace std; 

class trieNode{
    public:
    bool terminal; 
    trieNode* child[26]; 
    trieNode()
    {
        terminal= false ; 
        for(int i =0 ; i<26; i++)
        {
            child[i] = NULL;
        }
    }
};

void add(string s, trieNode* root)
{
    int n = s.length(); 
    for (int i = 0; i<n ;i++)
    {
        if(root->child[s[i]-'A']==NULL)
        {
            root->child[s[i]-'A']= new trieNode(); 
        }
        root= root->child[s[i]-'A'];

    }
    root->terminal= true; 

    
}

bool search(string s, trieNode* root) 
{
    int n = s.size();
    for(int i=0; i<n;i++)
    {
        if(root->child[s[i]-'A']==NULL) return false;
        root= root->child[s[i]-'A'];

    }
    return root->terminal;
}
