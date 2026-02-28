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
 * @brief Gibt den aktuellen Zustand des Parkhauses in der Konsole aus.
 *
 * @param[in] p_garage Zeiger auf die Parkhausstruktur mit dem aktuellen Status.
 * @return Kein Rückgabewert.
 */
void print_parking_garage_status(const ParkingGarage *p_garage);
/**
 * @brief Gibt eine Meldung zum Ergebnis eines Parkvorgangs in der Konsole aus.
 *
 * @param[in] result Ergebnisstatus des Parkvorgangs.
 * @return Kein Rückgabewert.
 */
void print_result_message(ParkingResult result);
#endif /* IO_H */