#include <assert.h>
#include "parking_garage.h"

void clear_slot(ParkingSlot *p_slot);

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

/*
Test 1:
Ein belegter Slot mit gesetzten Werten wird geleert.
Alle Slot- und Fahrzeugwerte muessen auf den Ausgangszustand zurueckgesetzt werden.
*/
void test_clear_slot_resets_all_fields() {

    ParkingSlot slot;

    slot.vehicle.id = 42;
    slot.vehicle.remaining_duration = 7;
    slot.vehicle.entry_time = 12;
    slot.departure_time = 19;
    slot.is_occupied = true;

    clear_slot(&slot);

    assert(slot.vehicle.id == 0);
    assert(slot.vehicle.remaining_duration == 0);
    assert(slot.vehicle.entry_time == 0);
    assert(slot.departure_time == 0);
    assert(slot.is_occupied == false);
}

/*
Test 2:
Ein NULL-Zeiger wird uebergeben.
Die Funktion darf nicht abstuerzen und muss direkt zurueckkehren.
*/
void test_clear_slot_with_null_pointer() {

    clear_slot(NULL);

    assert(1);
}