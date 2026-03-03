#ifndef IO_H
#define IO_H
#include "parking_garage.h"
#include "vehicle.h"

/*
typedef struct
{
    int slots;
    int max_park_duration;
    int sim_duration;
    int arrival_prob;
    int seed;
} SimulationConfig;
*/
/*
STRUCT SimulationConfig
    Ganzzahl slots
    Ganzzahl max_park_duration
    Ganzzahl sim_duration
    Ganzzahl arrival_prob
    Ganzzahl seed
END STRUCT
*/

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
 * @brief Gibt eine Meldung zum Ergebnis eines Parkvorgangs in der Konsole aus.
 *
 * @param[in] result Ergebnisstatus des Parkvorgangs.
 * @return Kein Rückgabewert.
 */
void print_result_message(ParkingResult result);
#endif /* IO_H */
