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
}

struct entry
{
  char[MAX_WORD_SIZE]   word;
  char[MAX_DESC_SIZE]   desc;
}

void d_initialise() {
  struct dictionary d;
  d->cword  = "";
  d->dict   = new_ht(26, hashfunc, getkeyfunc); //compare how this is done in david's examples
}
  
  /* array of arrays of entry's */
  
  /* dynamically allocate arrays as entry's are read in from the input file. */
  
  /* find array where entry would be stored if in the dictionary */
  
  /* compare search term to the words in that array */
  
int d_read_from_file(const char * filename) {
  char line[MAX_WORD_SIZE + MAX_DESC_SIZE];
  while ( fgets(line,MAX_WORD_SIZE + MAX_DESC_SIZE,filename) != ".\0" )d {
    //hash key then place in bst along with definition;
  }
  
}

int d_lookup(const char * word, char * meaning) {
  
}
