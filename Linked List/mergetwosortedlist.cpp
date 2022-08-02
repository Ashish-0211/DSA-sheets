#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
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
        cout << "The deleted value is :" << value << "\n";
    }
};
void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
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
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
void input(Node *&head, int size)
{
    int data;
    while (size--)
    {
        cin >> data;
        insertAtTail(head, data);
    }
}
Node *mergeTwoList(Node *&head1, Node *&head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    if (head1->data > head2->data)
        swap(head1, head2);
    Node *result = head1;
    while (head1 and head2)
    {
        Node *temp = NULL;
        while (head1 and head1->data <= head2->data)
        {
            temp = head1;
            head1 = head1->next;
        }
        temp->next = head2;
        swap(head1, head2);
    }
    return result;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int size1, size2;
    cout << "Enter the number of nodes to be entered in the linked list 1 :"
         << "\n";
    cin >> size1;
    input(head1, size1);
    cout << "Enter the number of nodes to be entered in the linked list 2 :"
         << "\n";
    cin >> size2;
    input(head2, size2);
    cout << "Linked list is :"
         << "\n";
    printLinkedList(head1);
    cout << "Linked List is :"
         << "\n";
    printLinkedList(head2);
    cout << "Merging two sorted list :"
         << "\n";
    Node *head = mergeTwoList(head1, head2);
    printLinkedList(head);
    return 0;
}
