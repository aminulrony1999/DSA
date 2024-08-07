#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *back;
    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};
Node *createDoublyLinkedList()
{
    int n;
    cout << "Enter number of nodes in the linked list : ";
    cin >> n;
    cout << "Enter the nodes : ";
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *prev = head;
    for (int i = 1; i < n; ++i)
    {
        cin>>x;
        Node *temp = new Node(x,nullptr,prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}
Node *deleteFirstNode(Node *head)
{
    if(head == NULL || head -> next == NULL)
    return NULL;
    Node *temp = head;
    head = head -> next;
    head -> back = nullptr;
    temp -> back = nullptr;
    delete temp;
    return head;
}
void printDoublyLinkedList(Node *head)
{
    Node *mover = head;
    while(mover != nullptr)
    {
        cout<< mover -> data<<" ";
        mover = mover -> next;
    }
}
int main()
{
    Node *head = createDoublyLinkedList();
    cout<<"Elements of the doubly linked list before deleting the first node : ";
    printDoublyLinkedList(head);
    head = deleteFirstNode(head);
    cout<<endl<<"Elements of the doubly linked list after deleting the first node : ";
    printDoublyLinkedList(head);
    return 0;
}