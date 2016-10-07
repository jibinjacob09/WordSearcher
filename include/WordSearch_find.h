#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG_FIND


/*this function goes through each char in the matrix and gives a sequence of 2 chars to the checkSequence function
to see if there is a matching node in the HashTable
Retruns 1 if ran without error */

void checkForKeyWord(char ** SearchMatrix, int mat_row, int mat_col, HashTable* KeyWord_tbl){
  int i=0,row = 0, col =0, count = 0;

  char c[Maxof(mat_row,mat_col)+1]; /*an array to store letters from the matrix*/

  /* looping through each char in the row looking for the keywords*/
  for (col = 0; col < 5 /*mat_col-1*/; col++){
    if ((c[0] = SearchMatrix[row][col]) != ' '){
      #ifdef DEBUG_FIND
      printf("letter %c\n", c[0]);
      #endif
      /*checking if keywords exists for this letter*/
      if (nextNodeExists(KeyWord_tbl->wordlist[c[0]-97])){
        #ifdef DEBUG_FIND
        printf("node exist for this letter in the hastable\n");
        #endif
        /*checking to see if a word exists using the next letter*/
        /*checking towards right*/
        if (col < (mat_col - 1)){
          /*getting a valid  next character*/
          if (SearchMatrix[row][col+1] != ' '){
            c[1] =  SearchMatrix[row][col+1];
          }
          else{
            c[1] =  SearchMatrix[row][col+2];
          }
        }
        c[2] = '\0'; /*terminating string correctly to avoid meory issues*/
        int checkright = checkSequence(SearchMatrix,KeyWord_tbl,c,col,row,mat_col, mat_row, right);
        #ifdef DEBUG_FIND
          printf("checkright = %d\n", checkright);
        #endif

        /*check right failed, so check down*/
        if (checkright == 0) {
          #ifdef DEBUG_FIND
          printf("performing checkdown\n");
          #endif

          if (row < (mat_row - 1)){
            /*getting a valid  next character*/
            if (SearchMatrix[row+1][col] != ' '){
              c[1] =  SearchMatrix[row+1][col];
            }
            else{
              c[1] =  SearchMatrix[row+2][col];
            }
          }
          c[2] = '\0'; /*terminating string correctly to avoid meory issues*/

          int checkdown = checkSequence(SearchMatrix,KeyWord_tbl,c,col,row,mat_col, mat_row, down);
          #ifdef DEBUG_FIND
            printf("checkdown = %d\n", checkdown);
          #endif

        }


      }
    }
  }
}

/*this function checks if a given sequence of chars matches any nodes in the hashtable. If there is matche,
then it goes to the SearchMatrix and then extracts chars to see if this is the location of the keyword.
returns 1 if the keyword is found and 0 if not found */
int checkSequence(char ** SearchMatrix,HashTable* KeyWord_tbl, char c[], int col, int row, int mat_col, int mat_row, int direction){

  HashNode * tempnode;
      int i= 0, count=0, returnval = 0;
      /*getting words starting with c[0] and c[1] from HashTable*/
  tempnode = FindinList(KeyWord_tbl->wordlist[c[0]-97], c);
      do {
        if (tempnode!=NULL){
          int l = strlen(tempnode->keyword);
          printf("l = %d\n", l);

          /*getting ready to extract l number of chars from matrix for comparsion*/
          switch (direction){
            case right :
                  printf("right\n");
                  if ((mat_col - col) >= l){
                    while(count < l){
                      /*extracting only valid chars*/
                     if (SearchMatrix[row][col + i] != ' '){
                        c[count] = SearchMatrix[row][col +i];
                        count++;
                        c[count] = '\0'; /*need to terminate string to avoid memory issues*/
                      }
                      i++;
                    }
                  }
                  break;
            case down:
                  printf("down\n");
                  if ((mat_row - row) >= l){
                    while(count < l){
                      /*extracting only valid chars*/
                     if (SearchMatrix[row + i][col] != ' '){
                        c[count] = SearchMatrix[row + i][col];
                        count++;
                        c[count] = '\0'; /*need to terminate string to avoid memory issues*/
                      }
                      i++;
                    }
                  }
                  break;
            default:
              exit (0);
          }
          if (l > 0) {
            #ifdef DEBUG_FIND
             printf("full extracted c = %s\n", c);
            #endif

            l = strlen(c);
            /*comparing if the letters extracted equals the keyword*/
            if (strcmp(c,tempnode->keyword) == 0){
              /*changing the status of the keyword, to avoid finding again*/
              tempnode->found = 1;
              returnval = 1;
              break;
            }
          }
          else{
            exit(0);
          }
       }
        else { /*no nodes for this sequence found*/
          #ifdef DEBUG_FIND
          printf("no matching nodes were found\n");
          #endif

          break;
        }
      }while ((tempnode = FindinList(tempnode, c)) != NULL);/*if there are more than one matching nodes*/

      #ifdef DEBUG_FIND
      if (returnval){
        printf("sequenced matched and node found\n");
      }
      else{
        printf("sequence not matched\n");
      }
      #endif

      return returnval;

}
