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
  int col =1;
  txtfile = fopen (puzzle, "r");
  while ((c = fgetc(txtfile)) != '\n'){
    if (c != ' '){
      //printf("%c", c);
      col++;
    }
  }
  fclose(txtfile);
  return col-1;
}


/*counts the number of rows int letter matrix*/
int LetterMatrix_rows(char* puzzle){
  FILE *txtfile;
  char str [256];
  int row=1;
  txtfile = fopen (puzzle, "r");
  while ((fgets(str, sizeof(str), txtfile) !=  NULL) && (str[0] != '\n'))
  {
    //printf("%s\n", str);
    row ++;
  }
  fclose (txtfile);

   return row-1;
}