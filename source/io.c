#include "io.h"

/**
 * @brief Entfernt verbleibende Zeichen aus dem Eingabepuffer, um saubere Lesefolgen zu gewährleisten.
 */

/*
---------------------------------------------
  PSEUDOCODE - Input validation
---------------------------------------------

FUNCTION read_menu_choice                    // Function checks if menu input is valid

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

   END FUNCTION
*/

/*
   FUNCTION vehicle_is_valid(vehicle)                  // Function checks if vehicle data is correct

       IF vehicle.id is invalid THEN                      // Check if vehicle ID is wrong or empty
           RETURN invalid                                 // Stop and mark vehicle as invalid
       END IF

       IF vehicle.remaining_duration <= 0 THEN            // Check if parking time is zero
           RETURN invalid                                 // Mark vehicle as invalid
       END IF

       RETURN true

   END FUNCTION

*/


static void clear_input_buffer(void);

