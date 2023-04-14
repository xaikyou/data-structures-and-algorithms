#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void GenerateLL(Node** head, int max)
{
    for (int i = 0; i < max; ++i)
    {
        Node* temp = new Node();
        temp->data = i + 1;
        temp->next = *head;
        *head = temp;
    }
}

void PrintLL(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Reverse(string &str)
{
    stack<char> S;
    for (int i = 0; i < str.length(); ++i)
    {
        S.push(str[i]);
    }
    for (int i = 0; i < str.length(); ++i)
    {
        str[i] = S.top();
        S.pop();
    }
} 

void Reverse(Node** head)
{
    if (*head == NULL) return;
    stack<Node*> S;
    Node* temp = *head;
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    *head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

bool CheckBalancedParanthesis(string str) // last opened first closed
{
    stack<char> S;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
            S.push(str[i]);
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if (S.empty() || 
                (str[i] == ')' && S.top() != '(') ||
                (str[i] == ']' && S.top() != '[') ||
                (str[i] == '}' && S.top() != '{') )
                return false;
            else S.pop();
            // if not set if S.empty() and S is empty, it will pop an empty Stack, cause error 
        }
    }
    return S.empty() ? true : false;
}

int main()
{
    // string str;
    // cout << "Enter a sentence: ";
    // getline(std::cin, str);
    // Reverse(str);
    // cout << str;

    // Node* head = NULL;
    // int n = 5; // linked list length
    // GenerateLL(&head,n);
    // PrintLL(head);
    // Reverse(&head);
    // PrintLL(head);

    string str;
    cout << "Enter a sentence: ";
    getline(std::cin, str);
    cout << CheckBalancedParanthesis(str);
    cout << "Hello";
    return 0;
}