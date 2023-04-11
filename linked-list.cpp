#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
}; 

struct LinkedList
{
    void InsertAtBeginning(Node** head, int x) 
    {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if (*head != NULL) temp->next = *head;
        *head = temp;
    }

    void InsertAtPosition(Node** head, int data, int n)
    {
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (n == 1)
        {
            temp->next = *head;
            *head = temp;
            return;
        }
        Node* temp2 = *head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }

    void DeleteAtPosition(Node ** head, int n) // code by myself :>
    {
        Node* temp = *head;
        if (n == 1)
        {
            *head = temp->next;
            free(temp);
            return;
        }
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }

    void Reverse(Node** head)
    {
        Node* current = *head;
        Node *next = NULL, *prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }

    void Print(Node* head)
    {
        Node* temp = head;
        cout << "List is: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Node* head = NULL;
    LinkedList list;
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int x = n;

    for (int i = 0; i < n; i++)
    {
        list.InsertAtBeginning(&head, x--);
    }
    list.Print(head);

    list.InsertAtPosition(&head, 99, 4);
    list.Print(head);

    list.DeleteAtPosition(&head, 4);
    list.Print(head);

    list.Reverse(&head);
    list.Print(head);

    free(head);
    return 0;
}