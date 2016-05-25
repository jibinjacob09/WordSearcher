#include <stdio.h>
#include "WordSearch_read.h"

void AccquireWordSearch(){

/*verify if the file exists and is not empty*/
  char* location = "location/of/WordSearch.txt";
  int filefound = FindTxtFile(location);

/*Check if the letterMatrix is NxM
  and if the Keyword is correctly seperated*/
int format_matrix = inputFormatMatrix_Check();
int format_keyword = inputFormatKeyWord_Check();

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
