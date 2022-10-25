#include <iostream>
using namespace std;
#include "node_class.cpp"

node *count(node *head, int targ){
int count=0;
node *temp = head;
node *target;
node *prev=NULL;
while (temp->next!=NULL)    
{
    if(temp->data == targ){
      count++;
      if(temp==head){
         target = temp;
         prev= temp;
         temp = temp->next;
         head = temp;
         delete target;
      }
      else{
        
       target = temp;
       temp = temp->next;
       delete target;

      }
    }
}

cout<<count;
return head;

}

node*reverse(node*head){

if(head->next==NULL || head==NULL){
    return head;
}

node *smallanswer = reverse(head->next); 
node*temp = smallanswer;

while(temp->next!=NULL){
temp = temp->next;
}
temp->next = head;
head->next = NULL;

    return smallanswer;
}

node*merge(node*h1, node*h2){

if (h1!=NULL && h2==NULL)  
{
    return h1;
}
else if(h1==NULL && h2!=NULL){
    return h2;
}
else if(h1==NULL && h2==NULL){
    return NULL;
}


node* dumy = new node; 
node *p3 = dumy;

if(h1->data<h2->data){
   dumy->next = h1;
    h1 = h1->next;
   p3 = p3->next;
}
else if(h1->data>h2->data){
    dumy->next = h2;
    h2 = h2->next;
    p3 = p3->next;
}

while(h1!=NULL && h2!=NULL){

if(h1->data<=h2->data){
    
p3->next = h1;
h1=h1->next;
p3= p3->next;

}

else if(h2->data<=h1->data){
    
p3->next = h2;
h2=h2->next;
p3 = p3->next;
}

}

if(h1!=NULL){
    p3->next = h1;
}else if (h2!=NULL)
{
     p3->next = h2;
}

    return dumy->next;

}




node* takeinput(){
node *head=NULL;
node *temp;
int choice;
cout<<"Want to enter data(0/1)"<<endl;
cin>>choice;
while(choice==1){
    node *n = new node;
    cout<<"Enter your data"<<endl;
    cin>>n->data;
    if(head==NULL){
     head=n;
     temp=head;
    }
else{
temp->next=n;
temp= temp->next;
temp->next=NULL;
}
cout<<"Want to enter data(0/1)"<<endl;
cin>>choice;

}
    return head;
}



void print(node *head){

node* temp=head;
while (temp!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->next;

}


}


int main(){
    //statically
    // node n1(10);
    // node *head = &n1;
    // node n2 (20);
    // n1.next= &n2;
    // node n3(30);
    // node n4(40);
    // node n5(50);
    // node n6(60);
    // n2.next= &n3;
    // n3.next= &n4;
    // n4.next= &n5;
    // n5.next= &n6;
    // n6.next = NULL;
node *head1 = takeinput();
print(head1);
cout<<endl;
node*head2 = takeinput();
print(head2);
cout<<endl;

node*head3 = merge(head1, head2);
print(head3);
// node *head2 = takeinput();
// print(head2);

// node*head4 = reverse(head1);
// cout<<endl;
// print(head4);

// node*head3 = merge(head1, head2);
// print(head3);
// cout<<head->data<<endl;
// head = head->next;
// cout<<head->data<<endl;

//dynamically

// node *n3 = new node(40);
// node *n4 = new node(50);

// cout<<n3->data;
// cout<<n4->data;
// n3->next = n4;
// n4->next=NULL;
}