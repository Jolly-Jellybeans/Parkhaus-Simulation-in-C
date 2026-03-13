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

/*
Test 3:
id <= 0 muss ungueltig sein.
*/
void test_vehicle_is_valid_with_invalid_id(void)
{
	Vehicle v = { .id = 0, .remaining_duration = 5, .entry_time = 0 };
	assert(vehicle_is_valid(&v) == false);
}

/*
Test 4:
remaining_duration <= 0 muss ungueltig sein.
*/
void test_vehicle_is_valid_with_invalid_duration(void)
{
	Vehicle v_zero = { .id = 1, .remaining_duration = 0, .entry_time = 0 };
	Vehicle v_negative = { .id = 1, .remaining_duration = -2, .entry_time = 0 };

	assert(vehicle_is_valid(&v_zero) == false);
	assert(vehicle_is_valid(&v_negative) == false);
}

/*
Test 5:
entry_time hat keinen Einfluss auf die Validierung.
*/
void test_vehicle_is_valid_ignores_entry_time(void)
{
	Vehicle v_negative_entry = { .id = 2, .remaining_duration = 3, .entry_time = -10 };
	assert(vehicle_is_valid(&v_negative_entry) == true);
}
