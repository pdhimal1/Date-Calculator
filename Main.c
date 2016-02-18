/*
 * Prakash Dhimal
 * Main.c 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "date.h"

#define SIZE_OF_DATE 11
struct tm today;

void processRequest(int request);
void mainMenu();


int main(int argc, char **argv)
{
	
	today = getDate();	
	char *buffer = (char *) malloc (sizeof(char) * SIZE_OF_DATE);	
	sprintf(buffer, "%02d%s%02d%s%04d", today.tm_mon, "-", today.tm_mday, "-", today.tm_year);	

	printf("Welcome to date Calculator: \n");
	printf("Today's Date is: '%s'\n", buffer);
	mainMenu();

	free(buffer);
	
	return 0;
}

void mainMenu()
{
	int request = 0;
	
	printf("\n1. Add days to todays Date\n");
	printf("2. Subtract days from today's date\n");
	printf("3. Exit.\n");
	printf("Choose from one of the options above: ");
	scanf("%d", &request);

	processRequest(request);	
}

void processRequest(int request)
{
	int i, numDays = 0;
	struct tm tmp;
	char *buffer = (char *) malloc (sizeof(char) * SIZE_OF_DATE);	
	tmp = today;

	switch (request)
	{
		case 1:
			printf("Enter number of days you want to go forward: ");
			scanf("%d", &numDays);
			for (i = 0; i < numDays; i++)
				tmp = getDayafter(tmp);
			sprintf(buffer, "%02d%s%02d%s%04d", tmp.tm_mon, "-", tmp.tm_mday, "-", tmp.tm_year);
			printf("\n%d days after today is: %s\n", numDays, buffer);
			mainMenu();
			break;
		case 2:
			printf("Enter number of days you want to go back: ");
			scanf("%d", &numDays);
			for (i = 0; i < numDays; i++)
				tmp = getDaybefore(tmp);
			sprintf(buffer, "%02d%s%02d%s%04d", tmp.tm_mon, "-", tmp.tm_mday, "-", tmp.tm_year);
			printf("\n%d days before today was: %s\n", numDays, buffer);
			mainMenu();
			break;
		case 3:
			printf("Good bye!\n");
			break;
		default:
			mainMenu();
			break;
	}

	free(buffer);
}
