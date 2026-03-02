#include "io.h"

/**
 * @brief Entfernt verbleibende Zeichen aus dem Eingabepuffer, um saubere Lesefolgen zu gewährleisten.
 */

/*
---------------------------------------------
  PSEUDOCODE - Input validation
---------------------------------------------

FUNCTION ValidateMenuInput(input)

       IF input is not numeric THEN
           DISPLAY error message
           RETURN invalid
       END IF

       IF input < 0 OR input > 4 THEN
           DISPLAY "Invalid menu option"
           RETURN invalid
       END IF

       RETURN valid

   END FUNCTION
*/


static void clear_input_buffer(void);

