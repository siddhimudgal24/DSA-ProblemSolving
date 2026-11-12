#include<bits/stdc++.h>
using namespace std;
// creating a class for Node structure
class Node{
    public:
    int data;
    Node* next;
    // creating a constructor for intialisation
    Node(int val){
        data = val;
        next = NULL;
    }
};
// creating a Node class will only create a node so we also have to create a List class
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    //in the List class we will implement the four functions = > push_front,pop_front,push_back,pop_back
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    List ll;
    ll.push_back(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printLL();
    return 0;
}