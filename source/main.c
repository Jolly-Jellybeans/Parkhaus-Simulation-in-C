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

  // 1. CONFIGURATION
  // Create config struct and fill it from user input
  config <- CALL get_config_from_user()

  // 2. INITIALIZATION
  CALL srand(config.seed)

  garage <- CALL parking_garage_create(config.slots)
  IF garage is NULL THEN
      RETURN -1
  END IF

  stats <- empty Statistics structure
  CALL statistics_init(ADDRESS OF stats)

  // 3. SIMULATION
  // Pass values from config struct into simulation
  CALL simulation(garage,
                  ADDRESS OF stats,
                  config.sim_duration,
                  config.arrival_prob,
                  config.max_park_duration)

  // 4. END
  CALL print_result_message(ADDRESS OF stats)
  CALL parking_garage_destroy(garage)

  RETURN 0

END FUNCTION
*/
