//Used cplusplus forums linked list insert and display functions, as well as its Node struct
//Everything else was written by me
//This essentially just gathers user input and enters it into a linked list.
//It then sorts this input using bubble sort, arguably one of the slowest sorting algorithms (with the exceptions of some particularly exceptional algorithms like bogosort)


#include <iostream>
using namespace std;
 class LLNode
{
private:
    struct Node {
        int data;
        struct Node* prev;
        struct Node* next;
    };
    struct Node* head = NULL;
public:
    void insert(int newdata) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = newdata;
        newnode->prev = NULL;
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
    }
    void display() {
        struct Node* ptr;
        ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    void bubblesort()
    {
        //Start at head
        //while list is not sorted
        //If element is greater than next element
        //swap them

        bool sorted = false;
        bool exit = false;
        struct Node* ptr = head;
        while (!exit)
        {    
            if (ptr->next != NULL && ptr->data > ptr->next->data)
            {
                int temp1 = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp1;  
                sorted = false;
            }

            if (ptr->next != NULL) ptr = ptr->next;
            else
            {
                if (sorted) exit = true;
                ptr = head;
                sorted = true;
            }
        }
    }
};
int main() {
    LLNode nd;
    int input;
    cout << "Input data: ";
    cin >> input;
    while (input != -999)
    {
        nd.insert(input);
        cin >> input;
    }
    nd.bubblesort();
    cout << "Sorted LLNode = ";
    nd.display();
    return 0;
}
