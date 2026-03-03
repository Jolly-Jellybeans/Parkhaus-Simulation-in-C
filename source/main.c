#include "parking_garage.h"
#include "statistics.h"
#include "queue.h"
#include "vehicle.h"
#include "io.h"
#include "simulation.h"


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
  IF p_garage is NULL THEN
      RETURN -1
  END IF

  stats ← empty Statistics structure
  CALL statistics_init(ADDRESS OF stats)

  // 3. SIMULATION
  // Simulationsparameter aus config-Struktur übergeben.
  CALL simulation(p_garage,
                  ADDRESS OF stats,
                  config.sim_duration,
                  config.arrival_prob,
                  config.max_park_duration)

  // 4. ENDE
  // Gesamtstatistik ausgeben und Ressourcen freigeben.
  CALL statistics_print(ADDRESS OF stats)
  CALL parking_garage_destroy(p_garage)

  RETURN 0

END FUNCTION
*/
