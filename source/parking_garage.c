#include "parking_garage.h"
static int find_free_slot_index(const ParkingGarage *p_garage);
static int find_slot_by_license_plate(const ParkingGarage *p_garage,const char *p_license_plate);
static void assign_slot(ParkingSlot *p_slot,const Vehicle *p_vehicle,int current_time);
static void clear_slot(ParkingSlot *p_slot);