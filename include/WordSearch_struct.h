#include  <stdlib.h>

enum bool{
  true,
  false
};

typedef struct list {
  char *keyword;
  char hashkey;
  struct list *next;
  int found;
}HashNode;

typedef struct _hashtable{
  int size;
  HashNode *wordlist;
}HashTable;
