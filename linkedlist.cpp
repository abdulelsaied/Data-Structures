
#include <iostream>
#include <string>

using namespace std;


struct node{
    string data;
    node *next;
};

node *addNode(node *head, string data);

node *removeNode(node *head, string data);

void printList(node *head);

// note: these don't _really_ need to return a node*, because if
// written correctly they'll always return nullptr.
node *deleteList(node *head);
node *recursiveDeleteList(node *head);

void recursivePrintBackwards(node *head);
node *recursiveDeleteList(node *head);
void printForward(node *head);

int main(){

    node *theList = nullptr;
    theList = addNode(theList, "hello");
    theList = addNode(theList, "aloha");
    theList = addNode(theList, "bonjour");
    theList = addNode(theList, "ohayou gozaimasu");


    cout << "printList: " << endl;
    cout << "--------------------" << endl;
    printList(theList);
    cout << endl;
    
    // added test for EC
    cout << "recursive printForwards: " << endl;
    cout << "--------------------" << endl;
    printList(theList);
    cout << endl;

    cout << "recursivePrintBackwards: " << endl;
    cout << "--------------------" << endl;
    recursivePrintBackwards(theList);

    cout << endl;
    cout << "recursiveDeleteList: " << endl;
    cout << "--------------------" << endl;
    recursiveDeleteList(theList);

    return 0;
}

// adds a node to the start of the list
node *addNode(node *head, string data){
    node *newNode = new node;
    newNode->data = data;

    if (head == nullptr){
        head = newNode;
        newNode->next = nullptr;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

// prints list in order
void printList(node *head){
    node *currentNode = head;
    while (currentNode != nullptr){
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}

// prints list backwards
void recursivePrintBackwards(node *head){
    if(head == nullptr){
        return;
    }
    recursivePrintBackwards(head->next);
    cout << head->data << endl;
}

// deletes list iteratively
node *deleteList(node *head){
    if (head == nullptr){
        return head;
    }
    node *currentNode = head;
    while (currentNode != nullptr){
        cout << "deleting " << currentNode->data << endl;
        node *tmp = currentNode->next;
        delete currentNode;
        currentNode = tmp;
    }
    return head;
}

// deletes list recursively
node *recursiveDeleteList(node *head){
    if(head == nullptr){
        return head;
    }
    cout << "deleting " << head->data << endl;
    delete head;
    return recursiveDeleteList(head->next);
}


// EXTRA CREDIT FUNCTION
void printForward(node *head){
    if(head == nullptr){
        return;
    }
    cout << head->data << endl;
    return printForward(head->next);
}
