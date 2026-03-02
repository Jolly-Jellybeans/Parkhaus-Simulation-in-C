#include "parking_garage.h"
#include "statistics.h"
#include "queue.h"
#include "vehicle.h"
#include "io.h"



// -----------------------------------------------
// PSEUDOCODE
//------------------------------------------------

BEGIN Menu Logic

    CREATE parking garage with fixed number of slots
    INITIALIZE statistics structure

    SET running = true

    WHILE running DO

        DISPLAY main menu
        PROMPT user for input
        READ user choice from input
        VALIDATE user input

        IF choice == 1 THEN
            READ vehicle data from user
            VALIDATE vehicle data
            TRY to park vehicle in garage
            DISPLAY result message
            UPDATE statistics if necessary

        ELSE IF choice == 2 THEN
            PROCESS departures based on current simulation time
            UPDATE statistics

        ELSE IF choice == 3 THEN
            DISPLAY current parking garage status

        ELSE IF choice == 4 THEN
            DISPLAY collected statistics

        ELSE IF choice == 0 THEN
            SET running = false

        ELSE
            DISPLAY "Invalid input"

        END IF

    END WHILE

    DESTROY parking garage
    TERMINATE program

END PROGRAM
