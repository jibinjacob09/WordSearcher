#include  <stdlib.h>

enum bool{
  true,
  false
};

enum directions {
  up =0,
  down = 1,
  right =2,
  left = 3
};

typedef struct list {
  char *keyword;
  char hashkey;
  struct list *next;
  int found;
}HashNode;

typedef struct _hashtable{
  int size;
  HashNode *wordlist[26];
}HashTable;
