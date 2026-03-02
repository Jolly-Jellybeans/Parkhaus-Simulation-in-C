#include "io.h"

/**
 * @brief Entfernt verbleibende Zeichen aus dem Eingabepuffer, um saubere Lesefolgen zu gewährleisten.
 */

/*
---------------------------------------------
  PSEUDOCODE - Input validation
---------------------------------------------

FUNCTION ValidateMenuInput(input)            // Function checks if menu input is valid

       IF input is not numeric THEN          // If user did not enter a number
           DISPLAY error message             // Show error message
           RETURN invalid                    // Stop and mark as invalid
       END IF

       IF input < 0 OR input > 4 THEN        // If number is outside allowed range
           DISPLAY "Invalid menu option"     // Tell user the opinion is wrong
           RETURN invalid                    // Mark input as invalid
       END IF

       RETURN valid

   END FUNCTION
*/

/*
   FUNCTION ValidateVehicleData(vehicle)                  // Function checks if vehicle data is correct

       IF vehicle.id is invalid THEN                      // Check if vehicle ID is wrong or empty
           RETURN invalid                                 // Stop and mark vehicle as invalid
       END IF

       IF vehicle.remaining_duration <= 0 THEN            // Check if parking time is zero
           RETURN invalid                                 // Mark vehicle as invalid
       END IF

       RETURN valid

   END FUNCTION

*/


static void clear_input_buffer(void);

