# include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};


Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *reverse(Node *head)
{
    Node * prev = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *addOneUtil(Node *head)
{
    // res is head node of the resultant list
    Node* res = head;
    Node *temp, *prev = NULL;

    int carry = 1, sum;

    while (head != NULL)
    {
        // Calculate value of next digit in resultant list.
        sum = carry + head->data;

        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        head->data = sum;

        // Move head and second pointers to next nodes
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}

Node* addOne(Node *head)
{
    head = reverse(head);

    head = addOneUtil(head);
    return reverse(head);
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);

    cout << "List is ";
    printList(head);

    head = addOne(head);

    cout << "\nResultant list is ";
    printList(head);

    return 0;
}
