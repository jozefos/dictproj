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

entry* passToHash(entry e) {
  //passing function
  ht_insert(function);
}

void d_initialise() {
  struct dictionary d;
  d->dict   = new_ht(4093, hashfun, getkeyfun); //compare how this is done in david's examples
}
  
int d_read_from_file(const char * filename) {
  
  FILE *fp = fopen(filename, "r");
  char line[MAX_WORD_SIZE + MAX_DESC_SIZE];
  char word[MAX_WORD_SIZE];
  char desc[MAX_DESC_SIZE];
  entry this;
  
  fgets(open,MAX_WORD_SIZE + MAX_DESC_SIZE,filename);
  while ( fgets(line,MAX_WORD_SIZE + MAX_DESC_SIZE,filename) != "." ) {
    fscanf(fp, "%s", word);
    this->word = word;
    fscanf(fp, "%[^\n]", meaning);
    this->desc = meaning;
    ht_insert(dict,this);
  }
  
  }
  
}

int d_lookup(const char * word, char * meaning) {
  //meaning = meaning associated with a successful lookup (look at ht_lookup)
}

FILE *fp;
char word[30]
char def[200]
fp = fopen("d1.txt", "r");
fscanf(fp, "%s", word);
printf("Word: %s\n", word);
fscanf(fp, "%[^\n]", meaning);
printf("meaning: %s\n", meaning);

fclose(fp);
