#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include "clist.h"
#include "ht.h"

struct dictionary
{
  char[]              cword;
  ht_implementation   dict;
};

struct entry
{
  char[MAX_WORD_SIZE]   word;
  char[MAX_DESC_SIZE]   desc;
};

int hashfun(struct entry e) {
  char * word = getkeyfun(e->word);
  //run getkeyfun, execute hash algorithm on it, return hash value
}

char* getkeyfun(struct entry e) {
  //look at David's implementation of a hash table for a function to model this on
  //read up on strings and char*'s
  
  //word is key, extract from structure
  //return word string
}

void d_initialise() {
  struct dictionary d = malloc(//look up malloc function
  d->cword  = "";
  d->dict   = new_ht(26, hashfunc, getkeyfunc); //compare how this is done in david's examples
}
  
int d_read_from_file(const char * filename) {
  char line[MAX_WORD_SIZE + MAX_DESC_SIZE];
  while ( fgets(line,MAX_WORD_SIZE + MAX_DESC_SIZE,filename) != ".\0" ) {
    //hash key then place in bst along with definition;
  }
  
}

int d_lookup(const char * word, char * meaning) {
  
}
