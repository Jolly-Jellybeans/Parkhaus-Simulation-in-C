#include <assert.h>
#include <stddef.h>
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

/*
Test 1:
Zwei belegte Slots haben ihre Abfahrtszeit bereits erreicht.
Die Funktion soll beide Fahrzeuge entfernen und die Belegung anpassen.
*/
void test_parking_garage_remove_departing_removes_due_vehicles() {

    ParkingSlot slots[3] = {0};
    ParkingGarage garage = {0};

    slots[0].vehicle.id = 1;
    slots[0].vehicle.remaining_duration = 3;
    slots[0].vehicle.entry_time = 2;
    slots[0].departure_time = 5;
    slots[0].is_occupied = true;

    slots[1].vehicle.id = 2;
    slots[1].vehicle.remaining_duration = 4;
    slots[1].vehicle.entry_time = 3;
    slots[1].departure_time = 8;
    slots[1].is_occupied = true;

    slots[2].vehicle.id = 3;
    slots[2].vehicle.remaining_duration = 6;
    slots[2].vehicle.entry_time = 4;
    slots[2].departure_time = 10;
    slots[2].is_occupied = true;

    garage.p_slots = slots;
    garage.slot_count = 3;
    garage.occupied_count = 3;

    int removed_count = parking_garage_remove_departing(&garage, 8);

    assert(removed_count == 2);
    assert(garage.occupied_count == 1);

    assert(slots[0].is_occupied == false);
    assert(slots[0].vehicle.id == 0);
    assert(slots[0].departure_time == 0);

    assert(slots[1].is_occupied == false);
    assert(slots[1].vehicle.id == 0);
    assert(slots[1].departure_time == 0);

    assert(slots[2].is_occupied == true);
    assert(slots[2].vehicle.id == 3);
    assert(slots[2].departure_time == 10);
}

/*
Test 2:
Kein Fahrzeug hat den Abfahrtszeitpunkt erreicht.
Die Funktion darf nichts entfernen und keine Werte veraendern.
*/
void test_parking_garage_remove_departing_keeps_future_vehicles() {

    ParkingSlot slots[2] = {0};
    ParkingGarage garage = {0};

    slots[0].vehicle.id = 11;
    slots[0].vehicle.remaining_duration = 2;
    slots[0].vehicle.entry_time = 1;
    slots[0].departure_time = 7;
    slots[0].is_occupied = true;

    slots[1].vehicle.id = 12;
    slots[1].vehicle.remaining_duration = 5;
    slots[1].vehicle.entry_time = 2;
    slots[1].departure_time = 9;
    slots[1].is_occupied = true;

    garage.p_slots = slots;
    garage.slot_count = 2;
    garage.occupied_count = 2;

    int removed_count = parking_garage_remove_departing(&garage, 6);

    assert(removed_count == 0);
    assert(garage.occupied_count == 2);

    assert(slots[0].is_occupied == true);
    assert(slots[0].vehicle.id == 11);
    assert(slots[0].departure_time == 7);

    assert(slots[1].is_occupied == true);
    assert(slots[1].vehicle.id == 12);
    assert(slots[1].departure_time == 9);
}