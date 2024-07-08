#include<iostream>
using namespace std;
//basic ll
class node
{
    public:
    int data;
    node *next;
    node(int data) {this->data=data;
    next=NULL;}            
};
int  size(node *head)
{
    int size=0;
    node *temp=head;
    while (temp!=NULL)
    {
        size++;
        temp= temp->next;
    }
    return size ;
}
void printLL(node *head)
{
    node *temp=head;
    while (temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<< endl;
}
void Ni(node *head, int data)
{
    node *temp= head;
    while (temp!=NULL)
    {
        temp=temp->next;    // h-4-5-8-null
    }
    node *temp1= new node(data);
    temp=temp1;

    

}
node* Inputs() // it adds the data on tail  // both head and tail element are required .
{
    /// @  more like to be used in stacks ;
    /// 
    int data;
    cin>> data;
    node *head=NULL;
    node *tail= NULL;
    while ( data!=-1)
    {
        if (head ==NULL)
        {
            node *n= new node(data);
            head= n;
            tail=n;
        }
        else
        {
            node *n= new node(data);
            tail->next=n;
            tail=n;

        }
        cin>>data;
    }
    return head ;
}
node* Rinputs()  // it adds the data from the head side more likely to used in the qouese
{
    int data; 
    cin>> data; 
    node *head=NULL;
    node *tail= NULL;
    while ( data!= -1)
    {
        if ( head==NULL)
        {
            node* n= new node(data);
            head= n;
            tail=n;
        }
        else 
        {
            node *n= new node(data);
            tail=head;
            head= n;
            head->next=tail;
        }
        cin>>data;
    }
    return head;
}
void ithNode( node *head, int i) // print the ith node ;
{
    node *temp = head;
    for (int j=1;j<i;j++)
    {
        temp=temp->next;
    }
    cout<<temp->data<<endl;

    
}
node* insertatI( node *head,int data, int i ) // insert the ith node ;
{
    node *temp=head;
    for (int j=1; j<i; j++)
    {
       temp= temp->next;
    }
    node *temp1= temp->next;
    node *n= new node(data);
    temp->next=n;
    n->next=temp1;
    return head;         
}
// here we haven't applied the condition for i greater than size in the code and also
// if i is less than 0.
node* dltatI(node *head,int i) // delete the ith node ;
{
    // this code has memory leak right new code without memory leak
    node *temp= head;
    for (int j=1;j<i;j++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
    
}
node* dltImd(node *head,int i )
{
    // just isolate the data and delete the node 
    node *temp= head;
    for (int j=1;j<i;j++)
    {
        temp=temp->next;
    }
    node *dlt= temp->next; // storing the data to be deleted in temporary variable 
    temp->next=temp->next->next; // neccessary condition for the code.
    dlt->next=NULL; // made the node to be deleted point towards null 
    delete dlt;
    return head;
        
}
// int main()
// {
//     // // static
//     // node *head= new node(4); 
//     // node one(5);
//     // head->next=&one;
//     // //dynamic 
//     // node *two= new node(8);
//     // one.next=two;
//     // // cout<<one.next->next<<endl;
//     // delete two;
//     // Ni(head,10);
//     // cout<<head->next->next->data;
//     // // cout<<head.data<<" "<<head.next->data<<endl;
//     // // cout<<head.next->next->data<<endl;
//     // //printLL(head); 
//     // // now we have two in the stack memory while node is in the heap 
//     // //cout<<two->data<<endl;
//     // // cout<<two->next<<endl


//     /* HEAD
//     it contains only address of the first node . 
//     ex:
//         node *head= new node(5);
//         now head points towards the first node ;
//         node *n1= new node(3);
//         head->next = n1;
//         delete n1;
//         */

//     node *head= Inputs();
//     printLL(insertatI(head,18 , 3));
//     printLL(dltatI(head,3));
    
// }