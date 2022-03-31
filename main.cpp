#include <iostream>  // cout

#include "assignment/dynamic_array.hpp"  // DynamicArray
#include "assignment/linked_list.hpp"    // LinkedList
#include "assignment/array_stack.hpp"    // ArrayStack
#include "assignment/linked_queue.hpp"   // LinkedQueue

using std::cout;

int main(int argc, char **argv) {

  // Пример. Создание пустого динамического массива.
  //assignment::DynamicArray array;

  int *arr = new int[2];
  arr[0] = 1;
  arr[1] = 2;

  int *arr1 = arr;

  for (int i = 0; i < 2; ++i) {
    cout << arr1[i];
  }
  return 0;
}
