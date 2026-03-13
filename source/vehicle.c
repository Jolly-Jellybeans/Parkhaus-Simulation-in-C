#include "vehicle.h"
#include <stdlib.h>

bool vehicle_is_valid(const Vehicle *p_vehicle)
{
    return p_vehicle != NULL
        && p_vehicle->id > 0
        && p_vehicle->remaining_duration > 0;
}
