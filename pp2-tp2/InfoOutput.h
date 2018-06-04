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

#ifndef INFOOUTPUT
#define INFOOUTPUT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Types.h"

/*
Prints a Seat
*/
void PrintSeat(Seat* seat);

/*
Prints an airplane
*/
void PrintAirplane(Airplane* airplane);

/*
Prints a flight
*/
void PrintFlight(Flight* flight);

/*
Prints a flight pretty
*/
void PrintFlightPretty(Flight* flight);

/*
Prints a line with the specified size of characters
*/
void PrintLine(int size);

#endif // !INFOOUTPUT

