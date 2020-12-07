/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

// WRITTEN BY ALAN


#include <stdio.h>

unsigned int is_prime(unsigned int n){
  int res = 0; 
  int i;
      for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
          res = 0;
          break;
        }
        else {
          res = 1;
        }
    }

  return res;
}


int main(void){

  printf("%d\n", is_prime(1));  // 11 is a prime.      Should print 1.
  
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}