/*
 * File: io.c
 * Description: Benutzereingaben, Konfigurationsaufbau und Ausgabe von Parkergebnissen.
 */
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
FUNCTION user_input(p_description) RETURNS integer
-------------------------------------------------   
    PRINT p_description                   // show prompt text to the user

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
  LOOP until config.slots > 0
        config.slots <- CALL user_input("Anzahl der Stellplaetze: ")
        IF config.slots <= 0 THEN
            PRINT "Bitte eine Zahl groesser 0 eingeben."
        END IF
    END LOOP
 
    LOOP until config.max_park_duration > 0
        config.max_park_duration <- CALL user_input("Maximale Parkdauer (pro Auto): ")
        IF config.max_park_duration <= 0 THEN
            PRINT "Bitte eine Zahl groesser 0 eingeben."
        END IF
    END LOOP
 
    LOOP until config.sim_duration > 0
        config.sim_duration <- CALL user_input("Gesamte Simulationsdauer: ")
        IF config.sim_duration <= 0 THEN
            PRINT "Bitte eine Zahl groesser 0 eingeben."
        END IF
    END LOOP
 
    LOOP until 0 <= config.arrival_prob <= 100
        config.arrival_prob <- CALL user_input("Ankunftswahrscheinlichkeit (0-100): ")
        IF config.arrival_prob < 0 OR config.arrival_prob > 100 THEN
            PRINT "Bitte einen Wert zwischen 0 und 100 eingeben."
        END IF
    END LOOP
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
    int ch = 0;          // variable to store each character

    while ((ch = getchar()) != '\n' && ch != EOF)      // read until end of line
    {
        ;
    }
}


int user_input(const char *p_description)
{
    int value = 0;             // variable for the user input

    while (1)              // repeat until valid number is entered
    {
        printf("%s", p_description);         // print input description

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
    SimulationConfig config = {0}; // config object for all inputs

    // Gueltige Slot-Anzahl erzwingen, da ein Parkhaus mindestens 1 Stellplatz braucht.
    do
    {
        config.slots = user_input("Anzahl der Stellplaetze: ");
        if (config.slots <= 0)
        {
            printf("Bitte eine Zahl groesser 0 eingeben.\n");
        }
    } while (config.slots <= 0);

    // >0 verhindert spaeter ungueltige Modulo-Operationen bei der Zufallsdauer.
    do
    {
        config.max_park_duration = user_input("Maximale Parkdauer (pro Auto): ");
        if (config.max_park_duration <= 0)
        {
            printf("Bitte eine Zahl groesser 0 eingeben.\n");
        }
    } while (config.max_park_duration <= 0);

    // Simulation muss mindestens einen Zeitschritt laufen.
    do
    {
        config.sim_duration = user_input("Gesamte Simulationsdauer: ");
        if (config.sim_duration <= 0)
        {
            printf("Bitte eine Zahl groesser 0 eingeben.\n");
        }
    } while (config.sim_duration <= 0);

    // Wahrscheinlichkeit immer im Bereich 0..100 halten.
    do
    {
        config.arrival_prob = user_input("Ankunftswahrscheinlichkeit (0-100): ");
        if (config.arrival_prob < 0 || config.arrival_prob > 100)
        {
            printf("Bitte einen Wert zwischen 0 und 100 eingeben.\n");
        }
    } while (config.arrival_prob < 0 || config.arrival_prob > 100);

    // Seed >= 0; 0 bedeutet zeitbasierter Seed (zufaellig).
    do
    {
        config.seed = user_input("Random-Seed (>=0, 0 = zeitbasiert): ");
        if (config.seed < 0)
        {
            printf("Bitte eine Zahl >= 0 eingeben.\n");
        }
    } while (config.seed < 0);

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
