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
        cout << "The value which is deleted is :" << value << "\n";
    }
};
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
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
void printLinkedList(Node *head)
{
    if (!head)
        return;

    Node *current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
bool cycleDetection(Node *head)
{
    if (!head)
        return false;
    unordered_map<Node *, bool> visited;

    Node *current = head;
    while (current)
    {
        if (visited[current] == true)
        {
            cout << "Cycle is present at :" << current->data << "\n";
            return true;
        }

        visited[current] = true;
        current = current->next;
    }
    return false;
}
Node *floyedCycleDetection(Node *head)
{
    if (!head)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (slow and fast)
    {
        fast = fast->next;
        if (fast)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Cycle is present at :" << slow->data << "\n";
            return slow;
        }
    }
    return NULL;
}
Node *startingNode(Node *head)
{
    if (!head)
        return nullptr;

    Node *intersection = floyedCycleDetection(head);
    Node *slow = head;
    while (intersection != slow)
    {
        intersection = intersection->next;
        slow = slow->next;
    }
    return slow;
}
void removeCycle(Node *&head)
{
    if (!head)
        return;

    Node *startOfLoop = startingNode(head);
    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
        temp = temp->next;
    temp->next = NULL;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    printLinkedList(head);
    head->next->next->next->next = head->next;
    bool check = cycleDetection(head);
    cout << check << "\n";
    Node *loop = floyedCycleDetection(head);
    Node *startNode = startingNode(head);
    cout << startNode->data << "\n";
    removeCycle(head);
    bool ocheck = cycleDetection(head);
    cout << ocheck << "\n";
    return 0;
}