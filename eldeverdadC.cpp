#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct date {
	int day;
	int month;
	int year;
	int hour;
	int minutes;
	int seconds;
};

struct registry {
	char name[40];
	char address[40];
	long phoneNumber;
	struct date stDate;
}; void write()
{
	struct registry reg;
	char ans;

	struct tm* tp;
	time_t segundos;
	time(&segundos);
	tp = localtime(&segundos);

	do {

		printf("Nom: \n");
		//fflush(stdout);
		gets_s(reg.name);
		printf("Adress: \n");
		//fflush(stdout);
		gets_s(reg.address);
		printf("Telefon: \n");
		//fflush(stdout);
		scanf("%ld", &reg.phoneNumber);
		//fflush(stdin);
		reg.stDate.day = tp->tm_mday;
		reg.stDate.month = tp->tm_mon;
		reg.stDate.year = tp->tm_year + 1900;
		reg.stDate.hour = tp->tm_hour;
		reg.stDate.minutes = tp->tm_min;
		reg.stDate.seconds = tp->tm_sec;
		//printf("%s, %s, %ld, %d/%d/%d %d:%d:%d \n", reg.name, reg.address, reg.phoneNumber, reg.stDate.day, reg.stDate.month, reg.stDate.year, reg.stDate.hour, reg.stDate.minutes, reg.stDate.seconds);

		printf("Vols afegir un altre registre? (y/n): ");
		scanf("%c", &ans);
	
	

	} while (ans == 'y');
	FILE* stream;
	stream = fopen("c:\\ficheros\\textoo.txt", "a");
	if (stream == 0)
	{
		perror("Error: ");
		exit(0);
	}
	else fprintf(stream, "%s %s %ld %d %d %d %d %d %d \n", reg.name, reg.address, reg.phoneNumber, reg.stDate.day, reg.stDate.month, reg.stDate.year, reg.stDate.hour, reg.stDate.minutes, reg.stDate.seconds);
	fclose(stream);

}
void read()
{
	struct registry reg {};
	FILE* stream;
	stream = fopen("c:\\ficheros\\textoo.txt", "r");
	if (stream == 0)
	{
		perror("Error: ");
		exit(0);
	}
	else {
		printf("name \tadress \tphonenumber \tdata \n");
		while (!feof(stream))
		{
			fscanf(stream, "%s %s %ld %d %d %d %d %d %d \n", reg.name, reg.address, &reg.phoneNumber, &reg.stDate.day, &reg.stDate.month, &reg.stDate.year, &reg.stDate.hour, &reg.stDate.minutes, &reg.stDate.seconds);
			printf("%s\t%s\t%ld\t%d/%d/%d %d:%d:%d \n", reg.name, reg.address, reg.phoneNumber, reg.stDate.day, reg.stDate.month, reg.stDate.year, reg.stDate.hour, reg.stDate.minutes, reg.stDate.seconds);
		}



		fclose(stream);
	}
}



void main()
{

	//read();
	write();
}