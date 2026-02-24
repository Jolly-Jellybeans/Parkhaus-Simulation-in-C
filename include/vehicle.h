#ifndef VEHICLE_H
#define VEHICLE_H

typedef struct
{
  int id;
  int remaining_duration;
  int entry_time;
} Vehicle;
bool vehicle_is_valid(const Vehicle *p_vehicle);
bool vehicle_has_license_plate(const Vehicle *p_vehicle,const char *p_license_plate);
#endif
