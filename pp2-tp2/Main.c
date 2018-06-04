
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
	
	srand(time(NULL)); // time based seed

	// the data structure where all the flights
	// are stored
	HashTable* flights = CreateHashTable();
	
	// the only current available aircraft
	Airplane* DaVinci = CreateAirplane("DaVinci", 12);

	// the current time
	struct tm* CurrentDate = NewDateFromString("2018/06/04");

	// init program menu
	int option = -1;
	int exit = 1;

	while (exit) {

		printf("ESTAir - Flight Management - %i/%i/%i\n", CurrentDate->tm_year + 1900, CurrentDate->tm_mon + 1, CurrentDate->tm_mday);
		printf("0. Exit\n");
		printf("1. Create new flight\n");
		printf("2. Book flight seat\n");
		printf("3. Cancel booking\n");
		printf("4. Print a specified flight\n");
		printf("5. List all flights\n");
		printf("6. Get soonest flight\n");
		printf("7. Set flight priority\n");
		printf("8. Print a specified flight in range\n");
		printf("9. Advance day\n");
		printf("10. Help\n");


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
				PrintFlightPretty(f);
					
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
			// get input
			printf("### Book flight seat: ###\n");
			
			long int id = RequestFlightID();

			if (CheckFlightForSeats(flights, id) >= 0) {

				unsigned int seatPosition = 0;

				printf("- Input seat Number:\n");
				scanf("%i", &seatPosition);
				ClearInput();
				
				BookFlightSeat(flights, id, seatPosition);

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
			// get input
			printf("### Cancel flight booking: ###\n");
			
			long int id = RequestFlightID();
			
			int result = CancelBooking(flights, id);

			if (result >= 0) {

				printf("Sucessfuly canceled reservation.\n");

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
			// get input
			printf("### Print Flight: ###\n");
			
			long int id = RequestFlightID();
			
			Flight* f = CheckHashTableForFlightID(flights, id);

			if (f != NULL) {

				PrintFlightPretty(f);

			}
			else {

				printf("The flight with id \"%ld\" could not be found.\n", id);

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

#pragma endregion

#pragma region [Get soonest]

		case 6:
		{
			// get input
			printf("### Get Soonest With Available Seats: ###\n");
			
			printf("- Please input number of seats:\n");

			int n;
			scanf("%i", &n);
			ClearInput();

			PrintFlightPretty(GetClosestFlightHoldPassengers(flights, n, DaVinci));

		}
		option = -1;
		break;

#pragma endregion

#pragma region [Set Flight Priority]

		case 7:
		{
			// get input
			printf("### Set Flight Priority: ###\n");

			long int id = RequestFlightID();

			Flight* f = CheckHashTableForFlightID(flights, id);

			if (f != NULL) {

				printf("- Input desired priority status? (0: No, 1: Yes)\n(Current is %i.)\n", f->IsPriority);

				int p;
				scanf("%i", &p);
				ClearInput();

				SetSeatPriority(f, p);

			}
			else {

				printf("The flight with id \"%ld\" could not be found.\n", id);

			}

		}
		option = -1;
		break;

#pragma endregion

#pragma region [Print a specified flight in range]

		case 8:
		{
			char startDateString[50];
			char finishDateString[50];

			struct tm* startDate;
			struct tm* finishDate;
			
			// get input
			printf("### Print a specified flight in range: ###\n");

			printf("- Input begin date yyyy/mm/dd hh:mm:\n");

			fgets(startDateString, sizeof(startDateString), stdin);
			ClearInput();

			printf("- Input finish date yyyy/mm/dd hh:mm:\n");

			fgets(finishDateString, sizeof(finishDateString), stdin);
			ClearInput();

			startDate = NewDateFromString(startDateString);
			finishDate = NewDateFromString(finishDateString);

			PrintSpecifiedRange(flights, startDate, finishDate);

		}
		option = -1;
		break;

#pragma endregion
			
#pragma region [Advance Day]

		case 9:
		{
			CurrentDate->tm_mday++;

			time_t current_t = mktime(CurrentDate);

			CurrentDate = CloneStructtm(localtime(&current_t));

			// update status of all flights
			UpdateFlightStatus(flights, CloneStructtm(CurrentDate));


			printf("Advanced one day!\n");
		}
			option = -1;
			break;

#pragma endregion

#pragma region [Help Topics]

		case 10:
		{					
			PrintLine(10);
			printf("### Help topics: ###.\n");
			printf("-> The flights ID are in the format dddyyhhmm;\n");
			printf("-> '*' means that a seat or flight is a priority.\n");
			PrintLine(10);
		}
		option = -1;
		break;

#pragma endregion

		// 11 fills with some flights to test
		case 11:
		{
			Flight* f = CreateFlight(
				0,
				CreateDate(1, 1, 2018, 18, 20, 20),
				NULL,
				DaVinci->SeatsNumber,
				CloneSeatsFromAirplane(DaVinci),
				DaVinci->ShuttleName
			);

			SetPassengerSeat(f->Seats[0], "some dude");
			SetPassengerSeat(f->Seats[1], "some dude");
			SetPassengerSeat(f->Seats[2], "some dude");

			AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(f), f));

			f = CreateFlight(
				0,
				CreateDate(2, 1, 2018, 18, 20, 20),
				NULL,
				DaVinci->SeatsNumber,
				CloneSeatsFromAirplane(DaVinci),
				DaVinci->ShuttleName
			);

			SetPassengerSeat(f->Seats[0], "some dude");
			SetPassengerSeat(f->Seats[1], "some dude");
			SetPassengerSeat(f->Seats[2], "some dude");
			SetPassengerSeat(f->Seats[3], "some dude");


			AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(f), f));

			f = CreateFlight(
				0,
				CreateDate(1, 1, 2019, 18, 20, 20),
				NULL,
				DaVinci->SeatsNumber,
				CloneSeatsFromAirplane(DaVinci),
				DaVinci->ShuttleName
			);

			SetPassengerSeat(f->Seats[0], "some dude");
			SetPassengerSeat(f->Seats[1], "some dude");
			SetPassengerSeat(f->Seats[2], "some dude");
			SetPassengerSeat(f->Seats[3], "some dude");
			SetPassengerSeat(f->Seats[4], "some dude");

			AddNodeToHashTable(flights, CreateNode(GetYearDayFromFlight(f), f));

			//PrintFlightPretty(f);

			//UpdateFlightStatus(flights, CloneStructtm(CurrentDate));

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