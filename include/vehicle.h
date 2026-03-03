#ifndef VEHICLE_H
#define VEHICLE_H

/*
typedef struct
{
  int id;
  int remaining_duration;
  int entry_time;
} Vehicle;
*/

/*
STRUCT Vehicle
    id                        // Unique vehicle identifier
    remaining_duration        // Remaining parking duration
    entry_time                // time when vehicle entered the garage

END STRUCT
*/

/**
 * @brief Prüft, ob eine Fahrzeugstruktur gültige Werte enthält.
 *
 * @param[in] p_vehicle Zu überprüfendes Fahrzeug.
 * @return true, wenn das Fahrzeug validiert werden kann, sonst false.
 */
bool vehicle_is_valid(const Vehicle *p_vehicle);

#endif
