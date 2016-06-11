#include <stdlib.h>
#include <string.h>

#include "WordSearch_hashtable.h"

//#define DEBUG2
//#define ShowStore


/*This function stores the SearchMatrix in a 2D char array.  This allows the program to
find the keywords by going to through all the characters*/
int SearchMatrix_Store(char **SearchMatrix, int mat_col, int mat_row, char* puzzle){
 FILE *txtfile;
  char c, str[mat_col+1];
  int col =0, i;
  int row =0;

  txtfile = fopen (puzzle, "r");
  /*Storing the SearchMatrix chars which occurs before the "******"*/
 while ((c = fgetc(txtfile)) != '*'){
    #ifdef DEBUG
    printf("%c ", c);
    #endif

    if ((c != '\n') && (c != ' ')){
     str[col] = c;
      col++;
    }
    else if ((row < mat_row) && (c == '\n')){
      strcpy(SearchMatrix[row], str);
      #ifdef DEBUG
      //printf("copied %s, result %s\n", str, SearchMatrix[row]);
      #endif

      col = 0;
      row = row+1;
    }

    #ifdef DEBUG
    printf("col = %d, row = %d \n", col, row);
    #endif
  }
  fclose(txtfile);
      #ifdef ShowStore
      for (i = 0; i<row; i++){
        printf("%s\n", SearchMatrix[i]);
      }
    #endif
  return 1;
}


int KeyWord_Store(char * puzzle, int mat_col, HashTable * KeyWord_tbl){
  FILE *txtfile;
  txtfile = fopen (puzzle, "r");
  char s[mat_col*2+1];

  //going to the keyword section in the puzzle
  while (strcmp(s, "***\n") != 0){
    fgets(s, mat_col*2+1,txtfile);
  }
  while (strcmp(s, "****\n") != 0){
    fgets(s, mat_col*2+1,txtfile);
    char * keyword;
    int l = strlen(s);

      if  (s[0] != '*'){
      keyword = malloc((l-1)*sizeof(char));
      strncpy(keyword,s,l-1);
      #ifdef DEBUG2
      printf("attempting to store %s  key = %c\n", keyword, s[0]);
      #endif
      setHashNode(KeyWord_tbl,keyword,s[0]);
      free (keyword);
    }

  }


  fclose(txtfile);

   return 0;

}
