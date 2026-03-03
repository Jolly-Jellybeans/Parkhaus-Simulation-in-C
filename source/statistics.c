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

FUNCTION statistics_on_parked_from_queue(p_statistics, wait_duration)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    IF wait_duration < 0
    THEN
        wait_duration ← 0
    END IF

    p_statistics.total_wait_duration ←
        p_statistics.total_wait_duration + wait_duration

    p_statistics.queued_vehicle_count_served ←
        p_statistics.queued_vehicle_count_served + 1

END FUNCTION

FUNCTION statistics_on_departure(p_statistics, park_duration)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    IF park_duration < 0
    THEN
        park_duration ← 0
    END IF

    p_statistics.total_park_duration ←
        p_statistics.total_park_duration + park_duration

    p_statistics.departed_vehicle_count ←
        p_statistics.departed_vehicle_count + 1

END FUNCTION

FUNCTION statistics_step_update(p_statistics, occupied_slots, total_slots)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    IF occupied_slots < 0
    THEN
        occupied_slots ← 0
    END IF

    IF total_slots > 0 AND occupied_slots > total_slots
    THEN
        occupied_slots ← total_slots
    END IF

    p_statistics.currently_parked ← occupied_slots

    IF total_slots > 0
    THEN
        occupancy_ratio ← occupied_slots / total_slots

        p_statistics.occupancy_ratio_sum ←
            p_statistics.occupancy_ratio_sum + occupancy_ratio

        p_statistics.occupancy_samples ←
            p_statistics.occupancy_samples + 1
    END IF

END FUNCTION