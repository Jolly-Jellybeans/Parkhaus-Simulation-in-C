#ifndef VEHICLE_H
#define VEHICLE_H

typedef struct
{
  int id;
  int remaining_duration;
  int entry_time;
} Vehicle;
/**
 * @brief Prüft, ob eine Fahrzeugstruktur gültige Werte enthält.
 *
 * @param[in] p_vehicle Zu überprüfendes Fahrzeug.
 * @return true, wenn das Fahrzeug validiert werden kann, sonst false.
 */
bool vehicle_is_valid(const Vehicle *p_vehicle);
/**
 * @brief Vergleicht das gegebene Kennzeichen mit dem im Fahrzeug gespeicherten.
 *
 * @param[in] p_vehicle Fahrzeugdatenknoten.
 * @param[in] p_license_plate Erwartetes Kennzeichen.
 * @return true, wenn das Kennzeichen übereinstimmt, sonst false.
 */
bool vehicle_has_license_plate(const Vehicle *p_vehicle,const char *p_license_plate);
#endif
