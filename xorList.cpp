// doubly linked list with storing the XOR of the next and prev pointer
// addresses instead of two separate addresses

#include <cinttypes>
#include <iostream>

using namespace std;

class Node{
public:
    friend class List;
    Node() : val(0), combined_address(0) { }
    Node(int data) : val(data), combined_address(0) { }
private:
    int val;
    Node* combined_address;
};

class List{
public:
    List() : head(0), tail(0) { }

    void push_back(int data){
        if (!head){
            head = tail = new Node(data);
        } else {
            Node* temp = tail;
            Node* prev = tail->combined_address;            
            tail = new Node(data);
            temp->combined_address = (Node*)((uintptr_t)tail ^ (uintptr_t)prev);
            tail->combined_address = temp;
        }

    }

    void push_front(int data){
        if (!head){
            head = tail = new Node(data);
        } else {
            Node* temp = head;
            Node* next = head->combined_address;
            head = new Node(data);
            temp->combined_address = (Node*)((uintptr_t)head ^ (uintptr_t)next);
            head->combined_address = temp;
        }
    }

    void pop_back(){

    }

    void pop_front(){

    }

    void traverse_forward(){
        Node* temp = head;
        Node* prev = 0;
        while(temp){
            cout << temp->val << " ";
            Node* temp_copy = temp;
            temp = (Node*)((uintptr_t)temp->combined_address ^ (uintptr_t)prev);
            prev = temp_copy;
        }
        cout << endl;
    }

    void traverse_reverse(){

    }
private:
    Node* head;
    Node* tail;
};

int main(){
    List list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);
    list.push_back(20);
    list.push_back(25);
    
    cout << "traversing : " << endl;
    list.traverse_forward();

    return 0;
}
