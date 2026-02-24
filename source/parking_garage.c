#include "parking_garage.h"

/**
 * @brief Sucht einen freien Stellplatz und liefert dessen Index zurück.
 */
static int find_free_slot_index(const ParkingGarage *p_garage);
/**
 * @brief Findet den Stellplatz-Index anhand des Fahrzeugkennzeichens.
 */
static int find_slot_by_license_plate(const ParkingGarage *p_garage,const char *p_license_plate);
/**
 * @brief Belegt einen Stellplatz mit den Informationen eines Fahrzeugs.
 */
static void assign_slot(ParkingSlot *p_slot,const Vehicle *p_vehicle,int current_time);
static void clear_slot(ParkingSlot *p_slot);