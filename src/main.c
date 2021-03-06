#include <stdio.h>
#include <stdlib.h>

#include "WordSearch_searchmatrx.h"
#include "WordSearch_hashtable.h"
#include "WordSearch_find.h"

//  #define DEBUG


/*Prototypes*/
void freeVars(char ** SearchMatrix, int mat_row, HashTable * KeyWord_tbl);



int main(int argc, char *argv[]){
/*Step 1:prepare puzzletxt for parsing/storing*/
  char* puzzle = "Puzzles/Halloween.txt";
  FILE* puzzletxt;
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
  if ((mat_row = LetterMatrix_rows(puzzle, mat_col)) < 0){
    printf("ERROR while counting rows in puzzle\n");
  }
  else {
    #ifdef DEBUG
    printf("rows counted = %d\n", mat_row);
    #endif
  }
/*Step 2: extract letter col and keywords from text and store*/
  char** SearchMatrix;
  int i;
  /*creating a device to store the letter matrix*/
  if ((SearchMatrix = malloc((mat_row) *sizeof(char *))) == NULL){
    printf("ERROR while creating SearchMatrix\n");
  }
  else {
    for (i = 0; i < mat_row; i++){
      SearchMatrix[i] = malloc((mat_col+5) * sizeof (char));
    }
  }
  int store_check;
  /*Parsing the letter matrix from the txtfile and storing it into SearchMatrix*/
  if (!SearchMatrix_Store(SearchMatrix, mat_col, mat_row, puzzletxt)){
      #ifdef DEBUG
      printf("ERROR during storing letter matrix\n");
      #endif
  }
  else{
    #ifdef DEBUG
    for (i =0; i < mat_row; i++){
      printf("%s\n ", SearchMatrix[i]);
    }
    #endif
  }
  /*Creating a hashmap to store the keywords*/
  HashTable *KeyWord_tbl;
  if ((KeyWord_tbl = CreateHashTable()) == NULL){
    printf("ERROR while creating hashmap\n");
  }
  else{
    #ifdef DEBUG
    printf("Hashmap of size %d, was created\n", KeyWord_tbl->size);
    #endif
  }
  if (!createRootsNode(KeyWord_tbl)){
    printf("ERROR creating RootNodes\n");
  }
  else{
    #ifdef DEBUG
    for (i =0; i <26; i ++){
      printf("wordlist[i]->hashkey %c\n",   KeyWord_tbl->wordlist[i]->hashkey );
    }
    #endif
  }
  HashNode * tempnode;
  if (!KeyWord_Store(puzzletxt, mat_row, mat_col, KeyWord_tbl)){
    printf("ERROR while storing keywords into hashmap\n");
  }

  //Step 3 finds the keywords stored in the HashTable in the matrix
    checkForKeyWord(SearchMatrix, mat_row, mat_col, KeyWord_tbl);
    printf("night = %d\n",  nextNodeExists(KeyWord_tbl->wordlist[13]));


  //Step 4 output the resutls

    fclose(puzzletxt);
    freeVars (SearchMatrix, mat_row, KeyWord_tbl);
    return 0;
}




  /*FREEING MALLOCED VARIABLES**/
void freeVars(char ** SearchMatrix, int mat_row, HashTable * KeyWord_tbl){
  int i;
  for (i = 0; i < mat_row; i++){
    free (SearchMatrix[i]);
  }
  free (SearchMatrix);
  //clearing the list roots
 for (i =0; i < 26; i ++){
    clearHashnode(KeyWord_tbl->wordlist[i]);
 }
 clearHashTable(KeyWord_tbl);

}
