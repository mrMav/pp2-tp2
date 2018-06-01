
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "InfoOutput.h"
#include "CreateFunctions.h"
#include "UserFunctions.h"
#include "Hashtable.h"
#include "Utils.h"

int main() {
	
	// the data structure where all the flights
	// are stored
	HashTable* flights = CreateHashTable();
	
	// the only current available aircraft
	Airplane* DaVinci = CreateAirplane("DaVinci", 12);

	// init program menu
	int option = -1;
	int exit = 1;

	while (exit) {

		printf("ESTAir - Flight Management\n");
		printf("0. Exit\n");
		printf("1. Create new flight\n");
		printf("2. List all flights\n");
		printf("x. Update Flights Status\n");


		PrintLine(10);

		printf("> ");

		scanf("%i", &option);
		ClearInput();

		switch (option) {

			// 0 exits the program
		case 0:

			exit = 0;
			break;

			// 1 allows to create a new flight
		case 1:

			{
				Flight* f = CreateNewFlight(flights, DaVinci);

				if (f != NULL) {

					printf("Successfuly created flight:\n");
					PrintFlight(f);
					
				}
				else {

					printf("An error occurred while creating the flight.\n");

				};

			}

			option = -1;
			break;

			// 2 prints all flights
		case 2:

			PrintHashTable(flights);

			option = -1;
			break;

			// 9 fills with some flights to test
		case 9:
			{
				Flight* f = CreateFlight(
					0,
					CreateDate(1, 6, 2019, 18, 20, 20),
					NULL,
					DaVinci->SeatsNumber,
					CloneSeatsFromAirplane(DaVinci),
					DaVinci->ShuttleName
				);

				AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(f), f));

				f = CreateFlight(
					0,
					CreateDate(17, 8, 2018, 18, 20, 20),
					NULL,
					DaVinci->SeatsNumber,
					CloneSeatsFromAirplane(DaVinci),
					DaVinci->ShuttleName
				);

				AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(f), f));
			}

			option = -1;
			break;

		default:

			printf("Invalid selection. No action performed.\n");			

		}

		PrintLine(10);

	}

	return 0;
}