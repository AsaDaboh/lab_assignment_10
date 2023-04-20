//Asa Daboh
//Lab Assignment #10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Trie 
{
  int wordct;
  struct Trie *next[26];
};

//void insert(struct Trie **ppTrie, char *word);
//int numberOfOccurances(struct Trie *pTrie, char *word);
//struct Trie *deallocateTrie(struct Trie *pTrie);

int numberOfOccurances(struct Trie *pTrie, char *word)
{

    struct Trie *temp = pTrie;
    
    if(pTrie == NULL)
      return 0;
    if(word == NULL)
      return 0;
  
    for (int i = 0; i < strlen(word); i++) {
      int x = word[i] - 'a'; 
      if (temp -> next[x] == NULL)
        return 0;
      temp = temp->next[x];
    }   
    return temp -> wordct;  
}


void insert(struct Trie **ppTrie, char* word) {
   
  struct Trie* temp = *ppTrie;

  if (ppTrie == NULL || word == NULL)
    return; 
  if(*ppTrie == NULL){

    struct Trie *newone = malloc(sizeof(struct Trie));
    newone->wordct = 0;

    for(int i = 0; i < 26; i++)
      newone -> next[i] = 0;

    *ppTrie = newone;
    
  }
    
  for (int i=0; word[i] != '0'; i++) {
        
    int index = (int) word[i] - 'a';
      
    if (temp == NULL || temp->next[index] == NULL ) {
            
      struct Trie *newtwo = malloc(sizeof(struct Trie));
      newtwo-> wordct = 0;
      for (int i = 0; i < 26; i++)
        newtwo->next[i] = 0;
      
      temp->next[index] = newtwo;
    }
  
    temp = temp->next[index];
  }
  
  temp -> wordct++;
}

struct Trie *deallocateTrie(struct Trie *pTrie){
  if(pTrie == NULL)
    return 0;
  for(int i = 0; i < 26; i++)
    if (pTrie->next[i] != NULL) {
            deallocateTrie(pTrie->next[i]);
        }
        else {
            continue;
        }
    
  free(pTrie);
  return NULL;
}


int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

      struct Trie* trie = NULL;
      
      for(int i = 0; i < 5; i++)
        insert(&trie, pWords[i]);
      
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
     }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}
