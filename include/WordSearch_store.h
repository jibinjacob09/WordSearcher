#include <stdlib.h>
#include <string.h>

//#define DEBUG
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
  //free (str);




    #ifdef ShowStore
      for (i = 0; i<row; i++){
        printf("%s\n", SearchMatrix[i]);
      }
    #endif


  //nothing went wrong
  return 1;

}
int KeyWord_Store(){
  //if  good
   //return 1;
   // else
   return 0;

}
