#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        //Implement the below 4 methods. Please note these methods are not from MPQ.h
        //BinaryHeap class does not inherit MPQ class 
        //Implement BinaryHeap insert operation
        //Also implement upheap and downheap operations (functions provided below) and call them from wherever necessary
        void insert(const T& data) {
            elements.push_back(data);
            size++;

            int index = size - 1;

            up_heap(index);

        }
        
        bool is_empty() {
            // Return true if BinaryHeap is empty otherwise false
            if (elements.size() == 0) {
                return true;
            }

            return false;
        }
        
        T min() {
            // Return minimum element in the BinaryHeap
            if (is_empty()) {
                throw std::invalid_argument("Heap is empty");
            }

            return elements.at(0);
        }
        
        T remove_min() {
            // Remove minimum element in the BinaryHeap and return it
            if (is_empty()) {
                throw std::invalid_argument("Heap is empty");
            }

            // store the value of min
            T min = elements.at(0);
            elements[0] = elements[size-1];
            elements.pop_back();
            size --;
            down_heap(0);

            // return min
            return min;

        }
    private:
        //
        std::vector<T> elements;
        int size = 0;

        //Implement down heap operation
        void down_heap(int i);

        //Implement up heap operation
        void up_heap(int i);

        //Pre-implemented helper functions
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        //Binary tree (Complete Binary tree) can be represented in vector form and hence, stored in a vector. 
        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}
        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}
        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}
        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){

    // only operate when i > 0
    if (i > 0) {
        int parentIndex = parent(i);
        T parentValue = elements.at(parentIndex);

        int childIndex = i;
        T childValue = elements.at(i);

        while (childValue < parentValue) {
            swap(parentIndex, childIndex);

            if (parentIndex == 0) {
                break;
            } else {
                childIndex = parentIndex;
                parentIndex = parent(parentIndex);

                childValue = elements.at(childIndex);
                parentValue = elements.at(parentIndex);
            }

        }
    }
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){

    int leftIndex = left_child(i);
    int rightIndex = right_child(i);
    int rootIndex = i;

    if (leftIndex >= 0 && rightIndex >= 0) {

        if ((leftIndex < size) && (elements.at(leftIndex)) < (elements.at(i))) {
            rootIndex = leftIndex;
        }

        if ((rightIndex < size) && (elements.at(rightIndex)) < (elements.at(rootIndex))) {
            rootIndex = rightIndex;
        }

        if (rootIndex != i) {
            swap(i, rootIndex);
            down_heap(rootIndex);
        }

    }

    // ** ignore *** 
    // // define root variables
    // int rootIndex = i;
    // T rootValue = elements.at(i);

    // // define child variables
    // int leftChildIndex = left_child(rootIndex);
    // int rightChildIndex = right_child(rootIndex);
    // T leftChildValue = elements.at(leftChildIndex);
    // T rightChildValue = elements.at(rightChildIndex);

    // while ((is_internal(rootIndex)) && ((rightChildValue <= rootValue) || (leftChildValue <= rootValue))) {

    //     // determin which is lesser, left or right
    //     if ((rightChildValue <= leftChildValue) && (rightChildIndex <= rootValue)) {
    //         swap(rightChildIndex, rootIndex);
    //         rootIndex = rightChildIndex;
    //         rootValue = rightChildValue;
    //     } else {
    //         swap(leftChildIndex, rootIndex);
    //         rootIndex = leftChildIndex;
    //         rootValue = leftChildValue;
    //     }

    //     if (is_leaf(rootIndex)) {
    //         break;
    //     }

    //     rightChildIndex = right_child(rootIndex);
    //     leftChildIndex = left_child(rootIndex);

    //     rightChildValue = elements.at(rightChildIndex);
    //     leftChildValue = elements.at(leftChildIndex);
    // }

}
#endif