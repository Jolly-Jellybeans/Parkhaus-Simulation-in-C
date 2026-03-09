#include "parking_garage.h"

/**
 * @brief Sucht einen freien Stellplatz und liefert dessen Index zurück.
 */
static int find_free_slot_index(const ParkingGarage *p_garage);
/**
 * @brief Leert einen Stellplatz und setzt ihn auf den Ausgangszustand zurück.
 */
static void clear_slot(ParkingSlot *p_slot);

/*
FUNCTION find_free_slot_index(p_garage)

    // Sicherheitsprüfung: Ohne gültiges Parkhaus oder Slot-Array
    // kann kein freier Stellplatz ermittelt werden.
    IF p_garage = NULL OR p_garage.p_slots = NULL
    THEN RETURN -1
    END IF

    // Lineare Suche: Der erste nicht belegte Stellplatz wird sofort zurückgegeben.
    FOR i ← 0 TO p_garage.slot_count - 1

        IF p_garage.p_slots[i].is_occupied = false
        THEN RETURN i
        END IF

    END FOR

    // Kein freier Platz gefunden.
    RETURN -1

END FUNCTION

FUNCTION clear_slot(p_slot)

    // Sicherheitsprüfung: Ein NULL-Zeiger darf nicht dereferenziert werden.
    IF p_slot = NULL
    THEN RETURN
    END IF

    // Stellplatz vollständig auf den Ausgangszustand zurücksetzen,
    // damit keine alten Fahrzeugdaten im Slot verbleiben.
    p_slot.vehicle.id ← 0
    p_slot.vehicle.remaining_duration ← 0
    p_slot.vehicle.entry_time ← 0
    p_slot.departure_time ← 0
    p_slot.is_occupied ← false

END FUNCTION

FUNCTION parking_garage_park(p_garage, p_vehicle, current_time)

    // Eingaben prüfen: Ohne gültiges Parkhaus oder gültige Fahrzeugdaten
    // ist kein Parkvorgang möglich.
    IF p_garage = NULL OR p_vehicle = NULL OR NOT vehicle_is_valid(p_vehicle) 
    THEN RETURN PARKING_INVALID
    END IF

    // Zuerst versuchen, einen direkten freien Stellplatz zu finden.
    free_index ← find_free_slot_index(p_garage)

    IF free_index ≥ 0 THEN

        // Fahrzeug auf den freien Stellplatz übernehmen und Parkzeit festlegen.
        slot ← p_garage.p_slots[free_index]

        slot.vehicle ← p_vehicle
        slot.vehicle.entry_time ← current_time
        slot.departure_time ← current_time + p_vehicle.remaining_duration
        slot.is_occupied ← true

        // Belegung erhöhen und erfolgreichen Parkvorgang melden.
        p_garage.occupied_count ← p_garage.occupied_count + 1

        RETURN PARKING_SUCCESS
    END IF

    // Kein Platz frei: Fahrzeug in die Warteschlange einreihen.
    IF queue_enqueue(p_garage.p_queue, p_vehicle) 
    THEN RETURN PARKING_QUEUED
    END IF

    // Falls auch das Einreihen fehlschlägt, ist die Queue voll.
    RETURN PARKING_QUEUE_FULL

END FUNCTION

FUNCTION parking_garage_remove_departing(p_garage, current_time)

    // Sicherheitsprüfung: Ohne gültiges Parkhaus können keine Abfahrten verarbeitet werden.
    IF p_garage = NULL
    THEN RETURN 0
    END IF

    // Zählt, wie viele Fahrzeuge in diesem Schritt entfernt wurden.
    removed_count ← 0

    // Alle Stellplätze durchlaufen und Fahrzeuge entfernen,
    // deren Abfahrtszeit erreicht oder überschritten ist.
    FOR i ← 0 TO p_garage.slot_count - 1

        IF p_garage.p_slots[i].is_occupied = true AND p_garage.p_slots[i].departure_time ≤ current_time
        THEN
            // Stellplatz leeren und Belegungszähler aktualisieren.
            clear_slot(p_garage.p_slots[i])
            p_garage.occupied_count ← p_garage.occupied_count - 1
            removed_count ← removed_count + 1
        END IF

    END FOR

    // Anzahl der tatsächlich entfernten Fahrzeuge zurückgeben.
    RETURN removed_count

END FUNCTION
*/
static void clear_slot(ParkingSlot *p_slot){
    if (p_slot == NULL) {
        return;
    }

    p_slot->vehicle.id = 0;
    p_slot->vehicle.remaining_duration = 0;
    p_slot->vehicle.entry_time = 0;
    p_slot->departure_time = 0;
    p_slot->is_occupied = false;
}

int parking_garage_remove_departing(ParkingGarage *p_garage,int current_time){
    if(p_garage == NULL){
        return 0;
    }

    int removed_count = 0;

    for(int i = 0; i < p_garage->slot_count; i++){
        if(p_garage->p_slots[i].is_occupied && p_garage->p_slots[i].departure_time <= current_time){
            clear_slot(&p_garage->p_slots[i]);
            p_garage->occupied_count--;
            removed_count++;
        }
    }

    return removed_count;
}
static int find_free_slot_index(const ParkingGarage *p_garage){
    if (p_garage == NULL || p_garage->p_slots == NULL) {
        return -1;
    }

    for (int i = 0; i < p_garage->slot_count; i++) {
        if (!p_garage->p_slots[i].is_occupied) {
            return i;
        }
    }

    return -1;
}