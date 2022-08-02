#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << "\n";
    }
};
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}
void insertAtAfter(Node *&head, int key, int val)
{
    Node *newNode = new Node(val);
    if (key == head->data)
    {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
    Node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
        if (temp == NULL)
            return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtPosition(Node *&head, int position, int val)
{
    Node *newNode = new Node(val);
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    int i = 0;
    Node *temp = head;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}
void deleteAtPosition(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node *curr = head;
    Node *temp = NULL;
    int cnt = 1;
    while (cnt < position)
    {
        temp = curr;
        curr = curr->next;
        cnt++;
    }
    temp->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void reverseLinkedList(Node *&head)
{
    Node *curr, *prev, *next;
    curr = head;
    prev = next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
Node *reverseLinkedListinK(Node *&head, int k)
{
    int count = 0;
    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr and count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        head->next = reverseLinkedListinK(next, k);

    return prev;
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    printLinkedList(head);
    insertAtAfter(head, 5, 67);
    insertAtPosition(head, 2, 675);
    printLinkedList(head);
    deleteAtPosition(head, 5);
    printLinkedList(head);
    reverseLinkedList(head);
    printLinkedList(head);
    reverseLinkedList(head);
    printLinkedList(head);
    head = reverseLinkedListinK(head, 2);
    printLinkedList(head);
    return 0;
}
