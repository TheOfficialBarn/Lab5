#include <stdio.h> //For input/print
#include <string.h> //For string stuff
#include <stdlib.h> //
#include <stdbool.h> //For true/false

#define SIZE 5


int getMatrices(int oneOrTwo);

void addTwoMatrices(); 
void multiplyTwoMatrices();
void transposeMatrix();
void printMatrix(int m[SIZE][SIZE]);

int main() {
	int userInput;

	//Ask which function the user would like to run
	while(true) {
		printf("Which program would you like to run?\n");
		printf("1) Add Two Matrices\n2) Multiply Two Matrices\n3) Transpose a Matrix\n4) Quit\nSelect a function (1-4): ");
		scanf("%d",&userInput);
		printf("\n");

		switch(userInput){
			case 1:
				printf("Running Function 1...\n--Add Two Matrices--\n");
				addTwoMatrices();
				break;
			case 2:
				printf("Running Function 2...\n--Multiply Two Matrices--\n");
				multiplyTwoMatrices();
				break;
			case 3:
				printf("Running Function 3...\n--Transpose a Matrix--\n");
				transposeMatrix();
				break;
			case 4:
				printf("Quitting Program...");
				break;
			default:
				printf("Select a valid input between 1 and 4.");
		}

		if(userInput == 4) {
			break;
		}
	}
}

void addTwoMatrices() {
	int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};

	int m3[SIZE][SIZE];
	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			//Perform matrix addition 
			m3[x][y] = m1[x][y]+m2[x][y];

		}
	}
	printMatrix(m3);

	//Return m3
}

void multiplyTwoMatrices() {
	int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};
	int m3[SIZE][SIZE] = {0}; //We have to initialize the matrix with zeroes due to the use of += operator
	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			for(int z = 0; z < SIZE; z++) {
            m3[x][y] += m1[x][z] * m2[z][y];
			}
		}
	}
	printMatrix(m3);
	//Return m3
}

void transposeMatrix() {
	int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	int mT[SIZE][SIZE];

	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			mT[y][x] = m1[x][y];
		}
	}
	printMatrix(mT);
	//Return mT
}

void printMatrix(int m[SIZE][SIZE]) {
	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			printf("%6d", m[x][y]);
		}
		printf("\n");
	}
	printf("\n———————————————————————\n\n");
}