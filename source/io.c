#include "io.h"
#include <stdio.h>

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
    config.seed             <- CALL user_input("Zufalls-Seed: ")

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



void clear_input_buffer(void)
{
    int ch;          // variable to store each character

    while ((ch = getchar()) != '\n' && ch != EOF)      // read until end of line
    {
        ;
    }
}


int user_input(const char *description)
{
    int value;             // variable for the user input

    while (1)              // repeat until valid number is entered
    {
        printf("%s", description);         // print input description

        if (scanf("%d", &value) == 1)      // try to read integer
        {
            clear_input_buffer();          // clear remaining input
            return value;
        }

        printf("Please enter a number.\n");    // error message
        clear_input_buffer();                  // remove invalid input
    }
}

SimulationConfig get_config_from_user(void)
{
    SimulationConfig config;        // config object for all inputs

    config.slots = user_input("Anzahl der Stellplaetze: ");      // number of parking slots
    config.max_park_duration = user_input("Maximale Parkdauer (pro Auto): ");    // max parking duration
    config.sim_duration = user_input("Gesamte Simulationsdauer: ");        // total simulation time
    config.arrival_prob = user_input("Ankunftswahrscheinlichkeit (0-100): ");    // arrival probability
    config.seed = user_input("Zufalls-Seed: ");      // random seed

    return config;
}

void print_result_message(ParkingResult result)
{
    switch (result)      // check parking result
    {
        case PARKING_SUCCESS:
            printf("Vehicle parked successfully.\n");        // parked directly
            break;

        case PARKING_QUEUED:
            printf("Parking full. Vehicle added to waiting queue.\n");      // added to queue
            break;

        case PARKING_QUEUE_FULL:
            printf("Queue is full. Vehicle rejected.\n");      // queue full
            break;

        case PARKING_INVALID:
            printf("Invalid vehicle data.\n");      // invalid input
            break;

        default:
            printf("Unknown parking result.\n");      // fallback case
            break;
    }
}
