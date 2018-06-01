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
	<summary>User functions implementation</summary>
*/

#define _CRT_SECURITY_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "Hashtable.h"
#include "CreateFunctions.h"
#include "UserFunctions.h"
#include "Utils.h"

/*
Let's the user create a new flight
*/
Flight* CreateNewFlight(HashTable* ht, Airplane* airplane) {

	if (ht == NULL || airplane == NULL) {

		return NULL;

	}

	Flight* f = NULL;
	char buffer[20];
	struct tm* departureDate;

	// get data from the user

	printf("### Create Flight: ###\n");

	printf("- Input flight date in the format yyyy/mm/dd hh:mm :\n");

	fgets(buffer, sizeof(buffer), stdin);
	fflush(stdin);

	departureDate = NewDateFromString(buffer);

	f = CreateFlight(

		0,
		departureDate,
		NULL,
		airplane->SeatsNumber,
		CloneSeatsFromAirplane(airplane),
		airplane->ShuttleName

	);

	// only add the flight if it is unique
	if (CheckHashTableForFlightID(ht, f->ID) == NULL) {

		AddNodeToHashTable(ht, CreateNode(GetYearDayFromFlight(f), f));

	}
	else {

		free(f);
		f = NULL;

	}

	return f;

}
