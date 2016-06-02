#include "WordSearch_struct.h"

#define DEBUG


/*Creates the Hashtable without any lists*/
HashTable * CreateHashTable (int size){
  int i;
  HashTable * KeyWord_tbl;
  if ( (KeyWord_tbl = malloc (sizeof (HashTable) )) == NULL){
    #ifdef DEBUG
    printf("Trouble creating HashTable\n");
    #endif
    return NULL;
  }
  KeyWord_tbl->size = size;
  return KeyWord_tbl;
}

/*creates Hashnodes for the HashTable*/
HashNode * setHashNode(char* word, char startlett){
  HashNode *hashnode;
  if((hashnode = malloc(sizeof (HashNode))) == NULL){
    #ifdef DEBUG
    printf("Trouble creating HashNodes");
    #endif
    return NULL;
  }
  hashnode->keyword = malloc((strlen(word)+1) * sizeof(char));
  strcpy(hashnode->keyword, word);
  hashnode->hashkey = startlett;
  #ifdef DEBUG
  printf("hashnode->keyword = %s,  hashkey=%c\n", hashnode->keyword, hashnode->hashkey);
  #endif
  hashnode->found = false;
  return hashnode;
}


/*Frees allocated memory of a HashNode*/
void clearHashnode(HashNode *hashnode){
  free(hashnode->keyword);
  free(hashnode);
}


/*frees the allocated memoory of the HashTable*/
void clearHashTable(HashTable *KeyWord_tbl){
  free(KeyWord_tbl);
}
