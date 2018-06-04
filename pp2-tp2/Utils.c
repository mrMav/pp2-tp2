/*
	<license>
	MIT License
	Copyright(c) 2018 Jorge Noro
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files(the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions :
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
	</license>
	<author> Jorge Noro </author>
	<version>1.0.0</version>
	<summary>Utility functions implementation</summary>
*/

#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "Utils.h"
#include "CreateFunctions.h"

/*
Extract a key from an id
*/
int ExtractKeyFromID(long int id) {

	return (int)floor(id / 1000000) - 1;

}

/*
Get the year day from a flight
*/
int GetYearDayFromFlight(Flight* flight) {

	char yearDay[4]; // should not be bigger than 3 digits (extra one is for terminator char)

	strftime(yearDay, 4, "%j", flight->Departure);
	
	return atoi(yearDay);

}

/*
Clone a struct tm*
*/
struct tm* CloneStructtm(struct tm* t) {

	struct tm* date = malloc(sizeof(struct tm));

	if (date == NULL) {

		return NULL;

	}

	date->tm_year = t->tm_year;
	date->tm_mon = t->tm_mon;
	date->tm_mday = t->tm_mday;

	date->tm_hour = t->tm_hour;
	date->tm_min = t->tm_min;
	date->tm_sec = t->tm_sec;
	date->tm_isdst = t->tm_isdst;

	date->tm_wday = t->tm_wday;
	date->tm_yday = t->tm_yday;
	
	return date;

}

/*
From a string int the format yyyy/mm/dd
returns a pointer to a date
*/
struct tm* NewDateFromString(char string[]) {
	
	char ano[5];
	char mes[3];
	char dia[3];

	char horas[3];
	char minutos[3];

	ano[0] = string[0];
	ano[1] = string[1];
	ano[2] = string[2];
	ano[3] = string[3];

	mes[0] = string[5];
	mes[1] = string[6];

	dia[0] = string[8];
	dia[1] = string[9];

	horas[0] = string[11];
	horas[1] = string[12];

	minutos[0] = string[14];
	minutos[1] = string[15];
	
	return CreateDate(atoi(dia), atoi(mes), atoi(ano), atoi(horas), atoi(minutos), 0);

}

/*
Clone and return a Seats array from an airplane
*/
Seat** CloneSeatsFromAirplane(Airplane* plane) {

	// create seats array
	Seat** s = (Seat**)malloc(sizeof(Seat*) * plane->SeatsNumber);

	for (unsigned int i = 0; i < plane->SeatsNumber; i++) {

		s[i] = CreateSeat(plane->Seats[i]->Number);

		s[i]->IsOccupied = plane->Seats[i]->IsOccupied;
		strcpy(s[i]->PassengerName, plane->Seats[i]->PassengerName);

	}

	return s;

}

/*
Clear stdin
*/
void ClearInput() {
	
	char c;

	while ((c = getchar()) != '\n' && c != EOF) {}

}