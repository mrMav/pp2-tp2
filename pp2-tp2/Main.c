
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "InfoOutput.h"
#include "CreateFunctions.h"
#include "Hashtable.h"
#include "Utils.h"

int main() {
	
	Airplane* DaVinci = CreateAirplane("DaVinci", 12);
	//PrintAirplane(DaVinci);

	DaVinci->Seats[0]->IsOccupied = 1;
	strcpy(DaVinci->Seats[0]->PassengerName, "Jorge Noro");

	Flight* flight1 = CreateFlight(

		1,
		CreateDate(31, 5, 2018, 18, 20, 20),
		CreateDate(31, 5, 2018, 19, 20, 20),
		DaVinci->SeatsNumber,
		CloneSeatsFromAirplane(DaVinci),
		DaVinci->ShuttleName

	);

	DaVinci->Seats[1]->IsOccupied = 1;
	strcpy(DaVinci->Seats[1]->PassengerName, "Ângela Torres");

	Flight* flight2 = CreateFlight(

		0,
		CreateDate(1, 6, 2018, 18, 20, 20),
		NULL,
		DaVinci->SeatsNumber,
		CloneSeatsFromAirplane(DaVinci),
		DaVinci->ShuttleName

	);

	Flight* flight3 = CreateFlight(

		0,
		CreateDate(1, 6, 2019, 18, 20, 20),
		NULL,
		DaVinci->SeatsNumber,
		CloneSeatsFromAirplane(DaVinci),
		DaVinci->ShuttleName

	);

	HashTable* flights = CreateHashTable();

	AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(flight1), flight1));
	AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(flight2), flight2));
	AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(flight3), flight3));

	PrintHashTable(flights);

	getchar();
	return 0;
}