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

---------------------------------------------
FUNCTION print_menu
---------------------------------------------
    PRINT "==== Parking Garage Simulation ==="
    PRINT "0 - Exit"
    PRINT "1 - Start Simulation"
    PRINT "2 - Show parking garage status"
    PRINT "3 - Show statistics"
END FUNCTION

---------------------------------------------
FUNCTION read_menu_choice                    // Function checks if menu input is valid
---------------------------------------------

  LOOP forever                               // keep asking until valid input
  
      READ input from user 
      
       IF input is not numeric THEN          // If user did not enter a number
           PRINT "Please enter a number."    // show error message
           CLEAR input buffer                // remove wrong chars
           CONTINUE                          // ask again
       END IF

       IF input < 0 OR input > 4 THEN        // If number is outside allowed range
           PRINT "Invalid menu option"       // Tell user the opinion is wrong
           CONTINUE                          // Mark input as invalid
       END IF

       RETURN input

    END LOOP
  END FUNCTION
*/
/*
--------------------------------------------------
  FUNCTION print_parking_garage_status(p_garage)
--------------------------------------------------
  IF p_garage is NULL THEN
      PRINT "Error: No garage data."
      RETURN
  END IF

  PRINT "==== Parking Garage Status ==="
  PRINT "Total slots: " p_garage.total_slots
  PRINT "Occupied slots: " p_garage.occupied_slots
  PRINT "Free slots: " (total_slots - occupied_slots)

  PRINT "Vehicles currently parked:"
  FOR each slot in p_garage.slots DO
      IF slot contains a vehicle THEN
          PRINT "Slot X: Vehicle ID = ..., Remaining = ..."
      ELSE
          PRINT "Slot X: empty"
      END IF
  END FOR

  PRINT "Waiting queue:"
  IF queue is empty  THEN
      PRINT "No vehicles waiting."
  ELSE
      PRINT "Vehicles waiting: ..."
  END IF
END FUNCTION
*/  


/*
FUNCTION read_simulation_parameters
    // slot_count
    DO
        READ slot_count
        IF slot_count is not numeric OR slot_count <= 0 THEN
            PRINT "Slot count must be a positive number."
        END IF
    WHILE slot_count is invalid                      //repeat until valid

    // max_parking_duration
    DO
        READ max_duration
        IF max_duration is not numeric OR max_duration <= 0 THEN
            PRINT "Max parking duration must be positive."
        END IF
    WHILE max_duration is invalid

    // simulation_duration (steps)
    DO
        READ sim_steps
        IF sim_steps is not numeric OR sim_steps <= 0 THEN
            PRINT "Simulation duration must be positive."
        END IF
    WHILE sim_steps is invalid

    // arrival_probability (0..100)
    DO
        READ arrival_probability
        IF arrival_probability is not numeric OR arrival_probability < 0 OR arrival_probability > 100 THEN
            PRINT "Arrival probability must be between 0 and 100."
        END IF
    WHILE arrival_probability is invalid

    // random_seed
    DO
        READ seed
        IF seed is not numeric OR seed < 0 THEN
            PRINT "Seed must be a non-negative number."
        END IF
    WHILE seed is invalid

    RETURN all parameters                            // return validated values
END FUNCTION
*/



static void clear_input_buffer(void);

