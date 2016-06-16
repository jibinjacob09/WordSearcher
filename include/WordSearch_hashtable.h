#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "WordSearch_struct.h"

//#define DEBUG




/*Creates the Hashtable without any lists*/
HashTable * CreateHashTable (){
  HashTable * KeyWord_tbl;
  if ( (KeyWord_tbl = malloc (sizeof (HashTable) )) == NULL){
    #ifdef DEBUG
    printf("Trouble creating HashTable\n");
    #endif
    return NULL;
  }
  KeyWord_tbl->size = 26;
  return KeyWord_tbl;
}



//Creates the linkedlist nodes of all 26 letters. These roots can be linked to the keywords
int createRootsNode (HashTable * KeyWord_tbl){
  int i;
  for (i =0; i < 26; i++){
    if((KeyWord_tbl->wordlist[i]= malloc(sizeof (HashNode))) == NULL){
      #ifdef DEBUG
      printf("Trouble creating hasnode roots\n");
      #endif
      return 0;
    }
    else{
      KeyWord_tbl->wordlist[i]->hashkey = 97 + i;
      KeyWord_tbl->wordlist[i]->next = NULL;
    }
  }
  return 1;
}



/*creates Hashnodes for the HashTable*/
int  setHashNode(HashTable * KeyWord_tbl, char* word, char startlett){
  HashNode *hashnode;
  int charkey = startlett - 97;
  #ifdef DEBUG
  printf("charkey = %d\n", charkey);
  #endif
  if((hashnode = malloc(sizeof (HashNode))) == NULL){
    #ifdef DEBUG
    printf("Trouble creating HashNodes");
    #endif
    return 0;
  }
  hashnode->keyword = malloc((strlen(word)+1) * sizeof(char));
    strcpy(hashnode->keyword, word);
  hashnode->hashkey = startlett;
  #ifdef DEBUG
  printf("hashnode->keyword = %s,  hashkey=%c\n", hashnode->keyword, hashnode->hashkey);
  #endif
  hashnode->found = false;
  hashnode->next = KeyWord_tbl->wordlist[charkey]->next;
  KeyWord_tbl->wordlist[charkey]->next = hashnode;
  #ifdef DEBUG
  printf("done the swap\n");
  #endif
}




void traverseList(HashNode * rootnode){
  HashNode * node;
  node = rootnode->next;
  while(node){
    printf("traversedlist: %s\n", node->keyword);
    node = node->next;
  }
}



/*Frees allocated memory of a HashNodes by traversing through the linkedlist*/
void clearHashnode(HashNode *rootnode){
  HashNode *node, *delnode;

  node = rootnode->next;
  while(node){
    if (node->keyword != NULL){
        free(node->keyword);
    }
    delnode = node;
    node = node->next;
    free(delnode);
  }
  free(rootnode);
}




/*frees the allocated memoory of the HashTable*/
void clearHashTable(HashTable *KeyWord_tbl){
  free(KeyWord_tbl);
}

/*function to determine which is larger, the matrix row or column.
the idea is that the largest keyword will only be as large as the matrix's biggest
dimension*/
int Maxof(int row, int col){
  if (row >= col){
    return row;
  }
  else if (col > row){
    return col;
  }
}



/*This function reads the keywords from the puzzle.txt and stores it into a
inputed hash map. The string *** indicates the start fo the keywords, and
**** indicates the end.   Currently this format is necessary for the identification
*/
int KeyWord_Store(FILE * puzzletxt, int mat_row, int mat_col, HashTable * KeyWord_tbl){
  char str[Maxof(mat_row,mat_col) +1];
  /*reading the storing the keywords*/
  do{
    fgets(str, Maxof(mat_row, mat_col)+1,puzzletxt);
    int l = strlen(str);
    /*removing the extra \n at the end of str*/
    if (str[l-1] == '\n'){
      str[l-1] = '\0';
      #ifdef DEBUG
      printf("str = %s\n", str);
      #endif
    }
    if(str[0] != '*'){/* keywords cannot start with '*' */
      if (!setHashNode(KeyWord_tbl, str, str[0])){
        return 0;
      }
    }
  }
  while (str [0] != '*');/* '*' indicates the end of keywords*/
  return 1;
}
