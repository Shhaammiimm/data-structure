#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *pre,*next;
    Node(int val){
        data=val;
        pre=NULL;
        next=NULL;
    }
};
Node* arrayTolinkedlist(vector<int>&a){
     Node* head= new Node(a[0]);
     Node* mover=head;
     for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i]);
        mover->next=temp;
        temp->pre=mover;
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
Node* insertKth(Node* head, int K, int val){
    
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
    Node* temp=head,*prev=NULL;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==K){
          prev->next=temp->next;
          temp->next->pre=prev;
          delete temp;
          return head;
        }
        prev=temp;
        temp=temp->next;
    }
    cnt++;
    if(cnt==K){
        delete temp;
        prev->next=NULL;
    }
    return head;
}
int main(){
    vector<int>a={3,5,2,6,8,4};
    Node* head=arrayTolinkedlist(a);
    print(head);
    head=removeKth(head,6);
    print(head);
}