#include "WordSearch_struct.h"

//#define DEBUG


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
    }
    #ifdef DEBUG2
    printf("KeyWord_tbl->wordlist[i]->hashkey %c\n",   KeyWord_tbl->wordlist[i]->hashkey );
    #endif
  }
  return 1;
}


/*creates Hashnodes for the HashTable*/
void  setHashNode(HashTable * KeyWord_tbl, char* word, char startlett){
  HashNode *hashnode;
  int charkey = startlett - 97;
  #ifdef DEBUG
  printf("charkey = %d\n", charkey);
  #endif

  if((hashnode = malloc(sizeof (HashNode))) == NULL){
    #ifdef DEBUG
    printf("Trouble creating HashNodes");
    #endif
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
