#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"
#include "clist.h"
#include "ht.h"

struct dictionary
{
  ht *   dict;
} d;

struct entry
{
  char   word[MAX_WORD_SIZE];
  char   desc[MAX_DESC_SIZE];
};

const char * getkey(any e) {
  return ((struct entry*)e)->word;
}

/* hash uses Dan Bernstein's djb2 hash algorithm, which */
/* I accessed via http://www.cse.yorku.ca/~oz/hash.html */
int hash(any e) {
  int             hash, c;
  unsigned long   interim = 5381;
  char            word[MAX_WORD_SIZE];
  strcpy(word,getkey(e));
  
  
  while (c = (*word=*word+1))
    interim = ((interim << 5) + interim) + c;
  
  hash = interim % 4093;
  return hash;
}

void d_initialise() {
//  struct dictionary d;
  d.dict   = new_ht(4093, hash, getkey); //compare how this is done in david's examples
}
  
int d_read_from_file(const char * filename) {
  
  FILE *fp = fopen(filename, "r");
  char line[MAX_WORD_SIZE + MAX_DESC_SIZE + 1];
  char word[MAX_WORD_SIZE];
  char desc[MAX_DESC_SIZE];
  struct entry this;
  int result;
  
//  fgets(open,MAX_WORD_SIZE + MAX_DESC_SIZE,filename);
  while ( fgets(line,MAX_WORD_SIZE + MAX_DESC_SIZE + 1,fp) != "." ) {
//    fscanf(fp, "%s", word);
    /*this.word = */fscanf(fp, "%s", this.word);//(char) word[];
    fscanf(fp+sizeof(char), "%[^\n]", this.desc);
//    this.desc = desc;
    ht_insert(d.dict,&this);
  }
  fclose(fp);
  
}

int d_lookup(const char * word, char * meaning) {
  //meaning = meaning associated with a successful lookup (look at ht_lookup)
  int bucket = hash(word);
  any a;
  
  if (a = ht_lookup(d.dict,word)) {//(clist_isempty(d.dict->items[bucket]))
    meaning = ((struct entry*)a)->desc;
    return 1;
  }    
  else {
    return 0;
  }
    
}
/*
FILE *fp;
char word[30];
char def[200];
fp = fopen("d1.txt", "r");
fscanf(fp, "%s", word);
printf("Word: %s\n", word);
fscanf(fp, "%[^\n]", meaning);
printf("meaning: %s\n", meaning);

fclose(fp);*/
