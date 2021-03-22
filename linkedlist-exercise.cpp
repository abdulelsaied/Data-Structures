// Name: Abdul-Rahman El-Saied
// CIS 25, Benjamin Allen
// 11/17/2019
// IN-CLASS ASSIGNMENT DAY 24
// This program implemeents the required exercises + EC



/* file: linkedlist-exercise.cpp
 * -----
 *  A partial implementation of a linked list. Note: this is not to
 *  be taken as an example of a particularly efficient or clean
 *  implementation of a linked list. It mainly exists for the
 *  purpose of the exercise below.
 *
 *  Exercise: implement two recursive functions:
 *
 *  void recursivePrintBackwards(node *head)
 *    void recursiveDeleteList(node *head)
 *  */


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
    // REPLACE THIS COMMENT WITH YOUR CODE. note: YOU MUST USE RECURSION.
    // tip 1: make sure your function works correctly when
    // provided with an empty list
    //
    // tip 2: what are your base cases? what's your recursive case?
    // write 'em down in pseudocode before you write your function.
    //
    // note: your full implementation could very well be shorter
    // than this comment. If you're using any type of loop,
    // you're doing it wrong. If you're writing a very long function,
    // you're probably doing it wrong.
    //
    // For a small amount of extra credit, also implement a recursive printForwards()
    // function.
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
