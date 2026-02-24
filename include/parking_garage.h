#ifndef PARKING_GARAGE_H
#define PARKING_GARAGE_H
#include "vehicle.h"
#include "queue.h"
//Hier Programm:
ParkingGarage *parking_garage_create(int slot_count);
void parking_garage_destroy(ParkingGarage *p_garage);
ParkingResult parking_garage_park(ParkingGarage *p_garage,const Vehicle *p_vehicle,int current_time);
ParkingResult parking_garage_unpark(ParkingGarage *p_garage,const char *p_license_plate,int current_time);
int parking_garage_remove_departing(ParkingGarage *p_garage,int current_time);
#endif /* PARKING_GARAGE_H */
