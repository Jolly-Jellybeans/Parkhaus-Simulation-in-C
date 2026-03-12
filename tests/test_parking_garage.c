#include <assert.h>
#include "parking_garage.h"

/*
Test 1:
Ein freier Slot existiert.
Die Funktion sollte den Index des ersten freien Slots zurückgeben.
*/
void test_find_free_slot_index_free_slot_exists() {

    ParkingSlot slots[3];

    slots[0].is_occupied = true;
    slots[1].is_occupied = false;   // erster freier Slot
    slots[2].is_occupied = true;

    ParkingGarage garage;
    garage.p_slots = slots;
    garage.slot_count = 3;

    int result = find_free_slot_index(&garage);

    assert(result == 1);
}


/*
Test 2:
Alle Slots sind belegt.
Die Funktion sollte -1 zurückgeben.
*/
void test_find_free_slot_index_no_free_slot() {

    ParkingSlot slots[2];

    slots[0].is_occupied = true;
    slots[1].is_occupied = true;

    ParkingGarage garage;
    garage.p_slots = slots;
    garage.slot_count = 2;

    int result = find_free_slot_index(&garage);

    assert(result == -1);
}