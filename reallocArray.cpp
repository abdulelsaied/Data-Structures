// This program defines a reallocArray function, which returns a pointer to a heap-allocated array with the same items as the original array, but with twice the capacity.

#include <iostream>

using namespace std;

int *reallocArray(int array[], int terms_used, int capacity);

int main(){
    
    int numberOfItems = 0;
    int capacity = 4; // arbitrary starting capacity.
    
    int *array = new int[capacity];
    
    for(int i = 0; i < 15; i++){
        array[i] = i;
        numberOfItems++;
        if(numberOfItems == capacity){
            array = reallocArray(array, numberOfItems, capacity);
            capacity *= 2;
        }
    }
    
    for(int i = 0; i < numberOfItems; i++){
        
        cout << array[i] << endl;
        
    }
    
    return 0;
}

// returns a pointer to a heap allocated array with twice the capacity
int *reallocArray(int array[], int items_used, int capacity){
    
    capacity *= 2;
    int *temp = new int[capacity];
    
    for(int i = 0; i < items_used; i++){ // only copying items that have been used
        
        temp[i] = array[i];
        
    }
    
    
    delete[] array;
    return temp;
    
}
