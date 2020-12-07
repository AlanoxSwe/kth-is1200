/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

// WRITTEN BY ALAN

#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int is_prime(int n){
  int res = 0; 
  int i;
      for (i = 2; i <= n / 2; i++){
        if (n % i == 0){
          res = 0;
          break;
        }
        else{
          res = 1;
        }
    }

  return res;
}

int counter = 0;
void print_number(int n){
    printf("%10d",n);       // 10 gives spaces that can or can not be filled by numbers
    counter++;
    if (counter % COLUMNS == 0) {
        printf("\n");
    }
}

void print_primes(int n){
  int i = 0;
    for (i = 2; i < n; i++) {
        if (is_prime(i)){
            print_number(i);
        }
    }
    printf("\n");
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2){
    print_primes(atoi(argv[1]));
  }
  else{
    printf("Please state an interger number.\n");
  }
  return 0;
}

 
