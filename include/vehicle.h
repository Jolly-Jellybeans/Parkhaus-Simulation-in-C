#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdbool.h>

typedef struct
{
  int id;
  int remaining_duration;
  int entry_time;
} Vehicle;


/*
STRUCT Vehicle
    id                        // Unique vehicle identifier
    remaining_duration        // Remaining parking duration
    entry_time                // time when vehicle entered the garage

END STRUCT
*/

/**
 * @brief Prüft ob ein Fahrzeug gültige Daten enthält.
 *
 * @param[in] p_vehicle Zeiger auf das zu prüfende Fahrzeug.
 * @return true wenn id > 0 und remaining_duration > 0, sonst false.
 */
bool vehicle_is_valid(const Vehicle *p_vehicle);

#endif
