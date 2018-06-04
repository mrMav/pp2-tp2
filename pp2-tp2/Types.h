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
	<summary>Application types definition</summary>
*/

#ifndef TYPES
#define TYPES

#include <time.h>

/*
Defines a Key struct to be used on ID creation
and hashtable lookup
*/
typedef struct Key {

	int ddd;
	int yy;
	int hh;
	int mm;

	long int value;

} Key;

/*
Defines a seat in the airplane
*/
typedef struct Seat {

	int IsOccupied;

	unsigned int Number;

	char PassengerName[100];

} Seat;

/*
Defines an airplane
*/
typedef struct Airplane {

	// this airplane shuttle name
	char ShuttleName[100];
	
	// the number of available seats in this airplane
	unsigned int SeatsNumber;

	// the seats array (static data structure), created at runtime
	Seat** Seats;
	
} Airplane;

/*
Defines a flight data structure
*/
typedef struct Flight {

	// 0: awaiting, 1: accomplished 
	int Status;

	// departure time
	struct tm* Departure;

	// arrive time
	struct tm* Arrive;

	// number of seats
	unsigned int SeatsNumber;

	// list of the seats status in the flight
	Seat** Seats;

	// the airplane that will perform this flight
	char AirplaneName[100];

	// unique identifier
	Key* ID;

} Flight;

#endif // !TYPES

