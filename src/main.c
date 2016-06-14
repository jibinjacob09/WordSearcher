#include <stdio.h>
#include <stdlib.h>

#include "WordSearch_store.h"
//#include "WordSearch_hashtable.h"

#define DEBUG

int main(int argc, char *argv[]){
/*Step 1:prepare puzzletxt for parsing/storing*/
  char* puzzle = "Puzzles/Halloween.txt";
  FILE * puzzletxt;
  /*check if puzzle path is valid, and opening it*/
  if (!VerifyPuzzle(puzzle)) {
    printf("Cannot Access %s\n   Exiting Now \n\n\n", puzzle);
    exit(0);
  }
  else{
    puzzletxt = fopen (puzzle, "r");
    #ifdef DEBUG
    printf("%s is valid, and opened file for reading\n", puzzle);
    #endif
  }
  /*getting total number of columns in the letter matrix*/
  int mat_col;
  if ((mat_col = LetterMatrix_col(puzzle)) < 1){
    printf("ERROR while counting coloumns in puzzle\n");
  }
  else{
    #ifdef DEBUG
    printf("columns counted =%d\n", mat_col);
    #endif
  }
  /*gettomg the total number of rows in the letter matrix*/
  int mat_row;
  if ((mat_row = LetterMatrix_rows(puzzle)) < 0){
      printf("ERROR while counting rows in puzzle\n");
  }
  else {
    #ifdef DEBUG
    printf("rows counted = %d\n", mat_row);
    #endif
  }
/*Step 2: extract letter col and keywords from text and store
  char** SearchMatrix;
  int i;

/* MASSIVE ERROR IN STORING THE SearchMatrix, FIX BEFORE JNI*/
/*  SearchMatrix = malloc((mat_row) *sizeof(char *));
  for (i = 0; i < mat_row; i++){
    SearchMatrix[i] = malloc((mat_col+1) * sizeof (char));
  }
  int store_check = SearchMatrix_Store(SearchMatrix, mat_col+1, mat_row, puzzle);
  printf ("store_check= %d\n", store_check);

  HashTable *KeyWord_tbl = CreateHashTable(1);
  printf("HashTable size = %d\n", KeyWord_tbl->size);
  int rootadd = createRootsNode(KeyWord_tbl);

    int num = KeyWord_Store(puzzle, mat_col, KeyWord_tbl);

    traverseList(KeyWord_tbl->wordlist[2]);



  /*FREEING MALLOCED VARIABLES**/
/*  for (i = 0; i < mat_row; i++){
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

*/
  return 0;
}
