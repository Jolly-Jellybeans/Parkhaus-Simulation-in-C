#include "vehicle.h"

/*
-------------------------------------
  PSEUDOCODE -- Vehicle Validation
-------------------------------------

FUNCTION vehicle_is_valid(vehicle)
  IF vehicle is Null THEN
        RETURN false                                  //no vehicle given
  END IF

  IF vehicle.id <= 0 THEN
        RETURN false                                  // id must be positive
  END IF

  IF vehicle.remaining_duration <= 0 THEN
        RETURN false                                  // parking duration must be positive
  END IF

  IF vehicle.entry_time < THEN
        RETURN false                                  // entry time cannot be negative
  END IF

  RETURN true                                         // vehicle data is valid

END FUNKTION
*/
