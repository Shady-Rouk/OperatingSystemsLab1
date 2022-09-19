// Farouk Balogun

#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  // Testing list_add_to_back
  printf("\n\nTesting list_add_to_back\n");
  list_t* list1 = list_alloc();
  list_add_to_back(list1, 1);
  list_add_to_back(list1, 2);
  list_add_to_back(list1, 3);
  list_add_to_back(list1, 4);
  list_print(list1);
  printf("The length of list1 is %d\n\n", list_length(list1));


  // Testing list_add_to_front
  printf("\n\nTesting list_add_to_front\n");
  list_add_to_front(list1, 8);
  list_add_to_front(list1, 7);
  list_add_to_front(list1, 6);
  list_add_to_front(list1, 5);
  list_print(list1);
  printf("The length of list1 is %d\n\n", list_length(list1));


  // Testing list_add_at_index and list_get_elem_at
  printf("\n\nTesting list_add_at_index and list_get_elem_at\n");
  list_add_at_index(list1, 22, 1);
  list_add_at_index(list1, 23, 0);
  list_add_at_index(list1, 27, 3);
  printf("my_list at index 1: %d\n", list_get_elem_at(list1, 1));
  printf("my_list at index 0: %d\n", list_get_elem_at(list1, 0));
  printf("my_list at index 3: %d\n", list_get_elem_at(list1, 3));
  list_print(list1);
  printf("The length of list1 is %d\n\n", list_length(list1));


  // Testing list_get_index_of
  printf("\n\nTesting list_get_index_of\n");
  printf("index of 22: %d\n", list_get_index_of(list1, 22));
  printf("index of 23: %d\n", list_get_index_of(list1, 23));
  printf("index of 27: %d\n", list_get_index_of(list1, 27));
  printf("index of 44: %d\n", list_get_index_of(list1, 44));


  // Testing list_is_in
  printf("\n\nTesting list_is_in\n");
  printf("-1 is in my_list: %d\n", list_is_in(list1, -1));
  printf("20 is in my_list: %d\n", list_is_in(list1, 20));
  printf("27 is in my_list: %d\n", list_is_in(list1, 27));


  // Testing list_remove_from_back
  printf("\n\nTesting list_remove_from_back\n");
  elem end1 = list_remove_from_back(list1);
  elem end2 = list_remove_from_back(list1);
  elem end3 = list_remove_from_back(list1);
  printf("I removed %d, %d, and %d in that order from the back of list1\n", end1, end2, end3);
  list_print(list1);
  printf("The length of list1 is: %d after removing from the back\n", list_length(list1));


  // Testing list_remove_from_front
  printf("\n\nTesting list_remove_from_front\n");
  elem start1 = list_remove_from_front(list1);
  elem start2 = list_remove_from_front(list1);
  elem start3 = list_remove_from_front(list1);
  printf("I removed %d, %d, and %d in that order from the front of list1\n", start1, start2, start3);
  list_print(list1);
  printf("The length of list1 is: %d after removing from the back\n", list_length(list1));


  // Testing list_remove_at_index
  printf("\n\nTesting list_remove_at_index\n");
  elem value1 = list_remove_at_index(list1, 1);
  elem value2 = list_remove_at_index(list1, 2);
  elem value3 = list_remove_at_index(list1, 1);
  printf("I removed %d, %d, and %d in that order from list1\n", value1, value2, value3);
  list_print(list1);
  printf("The length of list1 is: %d after removing with indexes\n", list_length(list1));


  // Testing list_free
  printf("\n\nTesting list_free\n");
  list_free(list1);
  list_print(list1);
  printf("\nThe length of list1 is: %d after freeing it\n", list_length(list1));
  return 0;
}
