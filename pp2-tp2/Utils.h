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
	<summary>Utility functions declarations</summary>
*/

#ifndef UTILS
#define UTILS

#include "Types.h"

/*
Extract a key from an id
*/
int ExtractKeyFromID(long int id);

/*
Get the year day from a flight
*/
int GetYearDayFromFlight(Flight* flight);

/*
Clone a struct tm*
*/
struct tm* CloneStructtm(struct tm* t);

/*
From a string int the format yyyy/mm/dd
returns a pointer to a date
*/
struct tm* NewDateFromString(char string[]);

/*
Clone and return a Seats array from an airplane
*/
Seat** CloneSeatsFromAirplane(Airplane* plane);

/*
Clear stdin
*/
void ClearInput();

#endif // !UTILS

