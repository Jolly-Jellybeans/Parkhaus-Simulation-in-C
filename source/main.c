#include "parking_garage.h"
#include "statistics.h"
#include "queue.h"
#include "vehicle.h"
#include "io.h"
#include "simulation.h"
#include <stdlib.h>


/*
------------------------------------------------------
    PSEUDOCODE - Main program flow
------------------------------------------------------

FUNCTION main

  // 1. KONFIGURATION
  // Simulationsparameter vom Benutzer abfragen.
  config ← CALL get_config_from_user()

  // 2. INITIALISIERUNG
  CALL srand(config.seed)

  p_garage ← CALL parking_garage_create(config.slots)
  IF p_garage ist NULL THEN
      RETURN -1
  END IF

  stats ← leere Statistics-Struktur
  CALL statistics_init(ADRESSE VON stats)

  // 3. SIMULATION
  // Simulationsparameter aus config-Struktur übergeben.
  CALL simulation(p_garage,
                  ADRESSE VON stats,
                  config.sim_duration,
                  config.arrival_prob,
                  config.max_park_duration)

  // 4. ENDE
    // Gesamtstatistik ausgeben und gleichzeitig in Datei schreiben.
    CALL statistics_print(ADRESSE VON stats, "statistics_output.txt")
  CALL parking_garage_destroy(p_garage)

  RETURN 0

END FUNCTION
*/


int main(void)
{
    SimulationConfig config;
    ParkingGarage *p_garage;
    Statistics stats;

    config = get_config_from_user();            // read user settings

    srand(config.seed);            // initialize random generator

    p_garage = parking_garage_create(config.slots);            // create garage
    if (p_garage == NULL)
    {
        return EXIT_FAILURE;
    }

    statistics_init(&stats);            // initialize statistics

    simulation(
        p_garage,
        &stats,
        config.sim_duration,
        config.arrival_prob,
        config.max_park_duration
    );

    statistics_print(&stats, "statistics_output.txt");            // print final statistics and export to text file
    parking_garage_destroy(p_garage);            // free memory

    return 0;
}
