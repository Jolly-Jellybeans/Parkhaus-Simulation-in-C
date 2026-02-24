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
int read_menu_choice(void);
bool read_vehicle_from_user(Vehicle *p_vehicle);
void print_parking_garage_status(const ParkingGarage *p_garage);
void print_result_message(ParkingResult result);
#endif /* IO_H */