#include "parking_garage.h"

/**
 * @brief Sucht einen freien Stellplatz und liefert dessen Index zurück.
 */
static int find_free_slot_index(const ParkingGarage *p_garage);
/**
 * @brief Leert einen Stellplatz und setzt ihn auf den Ausgangszustand zurück.
 */
static void clear_slot(ParkingSlot *p_slot);

FUNCTION parking_garage_park(p_garage, p_vehicle, current_time)

    IF p_garage = NULL OR p_vehicle = NULL OR NOT vehicle_is_valid(p_vehicle) 
    THEN RETURN PARKING_INVALID
    END IF

    free_index ← find_free_slot_index(p_garage)

    IF free_index ≥ 0 THEN

        slot ← p_garage.p_slots[free_index]

        slot.vehicle ← p_vehicle
        slot.vehicle.entry_time ← current_time
        slot.departure_time ← current_time + p_vehicle.remaining_duration
        slot.is_occupied ← true

        p_garage.occupied_count ← p_garage.occupied_count + 1

        RETURN PARKING_SUCCESS
    END IF

    IF queue_enqueue(p_garage.p_queue, p_vehicle) 
    THEN RETURN PARKING_QUEUED
    END IF

    RETURN PARKING_QUEUE_FULL

END FUNCTION
}