#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class Node {
public:
    char data[50];
    Node* next;
};

void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void sortedInsert(Node** head_ref, Node* new_node)
{
    Node* current;
    if (*head_ref == NULL || strcmp((*head_ref)->data, new_node->data)>=0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
            strcmp(current->next->data, new_node->data) < 0)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void deleteNode(Node **head_ref, char key[])
{
   Node* temp = *head_ref, *prev;

    if (temp != NULL && strcmp(temp->data, key) == 0)
    {
        *head_ref = temp->next;
        delete(temp);
        return;
    }

    while (temp != NULL &&  strcmp(temp->data, key) != 0 )
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    delete(temp);
}

bool search(Node* head, char a[])
{
    Node* current = head;
    while (current != NULL)
    {
        if (strcmp(current->data, a) == 0)
            return true;
        current = current->next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    int choice, i = 0, size = 0;
    char a[50][50];

  do{

      cout << "Press 1 to reserve a ticket." << endl;
      cout << "Press 2 to cancel a ticket." << endl;
      cout << "Press 3 to check if a ticket is reserved." << endl;
      cout << "Press 4 to display passengers." << endl;
      cout << "Press 5 to quit." << '\n';
      cin >> choice;
      switch (choice) {
              case 1:{

                Node* n = NULL;
                n = new Node();
                cout << "For making a reservation, please write your name without space (ex: MihaiPopescu)" << endl;
                cout << "Name under the reservation:";
                cin >> n->data;
                sortedInsert(&head, n);
                cout << endl;
                break;
              }

              case 2:{
                char a[50];
                cout << "For deleting a reservation, please write your name without space(ex: MihaiPopescu)" << endl;
                cout << "Name under the reservation:";
                cin >> a;
                deleteNode(&head, a);
                cout << endl;
                break;
              }
              case 3:{
                char a[50];
                cout << "For searching a reservation, please write your name without space(ex: AndreaHegyi)" << endl;
                cout << "Name under the reservation:";
                cin >> a;
                cout << endl;
                search(head, a)? cout<<"Yes" : cout<<"No";
                cout << endl;
                break;
              }

              case 4:{
                printList(head);
                cout << endl;
                break;
              }
              case 5: return 0;
            }

    }while (choice != 5);




    return 0;
}
