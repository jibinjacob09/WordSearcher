#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#define DEBUG
//#define ShowStore


/*This function stores the SearchMatrix in a 2D char array.  This allows the program to
find the keywords by going to through all the characters*/
int SearchMatrix_Store(char **SearchMatrix, int mat_col, int mat_row, FILE* puzzletxt){
  char c;
  char * str;
  int col =0, row = 0, i;
  /*Storing the SearchMatrix chars which occurs before the "***"*/
  str = malloc((mat_col +5) * sizeof(char));
  while (((fgets(str,mat_col+3,puzzletxt)) != NULL) && (str[0] != '*')){
    if (row < mat_row){
    //  SearchMatrix[row] = malloc(strlen(str) * sizeof(char));
      strcpy(SearchMatrix[row], str);
      #ifdef DEBUG
      printf("%s\n ", SearchMatrix[row]);
      #endif
      row++;
    }
  }
  free (str);
  for (i =0; i < mat_row; i++){
    if (SearchMatrix[i] == NULL){
        printf("i = %d\n", i);
        return 0;
    }
  }
  return 1;
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
