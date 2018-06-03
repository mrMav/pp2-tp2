
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
		printf("2. Book flight seat\n");
		printf("3. Cancel booking\n");
		printf("4. Print a specified flight\n");
		printf("5. List all flights\n");
		printf("8. Help\n");
		printf("x. Update Flights Status\n");


		PrintLine(10);

		printf("> ");

		scanf("%i", &option);
		ClearInput();

		switch (option) {

#pragma region [Exit Program]

		case 0:

			exit = 0;
			break;

#pragma endregion

#pragma region [Create a new flight]
			
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

#pragma endregion

#pragma region [Book flight seat]

		case 2:
		{
			char buffer[13];

			// get input
			printf("### Book flight seat: ###\n");

			printf("- Input flight ID:\n");

			fgets(buffer, sizeof(buffer), stdin);
			ClearInput();

			if (CheckFlightForSeats(flights, buffer) >= 0) {

				unsigned int seatPosition = 0;

				printf("- Input seat Number:\n");
				scanf("%i", &seatPosition);
				ClearInput();

				BookFlightSeat(flights, buffer, seatPosition);

			}
			else {

				printf("An error occurred while booking the flight.\n");

			}

		}
			option = -1;
			break;

#pragma endregion

#pragma region [Cancel booking]

		case 3:
		{
			char buffer[13];

			// get input
			printf("### Cancel flight booking: ###\n");

			printf("- Input flight ID:\n");

			fgets(buffer, sizeof(buffer), stdin);
			ClearInput();

			Flight* f = CheckHashTableForFlightID(flights, buffer);

			if (f != NULL) {

				char name[100];

				printf("- Input passenger name:\n");
				fgets(buffer, sizeof(buffer), stdin);
				ClearInput();

				// cancel flight


			}
			else {

				printf("An error occurred while booking the flight.\n");

			}

		}
		option = -1;
		break;

#pragma endregion

#pragma region [Print Flight]

		case 4:
		{
			char buffer[13];

			// get input
			printf("### Print Flight: ###\n");

			printf("- Input flight ID:\n");

			fgets(buffer, sizeof(buffer), stdin);
			ClearInput();

			Flight* f = CheckHashTableForFlightID(flights, buffer);

			if (f != NULL) {

				PrintFlight(f);

			}
			else {

				printf("The flight with id \"%s\" could not be found.\n", buffer);

			}

		}
			option = -1;
			break;

#pragma endregion

#pragma region [Print All Flights]

		case 5:

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

#pragma endregion

#pragma region [Help Topics]

		case 8:

			PrintLine(10);
			printf("### Help topics: ###.\n");
			printf("-> The flights ID are in the format yyyymmddhhmm.\n");
			PrintLine(10);

			option = -1;
			break;

#pragma endregion

		default:

			printf("Invalid selection. No action performed.\n");			

		}

		PrintLine(10);

	}

	return 0;
}