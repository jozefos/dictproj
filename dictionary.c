#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include "clist.h"
#include "ht.h"

struct dictionary
{
  ht_implementation   dict;
};

struct entry
{
  char[MAX_WORD_SIZE]   word;
  char[MAX_DESC_SIZE]   desc;
};

int hashfun(struct entry e) {
  int     hash;
  char *  ptr;
  char *  word = getkeyfun(e);
  //run getkeyfun, execute hash algorithm on it, return hash value
  hash = strtoul(word, &ptr, 10) % 4093;
  return hash;
}

char * getkeyfun(struct entry e) {
  return e->word;
}

void d_initialise() {
  struct dictionary d = malloc(//look up malloc function
  d->dict   = new_ht(4093, hashfun, getkeyfun); //compare how this is done in david's examples
}
  
int d_read_from_file(const char * filename) {
  
  FILE *open;
  char line[MAX_WORD_SIZE + MAX_DESC_SIZE];
  char word[MAX_WORD_SIZE];
  char desc[MAX_DESC_SIZE];
  
  open = fopen(filename, "r");
  
  fgets(open,MAX_WORD_SIZE + MAX_DESC_SIZE,filename);
  while ( fgets(line,MAX_WORD_SIZE + MAX_DESC_SIZE,filename) != "." ) {
    fscanf(line,"%s %[^\n]",
  }
  
}

int d_lookup(const char * word, char * meaning) {
  //meaning = meaning associated with a successful lookup (look at ht_lookup)
}
