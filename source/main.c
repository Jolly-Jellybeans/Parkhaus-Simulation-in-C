#include "parking_garage.h"
#include "statistics.h"
#include "queue.h"
#include "vehicle.h"
#include "io.h"


/*
// -----------------------------------------------
// PSEUDOCODE
//------------------------------------------------

BEGIN Menu Logic

    CREATE parking garage with fixed number of slots    // allocate parking garage
    INITIALIZE statistics structure                     // prepare statistics tracking

    SET running = true                                  // control variable for loop

    WHILE running DO

        DISPLAY main menu
        PROMPT user for input                           // ask user for choice
        READ user choice from input
        VALIDATE user input

        IF choice == 1 THEN                            // park a new vehicle
            READ vehicle data from user                
            VALIDATE vehicle data
            TRY to park vehicle in garage
            DISPLAY result message
            UPDATE statistics if necessary

        ELSE IF choice == 2 THEN                       // process departures
            PROCESS departures based on current simulation time
            UPDATE statistics

        ELSE IF choice == 3 THEN                       // show garage state
            DISPLAY current parking garage status

        ELSE IF choice == 4 THEN                       // show statistics
            DISPLAY collected statistics

        ELSE IF choice == 0 THEN                       // exit program
            SET running = false

        ELSE
            DISPLAY "Invalid input"

        END IF

    END WHILE

    DESTROY parking garage
    TERMINATE program

END PROGRAM
*/

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
