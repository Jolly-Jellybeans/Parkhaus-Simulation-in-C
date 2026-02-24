#ifndef IO_H
#define IO_H
#include "parking_garage.h"
#include "vehicle.h"
//Hier Programm:
/**
 * @brief Gibt das Hauptmenü der Parkhaus-Simulation in der Konsole aus.
 *
 * @return Kein Rückgabewert.
 */
void print_menu(void);
/**
 * @brief Liest die Menüauswahl des Benutzers von der Konsole ein.
 *
 * @return Eingegebene Menüoption als Ganzzahl.
 */
int read_menu_choice(void);
/**
 * @brief Liest die Fahrzeugdaten vom Benutzer ein und speichert sie in der übergebenen Struktur.
 *
 * @param[out] p_vehicle Zeiger auf die Fahrzeugstruktur, die mit Benutzereingaben gefüllt wird.
 * @return true, wenn die Eingabe erfolgreich war, sonst false.
 */
bool read_vehicle_from_user(Vehicle *p_vehicle);
/**
 * @brief Gibt den aktuellen Zustand des Parkhauses in der Konsole aus.
 *
 * @param[in] p_garage Zeiger auf die Parkhausstruktur mit dem aktuellen Status.
 * @return Kein Rückgabewert.
 */
void print_parking_garage_status(const ParkingGarage *p_garage);
void print_result_message(ParkingResult result);
#endif /* IO_H */