#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * removeDuplicates(char word []);
int targetFound(char charArray[], int num, char target);
void initializeEncryptArray(char key[], char encrypt[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main (int argc, char* argv[]){
  int choice, argLength;
  FILE *fin, *fout;
  char * key;
  
  if (argc != 5)
   {
     	printf ("Usage: cipher option key infile, outfile\n");
      	printf ("Option 1 for encryption and 2 for decryption");
      	exit(1);
   }
  
  //parse command line arguments into vars
  choice = atoi(argv[1]);
  key = (argv[2]);

  //init arrays
  char encrypt[26], decrypt[26];
  initializeEncryptArray(key, encrypt);
  initializeDecryptArray(encrypt, decrypt);
  
  fin = fopen(argv[3], "r");
  fout = fopen(argv[4], "w");



  //either encrypt or decrypt
  if(choice == 1) processInput(fin, fout, encrypt);
  if(choice == 2) processInput(fin, fout, decrypt);
  
  fclose(fin);
  fclose(fout);
  return 0;

  
  /* test stuff
  char swoop[]= "HELLOWORLD";
  char encrypt[26], decrypt[26];
  intializeEncryptArray(swoop, encrypt);
  initializeDecryptArray(encrypt, decrypt);
  printf("enc: %s\n", encrypt);
  printf("dec: %s\n", decrypt);
  */
}

char * removeDuplicates(char word[]){
  char*rPoint = (char*) malloc(sizeof(char) * strlen(word));
  int i = 0, j = 0, k = 0, dupe = 0;
  while(word[i] != '\0'){
    while((int)rPoint[j] != 0){
      if(word[i] == rPoint[j]){
       dupe = 1;
       break;
      }
      j++;
    }
    j = 0;
    if(dupe != 1){
      rPoint[k] = word[i];
      k++;
    }
    dupe = 0;
    i++;
  }
  return rPoint;
}

int targetFound(char charArray[], int num, char target){
  int i = 0;
  while(i <= num){
    if(charArray[i] == target) return 1;
    i++;
  }
  return 0;
}  

void initializeEncryptArray(char key[], char encrypt[]){
  char*usedKey = removeDuplicates(key);
  int i = 0;
  while((int)usedKey[i] != 0){
    encrypt[i] = usedKey[i];
    i++;
  }
  int k = 90;
  while(k >= 65){
    if(targetFound(encrypt, i, (char)k) == 0){
      encrypt[i] = (char)k;
      i++;
    }
    k--;
  }
}

void initializeDecryptArray(char encrypt[], char decrypt[]){
  int i = 0;
  while(i < 26){
    decrypt[((int)encrypt[i])-65]=(char) (i + 65);
    i++;
  }
}

void processInput(FILE * inf, FILE * outf, char substitute[]){
  char ch;
  int parsed = 0;
  while(fscanf(inf, "%c", &ch) != EOF){
    if(isupper(ch)){
      parsed = ((int) ch) - 65;
      fprintf(outf, "%c", substitute[parsed]);
    }
    else if(islower(ch)){
      parsed = ((int) ch) - 97;
      fprintf(outf, "%c", substitute[parsed]+32);
    }
    else{
      fprintf(outf, "%c", ch);
    }
  }
}
