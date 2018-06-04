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
	<summary>Output information to the user</summary>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "InfoOutput.h"

/*
Prints a Seat
*/
void PrintSeat(Seat* seat) {

	if (seat == NULL) {

		printf("'seat' argument was NULL.\n");

		return;

	}

	printf("Seat number: %i\n", seat->Number);
	printf("Seat priority status: %i\n", seat->IsPriority);
	printf("Seat status: %s\n", seat->IsOccupied == 0 ? "Free" : "Occupied");
	printf("Passenger Name: %s\n", seat->PassengerName);

};

/*
Prints an airplane
*/
void PrintAirplane(Airplane* airplane) {

	if (airplane == NULL) {

		printf("'airplane' argument was NULL.\n");

		return;

	}

	printf("---\n");
	printf("Shuttle name: %s\n", airplane->ShuttleName);
	printf("Number Of Seats: %i\n", airplane->SeatsNumber);

	for (unsigned int i = 0; i < airplane->SeatsNumber; i++) {

		PrintSeat(airplane->Seats[i]);

	}
	printf("---\n");
};

/*
Prints a flight
*/
void PrintFlight(Flight* flight) {

	if (flight == NULL) {

		printf("'flight' argument was NULL.\n");

		return;

	}
	
	char timeString[80];

	printf("---\n");

	printf("ID: %ld\n", flight->ID->value);

	printf("Flight Status: %s\n", flight->Status == 0 ? "Awaiting" : "Accomplished");
	printf("Flight Priority Status: %i\n", flight->IsPriority);
	printf("Aircraft: %s\n", flight->AirplaneName);

	
	strftime(timeString, 80, "%d/%m/%Y %H:%M", flight->Departure);
	printf("Departure: %s\n", timeString);
	
	if (flight->Status == 0) {

		printf("Arrive: Flight not accomplished yet.\n");

	}
	else {
	
		strftime(timeString, 80, "%d/%m/%Y %H:%M", flight->Arrive);
		printf("Arrive: %s\n", timeString);

	}	
	
	int unoccupiedSeats = 0;
	for (unsigned int i = 0; i < flight->SeatsNumber; i++) {

		if (flight->Seats[i]->IsOccupied) {
		
			PrintSeat(flight->Seats[i]);

		}
		else {

			unoccupiedSeats++;

		}
		
	}
	printf("Unoccupied Seats: %i\n", unoccupiedSeats);

	printf("---\n");

}

/*
Prints a line with the specified size of characters
*/
void PrintLine(int size) {

	for (int i = 0; i < size; i++) {
		printf("-");
	}
	printf("\n");

};