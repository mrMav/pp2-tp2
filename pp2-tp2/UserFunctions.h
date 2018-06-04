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
	<summary>User functions definition</summary>
*/

#ifndef USERFUNCTIONS
#define USERFUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "Hashtable.h"

/*
Lets the user create a new flight
*/
Flight* CreateNewFlight(HashTable* ht, Airplane* airplane);

/*
Check for flight empty seats
*/
int CheckFlightForSeats(HashTable* ht, long int id);

/*
Lets the user book a seat
*/
int BookFlightSeat(HashTable* ht, long int id, unsigned int seatPosition);

/*
Lets the user cancel a reservation
*/
int CancelBooking(HashTable* ht, long int id);

/*
Count free seats in flight
*/
int CountFreeSeats(Flight* f);

/*
Set a seat to a passenger
*/
Seat* SetPassengerSeat(Seat* seat, char name[]);

/*
Set a seat free
*/
Seat* FreePassengerSeat(Seat* seat);

/*
Request flight id to user
*/
long int RequestFlightID();

/*
request name to user
*/
void RequestName(char* buffer, size_t size);

/*
get closest flight to hold n passengers
*/
Flight* GetClosestFlightHoldPassengers(HashTable* ht, int n, Airplane* plane);

/*
Sets a flight priority
0: not priority
1: priority
*/
void SetFlightPriority(Flight* f, int i);

/*
Sets a seat priority
0: not priority
1: priority
*/
void SetSeatPriority(Seat* s, int i);

/*
Prints flight from a specified date range
*/
void PrintSpecifiedRange(HashTable* flights, struct tm* start, struct tm* finish);


#endif // !USERFUNCTIONS

