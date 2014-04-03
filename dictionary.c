#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include "clist.h"
#include "ht.h"

struct dictionary
{
  char[]              currentword;
  ht_implementation   dict;
}  

void d_initialise() {
  
}
  
  /* array of arrays of entry's */
  
  /* dynamically allocate arrays as entry's are read in from the input file. */
  
  /* find array where entry would be stored if in the dictionary */
  
  /* compare search term to the words in that array */
  
int d_read_from_file(const char * filename) {
  
}

int d_lookup(const char * word, char * meaning) {
  
}
