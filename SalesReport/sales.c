#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 12
#define MAXLEN 100


// ————————————————————— PROTOTYPE FUNCTIONS ————————————————————————————————————————————
void printMonth(double sales[MAXLINES], char months[MAXLINES][MAXLEN]);
void printSummary(double sales[MAXLINES], char months[MAXLINES][MAXLEN]);
void sixMonthAverage(double sales[MAXLINES], char months[MAXLINES][MAXLEN], int start);
void printReport(double sales[MAXLINES], char months[MAXLINES][MAXLEN], int counter);
// ————————————————————— PROTOTYPE FUNCTIONS ————————————————————————————————————————————

// ————————————————————— MAIN FUNCTION ————————————————————————————————————————————
int main(){
	FILE* filePtr;
	char monthSales[MAXLINES][MAXLEN];
	double realSales[12];
	char months[12][MAXLEN] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int start = 0;

	filePtr = fopen("salesInput.txt", "r");

	if (filePtr == NULL) {
		printf("An issue has occured while attempting to open the file: 'salesInput.txt'.\n");
		return(1);
	}

	int line =0;

	while (!feof(filePtr) && !ferror(filePtr))
		if (fgets(monthSales[line], MAXLEN, filePtr) != NULL)
			line++;
	fclose(filePtr);

	for (int x=0; x < line; x++){
		realSales[x] = atof(monthSales[x]);
	}

	printMonth(realSales, months);
	printSummary(realSales, months);
	sixMonthAverage(realSales, months, start);
	printReport(realSales, months, start);

	return 0;
}
// ————————————————————— MAIN FUNCTION ————————————————————————————————————————————

// ————————————————————— FUNCTION DEFINITIONS ————————————————————————————————————————————
void printMonth(double sales[MAXLINES], char months[MAXLINES][MAXLEN]){
	printf("%-10s %6s\n", "Month", "Sales");
	for(int x=0; x<MAXLINES; x++){
		printf("%-10s%10.2lf\n", months[x], sales[x]);
	}
}

void printSummary(double sales[MAXLINES], char months[MAXLINES][MAXLEN]){
	double max = sales[0];
	double min = sales[0];
	int maxIndex = 0;
	int minIndex = 0;
	int x;
	double average = 0;

	printf("\n—————————————————————————————\nSales Summary Report:");

	for(x=0; x<MAXLINES; x++){
		if(sales[x] > max){
			max = sales[x];
			maxIndex = x;
		} else if(sales[x] < min){
			min = sales[x];
			minIndex = x;
		}
	}

	for(int y=0; y<MAXLINES; y++){
		average += sales[y];
	}
	average /= MAXLINES;

	printf("\n%-5s $%5.2lf (%7s)\n%-5s $%5.2lf (%7s)\n%-5s $%5.2lf\n", "Minimum Sales: ", min, months[minIndex], "Maximum Sales: ", max, months[maxIndex], "Average Sales: ", average);
}

void sixMonthAverage(double sales[MAXLINES], char months[MAXLINES][MAXLEN], int start){
	if(start==0){
		printf("\nSix-Month Moving Average Report: \n");
	}
	double sixAverage = 0;

	if(start < 7){
		for(int x=start; x<start+6; x++){
			sixAverage += sales[x];
		}
		sixAverage/=6;
		printf("%-10s-%-10s %.2lf\n", months[start], months[start+5], sixAverage);
		sixMonthAverage(sales,months, start+1);
	}else{
		return;
	}
}

void printReport(double sales[MAXLINES], char months[MAXLINES][MAXLEN], int counter){
	int x;
	int maxIndex;
	double max = sales[0];

	if(counter ==11){
		return;
	} else {
		if(counter == 0) printf("\nSales Report: \n");
		for (x=1; x<MAXLINES; x++){
			if (sales[x]>max){
				max = sales[x];
				maxIndex = x;
			}
		}
	}
	printf("%-10s %10.2lf\n", months[maxIndex], max);
	sales[maxIndex] = 0;
	printReport(sales, months, counter+1);
}
// ————————————————————— FUNCTION DEFINITIONS ————————————————————————————————————————————
