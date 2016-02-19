/*
 * Prakash Dhimal
 * Main.c 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "date.h"

#define SIZE_OF_DATE 11
struct tm today;

void processRequest(int request);
void mainMenu();
struct tm getDateFromString(char *string);


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
	printf("3. Calculate your Age\n");
	printf("4. Exit.\n");
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
			printf("Enter your date of birth in mm-dd-yyyy or mm/dd/yyyy format\n");
			char dob[SIZE_OF_DATE];
			struct tm DOBinTM;
			scanf("%s", dob);
			DOBinTM = getDateFromString(dob);
			int age = differenceBetweenDates(today, DOBinTM);
			printf("\nYou are %d years old\n", age);
			mainMenu();
			break;
		case 4:
			printf("Good bye!\n");
			break;
		default:
			mainMenu();
			break;
	}

	free(buffer);
}

struct tm getDateFromString(char *string)
{
	char *tok;
	char *search = "-/ ";
	char dates[3][5];

	tok = strtok(string, search);

	int i = 0;
	while (tok != NULL)
	{
		//printf("%s\n", tok);
		strcpy(dates[i], tok);
		tok = strtok(NULL, search);
		i++;
	}
	
	int day = atoi(dates[1]);
	int month = atoi(dates[0]);
	int year = atoi(dates[2]);

	struct tm DOB;
	
	DOB.tm_mday = day;
	DOB.tm_mon = month;
	DOB.tm_year = year;


	return DOB;
}
