/*This library is used to check wordsearch txtfile
and to store the matrix and the keywords*/

#include <unistd.h>
#include <stdlib.h>

int FindTxtFile(char* location){
  //checks if access to file exists, return 0 if yes, -1 if not
  int result = access(location, F_OK);
  if (result == 0){ //file found and accessible
    return 1;
  }
  else {  //file not accessible
    return 0;
  }
}


/*count the number of columns in matrix*/
int LetterMatrix_col(char* puzzle){
  FILE *txtfile;
  char c;
  int col =0;
  txtfile = fopen (puzzle, "r");
  while ((c = fgetc(txtfile)) != '\n'){
    if (c != ' '){
      col++;
      printf("c = %c,  col = %d\n", c, col);
    }
  }
  fclose(txtfile);
  return col-1;
}


/*counts the number of rows int letter matrix*/
int LetterMatrix_rows(char* puzzle){
  FILE *txtfile;
  char *str;
  int row=0;
  txtfile = fopen (puzzle, "r");
  while (fgets(str, 250, txtfile)!=NULL)
  {
    row ++;
  }
  fclose (txtfile);
   return row-1;
}


int LetterMatrix_Store(){
  //if  good
   //return 1;
   // else
   return 0;

}
int KeyWord_Store(){
  //if  good
   //return 1;
   // else
   return 0;

}
