#include <iostream>


using namespace std;

class Node {
    public:
        int data;
        Node* next;  
};

class Linkedlist {
    private:
        Node *head, *tail;

    public:
        Linkedlist() {
            head = NULL;
            tail = NULL;
        }        

    void add_node(int n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL; 

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void print() {
        cout << "Linked List: "<< endl;
        Node *current = head;
        if(current==NULL) {
            cout << "Linked list is empty" << "\n";
        }
        else {
            while (current != NULL) {
                cout << current->data << "\n";
                current = current->next;
                }
        }

    }     

    void add_at_first(int n) {
        Node *x = head;
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = x; 
        head = tmp;
    }     

    void add_at_end(int n) {
        Node *current = head;
        if(current==NULL) {
            add_at_first(n);
        }
        else {
            while (current!= NULL) {
                if(current->next==NULL) {
                    Node *tmp = new Node;
                    current->next = tmp;
                    tmp->data = n;
                    tmp->next = NULL;
                    tail = tmp;
                    break;
                }
                else {
                    current = current->next;
                }
            }
        }
        
    }

    void add_at_position(int n, int position) {
        //assuming position starts at 1
        int pos = 1;
        Node* current = head;
        if(current==NULL) {
            add_node(n);
        }
        else if(position==1)
        {
            add_at_first(n);
        }
        else {

        }
        while(current!=NULL)
        {
            if(pos==position-1){
                Node* x = current->next;
                Node *tmp = new Node;
                current->next = tmp;
                tmp->data = n;
                tmp->next = x;
                break;
            }
            else{
                pos++;
                current = current->next;
            }
        }
        
    }

    void delete_at_position(int position) {
        int p = 1;
        Node* t = head;
        while(t!=NULL) {
            Node* prev;
            if(position==1) {
                 head = t->next;
                 delete t;
                 break;
            }
            else if(p==(position)) {
                prev->next = t->next;
                delete t;
                break;

            }
            else {
                prev = t;
                p = p+1;
            }
            t = t->next;
        }
        if(position>p) {
            cout << "Not enough elements in Linked list" << endl;
        }
    }

};

int input_extract() {
    int inp;
    cout << "enter " << " - ";
    cin >> inp;
    return inp;

}

int main()
{
    Linkedlist linked_list;
    int continue_executing {1};

    while (continue_executing) {

        int choice;
        cout << "1)Add a new node\n2)Print the linked list\n3)Add at front\n4)Add at end\n5)Add at a specific position\n6)Delete at position\n7)Exit the program\n\n";
        cout << "Enter your choice - ";
        cin >> choice;

        if(choice==1) {
            int x = input_extract();
            linked_list.add_node(x);
            cout << "--------------------------------------\n";
        }
        else if (choice==2) {
            linked_list.print();
            cout << "--------------------------------------\n";
        }
        else if(choice==3) {
            int b = input_extract();
            linked_list.add_at_first(b);
            cout << "--------------------------------------\n";
        }
        else if(choice==4) {
            int c = input_extract();
            linked_list.add_at_end(c);
            cout << "--------------------------------------\n";
        }
        else if(choice==5) {
            int d = input_extract();
            int e = input_extract();
            linked_list.add_at_position(d, e);
            cout << "--------------------------------------\n";
        }
        else if(choice==6) {
            int f = input_extract();
            linked_list.delete_at_position(f);
            cout << "--------------------------------------\n";
        }
        else if(choice==7) {
            continue_executing = 0;
        }
        else {
            cout << "invalid input\n";
            cout << "--------------------------------------\n";
        }
    }
    return 0;
}



