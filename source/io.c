#include "io.h"

/**
 * @brief Entfernt verbleibende Zeichen aus dem Eingabepuffer, um saubere Lesefolgen zu gewährleisten.
 */

/*
---------------------------------------------
---------------------------------------------
  PSEUDOCODE - Input validation
---------------------------------------------
---------------------------------------------

-------------------------------------------------
FUNCTION user_input(description) RETURNS integer
-------------------------------------------------   
    PRINT description                   // show prompt text to the user

    LOOP forever                        // keep asking until input is valid
        READ value

        IF value is not numeric THEN
            PRINT "Please enter a number."
            CONTINUE                    // ask again
        END IF

        RETURN value                    // valid number was entered
    END LOOP
END FUNCTION

---------------------------------------------------------------
FUNCTION get_config_from_user() RETURNS SimulationConfig
---------------------------------------------------------------  
    NEW config (Type SimulationConfig)  // create new config object

    config.slots            <- CALL user_input("Anzahl der Stellplätze: ")
    config.max_park_duration<- CALL user_input("Maximale Parkdauer (pro Auto): ")
    config.sim_duration     <- CALL user_input("Gesamte Simulationsdauer: ")
    config.arrival_prob     <- CALL user_input("Ankunftswahrscheinlichkeit (0-100): ")
    config.seed             <- CALL user_input("Zufalls-Seed (z.B. 42): ")

    RETURN config                      // return all user values
END FUNCTION
*/
/*
-----------------------------------------------------------
  FUNCTION print_result_message(result)
-----------------------------------------------------------
    SWITCH result                                                        // handle all result cases
          CASE PARKING_SUCCESS:
              PRINT "Vehicle parked successfully."
          CASE PARKING_QUEUED:
              PRINT "Parking full. Vehicle added to waiting queue."
          CASE PARKING_QUEUE_FULL:
              PRINT "Queue is full. Vehicle rejected."
          CASE PARKING_INVALID:
              PRINT "Invalid vehicle data."
          DEFAULT:
              PRINT "Unknown parking result."
    END SWITCH
  END FUNCTION
*/
/*
-----------------------------------------------------------
  END OF PSEUDOCODE
-----------------------------------------------------------
*/

static void clear_input_buffer(void);

