#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::vector
   // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private: 
   std::vector<T> v;

public:
   T remove_min() {

      // check if empty
      if (is_empty()) {
         throw std::invalid_argument("Vector is empty");
      }

      // store 1st value
      T min = v[0];
      int index = 0;

      for (int i = 0; i < v.size(); i ++){
         if (v[i] < min) {
            min = v[i];
            index = i;
         }
      }

      // remove the min
      v.erase(v.begin()+index);

      // return the min
      return min;

   }

   T min() {

      // check if empty
      if (is_empty()) {
         throw std::invalid_argument("Vector is empty");
      }

      // store 1st value
      T min = v[0];

      for (int i = 0; i < v.size(); i ++){
         if (v[i] < min) {
            min = v[i];
         }
      }

      return min;

   }

   bool is_empty() {
      if (v.size() == 0) {
         return true;
      } else {
         return false;
      }

      return false;
   }

   void insert(const T& data) {
      v.push_back(data);
   }
};

#endif