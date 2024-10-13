#include <stdio.h> //For input/print
#include <string.h> //For string stuff
#include <stdlib.h> //
#include <stdbool.h> //For true/false

void addTwoMatrices(); 
void multiplyTwoMatrices();
void transposeMatrix();
void printMatrix();

int main() {
	int userInput;

	//Ask which function the user would like to run
	while(true) {
		printf("Which program would you like to run?\n");
		printf("1) Add Two Matrices\n2) Multiply Two Matrices\n3) Transpose a Matrix\n4) Print a Matrix\n5) Quit\nSelect a function (1-5): ");
		scanf("%d",&userInput);
		printf("\n");

		switch(userInput){
			case 1:
				printf("Running Function 1...\n--Add Two Matrices--\n");
				addTwoMatrices();
				break;
			case 2:
				printf("Running Function 2...\n--Multiply Two Matrices--");
				multiplyTwoMatrices();
				break;
			case 3:
				printf("Running Function 3...\n--Transpose a Matrix--");
				transposeMatrix();
				break;
			case 4:
				printf("Running Function 4...\n--Print a Matrix--");
				printMatrix();
				break;
			case 5:
				printf("Quitting Program...");
				break;
			default:
				printf("Select a valid input between 1 and 5.");
		}

		if(userInput == 5) {
			break;
		}


	}
}