#include <stdio.h>
#include <stdlib.h>

#include "WordSearch_read.h"

#define DEBUG

void AccquireWordSearch(){

/*verify if the file exists and is not empty*/
  char* puzzle = "Puzzles/Halloween.txt";;
  int filefound = FindTxtFile(puzzle);
 #ifdef DEBUG
    printf ("filefound = %d\n", filefound);
 #endif

/*Unable to continue if file is not found*/
 if (filefound == 0){
   printf("Cannot Access %s\n   Exiting Now \n\n\n", puzzle);
   exit(0);
 }

int mat_col = LetterMatrix_col(puzzle);
#ifdef DEBUG
  printf("mat_col = %d\n", mat_col);
 #endif

int mat_row = LetterMatrix_rows(puzzle);
#ifdef DEBUG
  printf("mat_row = %d\n", mat_row);
#endif

char** lettermat[mat_row] = malloc(sizeof(char)*mat_col);

int i;
for(i = 0; i<mat_row; i++){
  free(lettermat[i]);
}

/*store lettermatrix into memory*/
int store_matrix = LetterMatrix_Store();

/*store keywords into memory*/
int store_keyword = KeyWord_Store();

}


int main(){

  //1.read from txtfile
    AccquireWordSearch();
  //2.find the keywords

  //3.Output the result


  return 0;
}
