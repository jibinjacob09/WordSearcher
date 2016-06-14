#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "WordSearch_hashtable.h"

#define DEBUG
//#define ShowStore


/*This function stores the SearchMatrix in a 2D char array.  This allows the program to
find the keywords by going to through all the characters*/
int SearchMatrix_Store(char **SearchMatrix, int mat_col, int mat_row, FILE* puzzletxt){
  char c;
  char * str;
  int col =0, row = 0, i;
  /*Storing the SearchMatrix chars which occurs before the "***"*/
  str = malloc((mat_col +2) * sizeof(char));
  while (((fgets(str,mat_col+2,puzzletxt)) != NULL) && (str[0] != '*')){
    if (row < mat_row){
    //  SearchMatrix[row] = malloc(strlen(str) * sizeof(char));
      strcpy(SearchMatrix[row], str);
      #ifdef DEBUG
     printf("%s\n ", SearchMatrix[row]);
      #endif
      row++;
    }
  }
    /*if ((c != '\n') && (c != ' ')){
      str[col] = c;
      col++;
    }*/
    /*else if ((row < mat_row) && (c == '\n')){
      strcpy(SearchMatrix[row], str);
      #ifdef DEBUG
      printf("copied %s, result %s\n", str, SearchMatrix[row]);
      #endif
      col = 0;
      row = row+1;
    }
    #ifdef DEBUG
    printf("col = %d, row = %d \n", col, row);
    #endif
  }
  fclose(puzzletxt);
  #ifdef ShowStore
  for (i = 0; i<row; i++){
    printf("%s\n", SearchMatrix[i]);
  }
  #endif*/
  free (str);
  return 1;
}

/*This function reads the keywords from the puzzle.txt and stores it into a
inputed hash map. The string *** indicates the start fo the keywords, and
**** indicates the end.   Currently this format is necessary for the identification
*/
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




/*a function that verifies if the puzzle file exists*/
int VerifyPuzzle(char * location){
  int filefound = access(location, R_OK); /*checks if access to file exists, return 0 if yes, -1 if not*/
  #ifdef DEBUG
  printf ("filefound = %d\n", filefound);
  #endif
  if (filefound == 0){
    return 1;
  }
  else{
    return 0;
  }
}



/*count the number of letter columns in matrix*/
int LetterMatrix_col(char* puzzle){
  FILE *txtfile;
  char c;
  int mat_col = 0;
  txtfile = fopen (puzzle, "r");
  while ((c = fgetc(txtfile)) != '\n'){
    mat_col++;
  }
  fclose(txtfile);
  return mat_col;
}


/*counts the number of rows int letter matrix*/
int LetterMatrix_rows(char* puzzle, int col){
  FILE *txtfile;
  txtfile = fopen (puzzle, "r");
  char str[col+2];  //array is bigger than size of counted col *2
  int row = 0;
  while ((fgets(str, col +2 , txtfile) !=  NULL) && (str[0] != '\n') && (str[0] != '*'))
  {
    row ++;
  }
  fclose (txtfile);
   return row;
}
