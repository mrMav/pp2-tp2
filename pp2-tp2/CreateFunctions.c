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
	<summary>Objects creation functions definition</summary>
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "CreateFunctions.h"
#include "Utils.h"

/*
Creates a Seat
*/
Seat* CreateSeat(unsigned int number) {

	Seat* s = (Seat*)malloc(sizeof(Seat));

	s->Number = number;
	s->IsOccupied = 0;
	strcpy(s->PassengerName, "");

	return s;
}

/*
Creates an airplane
*/
Airplane* CreateAirplane(char name[], unsigned int seatsNumber) {

	Airplane* a = (Airplane*)malloc(sizeof(Airplane));

	if (a == NULL) {

		return NULL;

	}

	strcpy(a->ShuttleName, name);
	a->SeatsNumber = seatsNumber;

	// create seats array
	a->Seats = (Seat**)malloc(sizeof(Seat*) * seatsNumber);

	for (unsigned int i = 0; i < seatsNumber; i++) {

		a->Seats[i] = CreateSeat(i + 1);
		
	}

	return a;

}

/*
Create a flight
*/
Flight* CreateFlight(int status, struct tm* departure, struct tm* arrive, unsigned int seatsNumber, Seat** seats, char airplaneName[]) {

	Flight* f = (Flight*)malloc(sizeof(Flight));

	if (f == NULL) {

		return NULL;

	}

	f->Status = status;
	f->Departure = departure;
	f->Arrive = arrive;
	f->SeatsNumber = seatsNumber;
	f->Seats = seats;
	strcpy(f->AirplaneName, airplaneName);
	sprintf(f->ID, "%04d%02d%02d%02d%02d", departure->tm_year+1900, departure->tm_mon+1, departure->tm_mday, departure->tm_hour, departure->tm_min);
	
	return f;

}

/*
Create a date structure
http://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
*/
struct tm* CreateDate(int day, int month, int year, int hour, int minutes, int seconds) {

	struct tm* date = malloc(sizeof(struct tm));
	
	if (date == NULL) {

		return NULL;

	}

	date->tm_year = year - 1900;  // notice the - 1900;
	date->tm_mon = month - 1;     // notice the - 1
	date->tm_mday = day;

	// init rest of components
	date->tm_hour = hour;
	date->tm_min = minutes;
	date->tm_sec = seconds;
	date->tm_isdst = -1;

	time_t t = mktime(date);
	struct tm* dateCalculated = localtime(&t);
	
	date = CloneStructtm(dateCalculated);

	return date;

}