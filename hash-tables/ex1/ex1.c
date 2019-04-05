#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  // is there enough data to work with?
  if(length < 2){
    return NULL;
  }
  // populate the hash table
  for(int i = 0; i < length; i++){
    // won't get fooled again
    // use values as keys and indexes as values
    hash_table_insert(ht, weights[i], i);
  }
  // find pairs of numbers equal to limit
  for(int j = 0; j < limit/2; j++){
//    printf("\n\nlooping through combinations\n");
    int l_key = limit - j;
    int l_index = hash_table_retrieve(ht, l_key);
    int s_index = hash_table_retrieve(ht, j);
//    printf("l_index = %d\n", l_index);
//    printf("s_index = %d\n", s_index);
    if(l_index >= 0 && s_index >= 0){
//      printf("{%d, %d}", l_index, s_index);
      Answer *answer = malloc(sizeof(Answer));
      answer->index_1 = l_index;
      answer->index_2 = s_index;
      return answer;
    }
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  printf("Test1 expecting null: ");
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  printf("Test2 expecting {1, 0}: ");
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  printf("Test3 expecting {3,1}: ");
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  printf("Test4 expecting {6, 2}: ");
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
