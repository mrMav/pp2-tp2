
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "InfoOutput.h"
#include "CreateFunctions.h"

int main() {
		
	Airplane* DaVinci = CreateAirplane("DaVinci", 12);

	PrintAirplane(DaVinci);

	DaVinci->Seats[0]->IsOccupied = 1;
	strcpy(DaVinci->Seats[0]->PassengerName, "Jorge Noro");

	Flight* flight1 = CreateFlight(

		0,
		CreateDate(31, 5, 2018, 18, 20, 20),
		NULL,
		DaVinci->SeatsNumber,
		DaVinci->Seats,
		DaVinci->ShuttleName

	);

	PrintFlight(flight1);




	getchar();
	return 0;
}