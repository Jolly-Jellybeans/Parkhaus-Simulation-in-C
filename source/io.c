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
-------------------------------------------------
  FUNCTION print_result_message(result)
-------------------------------------------------
    SWITCH result
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
-------------------------------------------------------
  END OF PSEUDOCODE
-------------------------------------------------------
*/

static void clear_input_buffer(void);

