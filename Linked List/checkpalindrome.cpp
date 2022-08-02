#include <bits/stdc++.h>
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
        cout << "Deleted node value is :" << value << "\n";
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
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
}
void input(Node *&head)
{
    cout << "Enter the number of nodes :"
         << "\n";
    int size;
    cin >> size;
    int data;
    while (size--)
    {
        cin >> data;
        insertAtTail(head, data);
    }
}
void printLinkedList(Node *head)
{
    cout << "Linked List is :"
         << "\n";
    Node *current = head;
    while (current)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
Node *middleOfList(Node *&head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverseList(Node *&node)
{
    Node *current = node;
    Node *prev = NULL;
    Node *next = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
bool palindromeList(Node *&head)
{
    Node *middle = middleOfList(head);
    middle->next = reverseList(middle->next);
    middle = middle->next;
    Node *temp = head;
    while (middle)
    {
        if (temp->data != middle->data)
            return false;
        temp = temp->next;
        middle = middle->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    input(head);
    printLinkedList(head);
    if (palindromeList(head))
        cout << "List is palindrome"
             << "\n";
    else
        cout << "List is not palindrome"
             << "\n";
    return 0;
}