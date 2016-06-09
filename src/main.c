#include <stdio.h>
#include <stdlib.h>


#include "WordSearch_read.h"
#include "WordSearch_store.h"
#include "WordSearch_hashtable.h"

#define DEBUG

void VerifyPuzzle(char * puzzle){

  /*verify if the file exists and is not empty*/
  int filefound = FindTxtFile(puzzle);
  #ifdef DEBUG
  printf ("filefound = %d\n", filefound);
  #endif

  /*Unable to continue if file is not found*/
  if (filefound == 0){
    printf("Cannot Access %s\n   Exiting Now \n\n\n", puzzle);
    exit(0);
  }

}


int main(int argc, char *argv[]){

  //1.read and store from txtfile
  char* puzzle = "Puzzles/Halloween.txt";;
  VerifyPuzzle(puzzle);

  int mat_col = LetterMatrix_col(puzzle);
  #ifdef DEBUG
  printf("mat_col = %d\n", mat_col);
  #endif


  int mat_row = LetterMatrix_rows(puzzle);
  #ifdef DEBUG
  printf("mat_row = %d\n", mat_row);
  #endif

  char** SearchMatrix;
  int i;

/* MASSIVE ERROR IN STORING THE SearchMatrix, FIX BEFORE JNI*/
  SearchMatrix = malloc((mat_row) *sizeof(char *));
  for (i = 0; i < mat_row; i++){
    SearchMatrix[i] = malloc((mat_col+1) * sizeof (char));
  }
  int store_check = SearchMatrix_Store(SearchMatrix, mat_col+1, mat_row, puzzle);
  printf ("store_check= %d\n", store_check);

  HashTable *KeyWord_tbl = CreateHashTable(1);
  printf("HashTable size = %d\n", KeyWord_tbl->size);
  int rootadd = createRootsNode(KeyWord_tbl);

    setHashNode(KeyWord_tbl,"foods", 'f');
      setHashNode(KeyWord_tbl,"fire", 'f');

    traverseList(KeyWord_tbl->wordlist[5]);



  /*FREEING MALLOCED VARIABLES**/
  for (i = 0; i < mat_row; i++){
    free (SearchMatrix[i]);
  }
  free (SearchMatrix);

  //clearing the list roots
  //clearHashnode(KeyWord_tbl->wordlist[5]->next);
 for (i =0; i < 26; i ++){
    clearHashnode(KeyWord_tbl->wordlist[i]);
 }
 clearHashTable(KeyWord_tbl);


  //2.find the keywords

  //3.Output the result


  return 0;
}
