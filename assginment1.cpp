/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
// Linked List declaration
struct Node{
    int data;
    Node *next;
    Node *prev;
};
// Function for displaying the Linked List
void display(Node *head){
    Node *ptr1=head;
    while(ptr1!=NULL){
        cout<<ptr1->data<<" ";
        ptr1=ptr1->next;
    }
}

//Function for inserting element in Linked List
Node* insert_ele(int pos, int val,Node *head){
    Node *ptr,*ptr1=head;
    Node *newNode=new Node;
    newNode->data=val;
    if(pos==1){
        newNode->next=head;
        newNode->prev=NULL;
        head=newNode;
    }
    else{
        for(int i=0;i<pos;i++){
            if(ptr1==NULL){
                return head;
            }
            ptr1=ptr1->next;
        }
        ptr=ptr1->prev;
        ptr->next=newNode;
        newNode->prev=ptr;
        newNode->next=ptr1;
        ptr1->prev=newNode;
        
    }
    return head;
    
}
//Function for removing element from Linked List
Node* remove_ele(int pos, Node *head){
    Node *ptr,*ptr1,*ptr2;
    if(pos==1){
        head=head->next;
    }
    else{
        ptr=head;
        for(int i=0;i<pos;i++){
            ptr=ptr->next;
        }
        ptr1=ptr->prev;
        ptr2=ptr->next;
        ptr->next=NULL;
        ptr->prev=NULL;
        ptr1->next=ptr2;
        ptr2->prev=ptr1;
    }
    return head;
}

//Function to find whether element is present
void find_ele(int tar, Node *head){
    Node *ptr=head;
    bool f=false;
    while(ptr!=NULL){
        if(tar==ptr->data){
            f=true;
            break;
        }
        ptr=ptr->next;
        
    }
    if(f==true){
        cout<<"Element found\n";
    }
    else{
        cout<<"Element not found\n";
    }
}

int main()
{
    int n,x;
    Node *head;
    Node *ptr1=NULL;
    cout<<"Enter the size of Linked List :";
    cin>>n;
    cout<<"\n";
    for(int i=0;i<n;i++){
        Node *ptr=new Node;
        cout<<"Enter element : ";
        cin>>x;
        if(i==0){
            ptr->data=x;
            ptr->next=NULL;
            ptr->prev=NULL;
            head=ptr;
        }
        else{
            ptr->data=x;
            ptr->next=NULL;
            ptr1->next=ptr;
            ptr->prev=ptr1;
        }
        ptr1=ptr;
        
    }
    //For inserting
    cout<<"List before inserting element : ";
    display(head);
    head=insert_ele(2,2,head);
    cout<<"\n";
    cout<<"Linked list after inserting element : ";
    display(head);
    cout<<"\n";
    
    //For removing
    cout<<"List before removing element : ";
    display(head);
    head=remove_ele(2,head);
    cout<<"\n";
    cout<<"Linked list after removing element : ";
    display(head);
    cout<<"\n";
    
    //For finding element
    find_ele(1,head);
    find_ele(10,head);
    return 0;
}