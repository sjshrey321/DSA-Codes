#include<iostream>
#include<vector>
using namespace std; 

class btnode{
    public: 
    int data; 
    btnode* left; 
    btnode* right; 

    // constructor 
    btnode( int data) 
    {
        this->data= data;
        left= NULL; 
        right= NULL;
    }
    ~btnode()
    {
        delete left;
        delete right;
    }
};

btnode* searchbst(btnode* root, int val)
{
    if (root==NULL) return NULL;
    if (root->data==val) return root; 
    if (val<root->data)
    {
        return searchbst(root->left,val);
    }
    if (val>root->data) return searchbst(root->right,val); 
    return NULL;
}

// now iterative  

btnode* searchIbst(btnode* root,int val) 
{
    if (root==NULL) return NULL; 
    while (root!=NULL)
    {
        if (root->data==val) return root;
        if (val<root->data) root=root->left;
        if (val> root->data) root= root->right;

    }
    return NULL;
}

int minBST(btnode* root) 
{
    if (root==NULL) return -1; 
    while( root->left!=NULL) 
    {
        root=root->left;
    }
    return root->data;
}
// max value 
int maxBST(btnode* root) 
{
    if (root==NULL) return -1; 
    while( root->right!=NULL) 
    {
        root=root->right;
    }
    return root->data;
}

// sum of all the nodes in the range [l,r]; 

int rangeSumBST(btnode* root, int l, int r ) 
{
    if(root==NULL) return 0;
    
    int sum=0; 

    if (root->data>=l && root->data<= r)
    {
        sum+=root->data;
    }
    if (root->data>r)
    {
        sum+=rangeSumBST(root->left,l,r); 

    }
    else if ( root->data<l) sum+= rangeSumBST(root->right,l,r);

    else sum+= rangeSumBST(root->left,l,r) + rangeSumBST(root->right,l,r); 

    return 0;

}

int inordersuccessor(btnode* root, int key)
{
    if(root==NULL) return -1; 
    int successor = 0 ; 
    while (root!=NULL)
    {
        if(root->data> key) 
        {
            successor = root->data; 
            root= root->left; 
        }
        else if(root->data< key)
        {
            root= root->right;
        }
        else if(root->data==key)
        {
            root= root->right;
        }

    }
    return successor;
}

bool validateBST(btnode* root,long long minv=-10000000000, long long maxv=10000000000)
{
    // three conditions 
    // left side< node
    // right side> node.
    // first is very simple ways is that we take inorder traversal and store it in an 
    /* array and then if arr is sorted that implies that we have an 
    sorted array but rather than arr we have the two pointer approach.*/
    
    /* second approach is that we use range system that for the root we start with range -inf to inf as we go left range 
    is equal to -inf,root and as we go right we have the range root,inf if all the nodes fit in their resp ranges than we 
    have a bst.. */
    if (root==NULL) return true ; 
    if (root->data>=maxv or root->data<=minv)
    {
        return false;
    }
    bool l= validateBST(root->left,minv,root->data);
    bool r= validateBST(root->right,root->data,maxv);
    return l+r; 

}

// construct bst from an sorted array 

btnode* sArrtoBST(vector<int> arr, int s, int e) 
{
    if(arr.empty() or s>e) return NULL; 
    int mid= (s+e)/2;
    btnode* root= new btnode(arr[mid]);
    root->left=sArrtoBST(arr,s,mid-1);
    root->right=sArrtoBST(arr,mid+1,e); 
    return root;

}

// new class bst with more function like insert and delete and search and print etc; 

class BST{
    btnode* root;
    void printRecBT(btnode* root)
    {      
        if(root==NULL) return; 
        cout<<root->data<<":";
        if(root->left!=NULL) cout<<'l'<<root->left->data<<" ";
        if(root->right!=NULL) cout<<'r'<<root->right->data;
        cout<<endl;
        printRecBT(root->left); 
        printRecBT(root->right);
    }
    bool hasData(btnode* root,int data) 
    {
        if(root==NULL) return false; 
        if (root->data==data) return true ; 
        if (root->data> data) return hasData(root->left,data);
        else if (root->data< data) return hasData(root->right,data) ; 
        return false;
    }

    btnode* insert(btnode* root, int data) 
    {
        // we need to provide back the updated root. 
        if (root==NULL) 
        {
            btnode* node= new btnode(data); 
            return node;
        }

        if(root->data > data) root->left=insert(root->left,data);
        if(root->data < data) root->right=insert(root->right,data);


        return root;
    }

    btnode* deleteData(btnode* root, int data) 
    {
        if (root==NULL) return NULL; 
        if (data > root->data)
        {
            root->right= deleteData(root->right,data);
        }
        else if ( data < root->data) 
        {
            root->left= deleteData(root->left,data);                  
        }
        else 
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root; 
                return NULL;
            }
            else if ( root->left==NULL)
            {
                btnode* n= root->right;
                root->right=NULL; 
                delete root;                                                                   
                return n ;                 
            }

            else if ( root->right==NULL) 
            {
                btnode* n = root->left; 
                root->left= NULL; 
                delete root; 
                return n ; 

            }
            else 
            {
                btnode* minN= root->right; 
                while(minN->left!=NULL)
                {
                    minN = minN->left; 
                }
                root->data=minN->data; 
                root->right=deleteData(root->right,minN->data);
                return root; 
            }

        }
        return root; 
    }

    pair<btnode*,btnode*> bstLL(btnode* root) // first = head, second = tail. 
    {
        if(root->left==NULL && root->right==NULL)
        {
            pair<btnode*,btnode*> p; 
            p.first = root; 
            p.second =root; 
            return p; 

        }
        else if( root->right==NULL) 
        {
            pair<btnode*,btnode*> leftll= bstLL(root->left);
            leftll.second->right= root; 
            pair<btnode*,btnode*> ans; 
            ans.first= leftll.first; 
            ans.second=root;
            return ans ;
        }
        else if( root->left==NULL) 
        {
            pair<btnode*,btnode*> rightll= bstLL(root->right);
            root->right=rightll.first;
            pair<btnode*,btnode*> ans; 
            ans.first=root;
            ans.second=rightll.second;
            return ans ;
        }

        else 
        {
            pair<btnode*,btnode*> leftll= bstLL(root->left);
            pair<btnode*,btnode*> rightll= bstLL(root->right); 
            leftll.second->right=root;
            root->right=rightll.first;
            pair<btnode*,btnode*> ans; 
            ans.first=leftll.first; 
            ans.second=rightll.second; 
            return ans;
        }
    }

    public:
    BST()
    {
        root=NULL;

    }
    ~BST()
    {
        delete root;
    }
    
    void dlt(int data)
    {
        deleteData(root,data);
    }

    void insert(int data)
    {
        root=insert(root,data);
    }

    bool search(int data) 
    {
        return hasData(root,data); 
    }

    void printTree()
    {
        printRecBT(root);  
    }

// converting the bst into sorted linked list. 
    btnode* BSTtoSLL()
    {
        pair p= bstLL(root); 
        // now we make left pointer null for every node; 
        btnode* temp= p.first;
        while(temp)
        {
            temp->left==NULL; 
            temp=temp->right;
        } 
        return p.first;  

    }

};

int main()
{
    BST b; 
    b.insert(10);
    b.insert(11);
    b.insert(4);
    b.insert(6);
    b.insert(7); 
    b.dlt(4);

    b.printTree(); 

    return 0; 

}



