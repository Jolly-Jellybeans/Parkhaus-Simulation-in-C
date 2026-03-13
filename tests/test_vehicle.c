#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include "vehicle.h"

/*
Test 1:
NULL-Zeiger muss als ungueltig erkannt werden.
*/
void test_vehicle_is_valid_with_null_pointer(void)
{
	assert(vehicle_is_valid(NULL) == false);
}

/*
Test 2:
Gueltiges Fahrzeug (id > 0 und remaining_duration > 0).
*/
void test_vehicle_is_valid_with_valid_vehicle(void)
{
	Vehicle v = { .id = 1, .remaining_duration = 5, .entry_time = 0 };
	assert(vehicle_is_valid(&v) == true);
}


