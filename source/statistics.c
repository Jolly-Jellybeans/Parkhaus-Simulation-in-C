#include "statistics.h"
FUNCTION statistics_init(p_statistics)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    p_statistics.currently_parked ← 0

    p_statistics.occupancy_ratio_sum ← 0.0
    p_statistics.occupancy_samples ← 0

    p_statistics.queued_vehicle_count_cumulative ← 0
    p_statistics.queued_vehicle_count_served ← 0

    p_statistics.total_park_duration ← 0
    p_statistics.departed_vehicle_count ← 0

    p_statistics.total_wait_duration ← 0

END FUNCTION

FUNCTION statistics_on_queued(p_statistics)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    p_statistics.queued_vehicle_count_cumulative ←
        p_statistics.queued_vehicle_count_cumulative + 1

END FUNCTION