#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1){
       data=data1;
       next=NULL;
    }
};
Node* arrayTolinkedlist(vector<int>&a){
     Node* head= new Node(a[0]);
     Node* mover=head;
     for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i]);
        mover->next=temp;
        mover=temp;
     }
     return head;
}
void print(Node* head){
     while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* removeHead(Node* head){
    if(head==NULL)return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;

}
Node* removeTail(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
Node* insertKth(Node* head, int val, int K){
    if(head==NULL){
        if(K==1){
            Node* x=new Node(val);
            x->next=head;
            head=x;
        }
        return head;
    }
    if(K==1){
        Node* x=new Node(val);
            x->next=head;
            head=x;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt == K-1){
            Node* x=new Node(val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* removeKth(Node* head, int K){
    if(head==NULL)return head;
    if(K==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* temp=head,*pre=NULL;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==K){
          pre->next=temp->next;
          delete temp;
          return head;
        }
        pre=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>a={2,5,3,5,6,7};
    Node* head= arrayTolinkedlist(a); 
    Node* temp=head;
    print(head);
   // head=removeHead(head);
    //head=insertKth(head,4,5);
    head=removeKth(head,3);
    print(head);
}