# include <iostream>
//#include "node.cpp"
using namespace std;
class Node{
public:
int data;
Node *next;
    Node(int data)
    {
    this -> data = data;
    this->next = NULL ;
    }
};

Node*inputnode(){
        int data;
        cin>>data;
        Node*head= NULL;
        Node*tail=NULL;
        while(data!=-1){
            Node*newnode=new Node(data);
            if (head==NULL){
                head=newnode;
                tail=newnode;
            }
            else{
                /*Node*temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }*/
                tail->next=newnode;
                tail=newnode;
            }
            cin>>data;
            }
            return head;
        }
void print(Node*head){
while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
    }
}
int main(){
Node*head=inputnode();
print(head);
}
