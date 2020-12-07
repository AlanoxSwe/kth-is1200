// WRITTEN BY ALAN

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void mean_sieves(int n){
	int i;
	int j;
	char numbers[n];
	int count = 0;
	int primeSum = 0;
	double mean = 0;

	for (i = 0; i < n; i++){
		numbers[i] = 1; //Set all to 1
	}


	for (i = 2; i <= (int) sqrt(n); i++) {
		if (numbers[i]) {
			for (j = i*i; j < n; j += i) 
				numbers[j] = 0; //Set non-primes to 0
		}
	}

	for (i = 2; i < n; i++){
		if ((int) numbers[i]){ //If number[i] == 1 (true)
			//print_number(i);
			primeSum+=i;
			count++;
		}
	}

	mean = (double)primeSum/count;
	printf("%f\n", mean);
	
	printf("%d\n", primeSum);
	printf("%d", count);

}
/*
void print_sieves(int n){

	int i;
	int j;
	char numbers[n];

	for (i = 0; i < n; i++)
		numbers[i] = 1;

	for (i = 2; i <= (int) sqrt(n); i++) {
		if (numbers[i]) {
			for (j = i*i; j < n; j += i) 
				numbers[j] = 0;
		}
	}

	for (i = 2; i < n; i++){
		if ((int) numbers[i])
			print_number(i);
	}

	printf("\n");
}*/


int main(int argc, char *argv[]){
	if(argc == 2)
		mean_sieves(atoi(argv[1]));
	else
		printf("Please state an interger number.\n");
	return 0;
}
