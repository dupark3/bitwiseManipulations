// doubly linked list with storing the XOR of the next and prev pointer
// addresses instead of two separate addresses

#include <cinttypes>
#include <iostream>
#include <stdexcept>

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
    ~List() {
        while(head){
            Node* prev = head;
            head = head->combined_address;
            if (head){
                head->combined_address = (Node*)((uintptr_t)head->combined_address ^ (uintptr_t)prev);
            }
            delete prev;
        }
    }

    bool is_empty(){
        return head;
    }

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

    int pop_back(){
        if (!tail){
            throw logic_error("empty list");
        } else {
            int val = tail->val;

            Node* temp = tail;
            tail = tail->combined_address;
            if (tail){
                tail->combined_address = (Node*)((uintptr_t)tail->combined_address ^ (uintptr_t)temp);
            }            
            delete temp;

            return val;
        }
    }

    int pop_front(){
        if (!head){
            throw logic_error("empty list");
        } else {
            int val = head->val;

            Node* temp = head;
            head = head->combined_address;
            if (head){                
                head->combined_address = (Node*)((uintptr_t)head->combined_address ^ (uintptr_t)temp);
            }
            delete temp;

            return val;
        }
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
        Node* temp = tail;
        Node* next = 0;
        while(temp){
            cout << temp->val << " ";
            Node* temp_copy = temp;
            temp = (Node*)((uintptr_t)temp->combined_address ^ (uintptr_t)next);
            next = temp_copy;
        }
        cout << endl;
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
    list.traverse_reverse();

    cout << endl << "popping last item which was " << list.pop_back() << endl;
    cout << "traversing : " << endl;
    list.traverse_forward();
    list.traverse_reverse();

    cout << endl << "popping first item which was " << list.pop_front() << endl;
    cout << "traversing : " << endl;
    list.traverse_forward();
    list.traverse_reverse();

    List list2;
    list2.push_front(3);
    cout << list2.pop_back() << endl;
    return 0;
}
