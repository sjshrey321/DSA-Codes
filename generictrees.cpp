#include<iostream> 
#include<vector>
#include<queue>
using namespace std; 


class node{
    public:
    int data; 
    vector<node*> child ; 
    node(int data) 
    {
        this->data= data;

    }
    ~node()
    {
        for(int i=0; i<child.size();i++)
        {
            delete child[i];
        }
    }
    
    

};

// print recursive 'hy
void printRec(node* n){
        cout<<n->data <<":";  
        for (int i=0 ; i< n->child.size(); i++)
        {
            cout<<n->child[i]->data<< " ";
        }
        cout<<endl;
        for (int i=0; i< n->child.size(); i++)
        {
            printRec( n->child[i]);
        }
    };
// taking inputs using recursion () pov: not a good way. // because you need to remember the 
// the recursion.  
 node* takeinput()
 {
    int rootData; 
    cout<<"Enter Data"; 
    cin>> rootData; 
    node *root= new node(rootData);
    int n; 
    cout<<" How many Children" ; 
    cin>> n;  
    for (int i=0; i<n; i++)
    {
        node* child= takeinput();
        root->child.push_back(child);
    }
    return root;
    
 }

 // take input level wise 
 // using queue //
 node* TakeInputsLevelWise()
 {
    int rootdata; 
    cout<< " Enter the Root Data "; 
    cin>>rootdata; 
    node* root= new node(rootdata) ; 
    queue<node*> q; 
    q.push(root); 
//  three main steps : 
    // 1; create a node
    // 2; push the node
    // 3; connect the node
    while ( !q.empty())
    {
        node* f = q.front(); 
        q.pop(); 
        cout<< " Enter no of children for "<< f->data; 
        int n; 
        cin>>n;
        for( int i =0 ; i<n ; i++)
        {
            int childdata; 
            cout<<" Enter Data of "<< i<<" the child of " << f->data<< endl; 
            cin>> childdata; 

            node* child= new node(childdata) ;
            q.push(child); 
            f->child.push_back(child); 

        }
    }
    return root; 

 }

 void PrintLevelWise(node *root){
    queue<node*> q; 
    q.push(root); 
    while(!q.empty())
    {
        node* f= q.front(); 
        q.pop(); 
        cout<<f->data<<":"; 
        int n = f->child.size(); 
        for (int i=0 ; i<n; i++) 
        {
            q.push(f->child[i]);
            cout<<(f->child[i]->data)<<" ";
        }
        cout<<endl;
        delete f;
    }
 }

 int countnodes(node* root)
 {
    int ans = 1 ; 
    for( int i = 0 ; i< root->child.size(); )
    {
        ans+= countnodes(root->child[i]);
    }
    return ans; 
 }

 int height(node* root)
 {
    int ans= 0; 
    for (int i = 0 ; i<root->child.size();i ++) 
    { 
        int h= height(root->child[i]);
        if ( ans<h)
        {
            ans= h;
        }
    }
    return ans +1;
 }

 void printKlevel(node* root, int k ) 
 {
    if (k==0) 
    {
        cout<<root->data<<" ";
        return;
    } 
    else
    {
        for (int i=0 ; i<root->child.size(); i++) 
        {
            printKlevel(root->child[i],k-1);
        }
    }
 }

 int CountLeafNode( node* root) 
 {
    if(root->child.size()==0)
    {
        return 1; 
    }
    int ans=0; 
    for( int i =0 ; i<root->child.size(); i++) 
    {
        ans+=CountLeafNode(root->child[i]);
    }
    return ans;
 }

 vector<int> inordertraversal(node* root) 
 {
    vector<int> ans;
    ans.push_back(root->child[0]->data);
    ans.push_back(root->data); 
    ans.push_back(root->child[1]->data); 
    while(root->child.size()!=0)
    {
        node* root1=root->child[0];
        node* root2= root->child[1];
        
    }
 }

 void PreOrderTransversal( node* root)
 {
    if (root==NULL) return ; 
    cout<<root->data<<endl;
    for (int i=0; i<root->child.size(); i++)
    {
        PreOrderTransversal(root->child[i]);
    }
 }

 void PostOrderTransversal(node* root)
 {
    if ( root==NULL ) return ; 
    for (int i=0 ; i<root->child.size();i++)
    {
        PostOrderTransversal(root->child[i]); 
    }

    cout<<root->data<<endl;
 }

void deleteTree(node* root)
{
    if (root==NULL) return ; 

    for (int i = 0 ; i<root->child.size(); i++)
    {
        deleteTree(root->child[i]);
    }
    delete root;

}
int main() 
{
    // node* root= new node(5); 
    // node* n1= new node(2);
    // node* n2= new node(3);
    // node* n3= new node(4);
    // root->child.push_back(n1);  
    // root->child.push_back(n2);
    // n1->child.push_back(n3); 
    // printRec(root);

    node* root= TakeInputsLevelWise(); 
    PostOrderTransversal(root);




    
}

