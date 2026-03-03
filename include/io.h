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
 * @brief Prompts the user for a numeric input.
 *
 * Displays the given description text in the console,
 * reads a value from the user and returns it.
 *
 * @param description Text shown to the user as input prompt.
 * @return The numeric value entered by the user.
 */
int user_input(const char *description);

/**
 * @brief Reads all simulation parameters from the user.
 *
 * Requests the required simulation configuration values
 * (number of slots, maximum parking duration, simulation duration,
 * arrival probability and random seed) and returns them
 * as a SimulationConfig structure.
 *
 * @return A SimulationConfig containing all user-defined parameters.
 */
SimulationConfig get_config_from_user(void);
/**
 * @brief Gibt eine Meldung zum Ergebnis eines Parkvorgangs in der Konsole aus.
 *
 * @param[in] result Ergebnisstatus des Parkvorgangs.
 * @return Kein Rückgabewert.
 */
void print_result_message(ParkingResult result);
#endif /* IO_H */
