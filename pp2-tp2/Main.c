#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "InfoOutput.h"
#include "CreateFunctions.h"

int main() {
		
	Airplane* DaVinci = CreateAirplane("DaVinci", 12);

	PrintAirplane(DaVinci);

	getchar();
	return 0;
}