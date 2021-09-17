#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private:
   std::list<T> l;

public:
   T remove_min() {
      // check if empty
      if (is_empty()) {
         throw std::invalid_argument("List is empty");
      }

      // assign 1st element
      T min = l.front();

      // remove 1st element
      l.pop_front();

      return min;
   }

   T min() {
      // check if empty
      if (is_empty()) {
         throw std::invalid_argument("List is empty");
      }

      // return 1st element
      return l.front();

   }

   bool is_empty() {
      if (l.empty()) {
         return true;
      }

      return false;
   }

   void insert(const T& data) {

      for (typename std::list<T>::iterator it = l.begin(); it != l.end(); ++it) {
         if (data < *it) {
            l.insert(it, data);
            return;
         }
      }

      l.push_back(data);

   }
};

#endif