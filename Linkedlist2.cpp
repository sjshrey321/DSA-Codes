#include <iostream>
#include"LinkedList1.cpp"

using namespace std;

// Length of the LL using recursion.

int Mlength(node* head)
{
    // two conditions if head.next is NULL then the length is one. 
    if (head->next==NULL)
    {
        return 1;
    }
    else
    {
        return Mlength(head->next)+1;
    }
}

bool ispresent(node *head, int data)
{
    int temp=0;
    while ( head->next!= NULL)
    {
        if (head->data== data)
        {
            temp=1;
            break;
        }
        head=head->next;
    }
    if ( temp==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

// searching the element in the ll using recursion. 

bool search(node* head, int data)
{
    if (head->next==NULL)
    {
        if (head->data== data)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else
    {
        if ( head->data== data)
        {
            return 1;
        }
        else 
        {
             return search(head->next,data);
        }
    }
}

// reaching the mid node of the linked list 

// there are two ways one does the work in two transversal length and second does in 
// in the one transversal lenght 

// so for two transversal length we use size / length function. 

/* This is slow ptr fast ptr approach. */
// for one transversal we use slow and fast ptr aproach. 

node* midnode(node* head) // for even we have to return second middle node. 
{
    node *slow= head;
    node *fast= head->next;
    while ( fast->next!=NULL and fast!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    if (fast)// even 
    {
        return slow->next;
    }
    else return slow;
}

// reverse a linked list. 

/*  the approach is simple we use three var prev  current and n and then use the loop. */ 
node* RevLL(node* head)
{
    node *curr= head;
    node *prev=NULL;
    while (curr!=NULL)
    {
       node* n=curr->next;
       curr->next=prev;
       prev=curr;
       curr=n;
    }
    return prev;
}
node* dltRk(node* head,int k )
{
    //return RevLL(dltImd(RevLL(head),k));
    return dltImd(head,size(head)-k); // this code is in two traversal traversal 
    // what we want is in  one traversal and for that we use two variavbke 
    // and move them such that the diff bw them is always k. 
    
    
}

/* Merge Two sorted list using linked list. */

node* Mergetwolist(node* head1, node*head2)
{
    if (head1==NULL) return head2;
    if (head2==NULL) return head1;
    
    node * finalhead= NULL;

    if ( head1->data <= head2->data)
    {
        finalhead= head1;
        head1= head1->next;
    }
    else
    {
        finalhead = head2;
        head2= head2->next;
    }

    node *temp = finalhead;

    while ( head1 and head2 )
    {
        if ( head1->data < head2->data)
        {
            temp->next= head1; 
            temp = head1; 
            head1= head1->next; 

        }
        else 
        {
            temp->next= head2;
            temp = head2;  
            head2 = head2->next; 
           
        }
    }

    if ( head1) temp->next=head1;
    if (head2) temp->next= head2; 

    return finalhead; 

}

node* MergeRec(node* head1, node* head2)
{
    
}

int main()
{
    node *head= Inputs();
    printLL(head);
    printLL(dltRk(head,1));
    
}
