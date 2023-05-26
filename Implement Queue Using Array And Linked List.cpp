//Striver Code
#include<bits/stdc++.h>

using namespace std;
class Queue {
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

  Queue(int maxSize) {
    ( * this).maxSize = maxSize;
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }
  void push(int newElement) {
    if (currSize == maxSize) {
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }
    if (end == -1) {
      start = 0;
      end = 0;
    } else
      end = (end + 1) % maxSize;
    arr[end] = newElement;
    cout << "The element pushed is " << newElement << endl;
    currSize++;
  }
  int pop() {
    if (start == -1) {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped = arr[start];
    if (currSize == 1) {
      start = -1;
      end = -1;
    } else
      start = (start + 1) % maxSize;
    currSize--;
    return popped;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int size() {
    return currSize;
  }

};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}

//Code Studio Code
//Using Array
class Queue {
private:
    int *arr;
    int qfront;
    int rare;
    int max_size;
    int length;
public:
    Queue() {
        arr = new int[64];
        qfront = -1;
        rare = 0;
        length = 0;
        max_size = 64;
    }
    ~Queue(){
        delete []arr;
    }
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return length == 0;
    }

    void enqueue(int data) {
        // in case of overflow
        if(qfront == 0 && rare == max_size){
            int *new_arr = new int[2*max_size];
            for(int i = 0; i < max_size; i++){
                new_arr[i] = arr[i];
            }
            max_size = 2*max_size;
            delete arr;
            arr = new_arr;
        }
        // shift the values back
        if(qfront > 0 && rare == max_size){
            for(int i = qfront, j = 0; i < rare; i++, j++){
                arr[j] = arr[i];
            }
            rare = rare - qfront;
            qfront = 0;
        }
        arr[rare] = data;
        rare++;
        if(qfront == -1) qfront = 0;
        length++;
    }

    int dequeue() {
        if(qfront >= 0){
            int x = arr[qfront];
            qfront++;
            length--;
            if(qfront == rare){
                qfront = -1;
                rare = 0;
            }
            return x;
        }
        return -1;
    }

    int front() {
        if(qfront == -1){
            return -1;
        }
        return arr[qfront];
    }
};

//Using Linked List
class Node{
    public:
        int val;
        Node* next;
    public:
        Node(){
            val = 0;
            next = NULL;
        }
        Node(int x){
            val = x;
            next = NULL;
        }
        Node(int x, Node* node){
            val = x;
            next = node;
        }
        ~Node(){
            if(next != NULL) delete next;
        }
};

class LinkedList: protected Node{
    public:
        Node *root;
        Node *tail;
    public:
        LinkedList(){
            root = NULL;
            tail = NULL;
        }
        LinkedList(Node *r){
            root = r;
            tail = root;
        }
        void add(int v){
            if(root == NULL){
                root = new Node(v);
                tail = root;
                return;
            }
            Node *n = new Node(v);
            tail->next = n;
            tail = n;
            return;
        }
        void print(){
            if(root == NULL){
                cout << endl;
                return;
            }
            Node *n = root;
            while(n != NULL){
                cout << n->val << " ";
                n = n->next;
            }
            cout << endl;
        }
        void insertAt(int pos, int x){
            Node *curr = root;
            Node *prev = NULL;
            while(pos-- && curr != NULL){
                prev = curr;
                curr = curr->next;
            }
            if(pos <= 0){
                if(curr == NULL){
                    curr = new Node(x);
                    tail->next = curr;
                    tail = curr;
                }
                else{
                    Node *q = new Node(x);
                    if(prev != NULL){
                        prev->next = q;
                    }
                    else{
                        root = q;
                    }
                    q->next = curr;
                }

            }  
        }
        void deleteNodeAt(int pos){
            Node* prev = NULL;
            Node* curr = root;
            while(pos-- && curr != NULL){
                prev = curr;
                curr = curr->next;
            }
            if(curr != NULL){
                if(prev == NULL){
                    root = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                if(curr == tail){
                    tail = prev;
                }
                curr->next = NULL;
                delete curr;
            }
        }
        void removeValue(int x){
            Node* prev = NULL;
            Node* curr = root;
            while(curr != NULL && curr->val != x){
                prev = curr;
                curr = curr->next;
            }
            if(curr != NULL){
                if(prev == NULL){
                    root = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                if(curr == tail){
                    tail = prev;
                }
                delete curr;
            }
        }
};

class Queue {
private:
    LinkedList* LL; 
    Node *qfront;
    Node *rare;
    int length;
public:
    Queue() {
        LL = new LinkedList();
            qfront = NULL;
            rare = NULL;
            length = 0;
    }
    ~Queue(){
            delete LL;
    }
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return length == 0;
    }

    void enqueue(int data) {
        LL->add(data);
        qfront = LL->root;
        rare = LL->tail;
        length++;
    }

    int dequeue() {
        if(qfront != NULL){
            int data = qfront->val;
            LL->deleteNodeAt(0);
            qfront = LL->root;
            length--;
            return data;
        }
        return -1;
    }

    int front() {
        if(qfront == NULL){
                return -1;
            }
            return qfront->val;
    }
};
