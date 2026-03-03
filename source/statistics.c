#include "statistics.h"
FUNCTION statistics_init(p_statistics)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    p_statistics.currently_parked ← 0
    p_statistics.currently_queued ← 0

    p_statistics.parked_vehicle_count_sum ← 0
    p_statistics.queued_vehicle_count_sum ← 0
    p_statistics.time_samples ← 0

    p_statistics.occupancy_ratio_sum ← 0.0
    p_statistics.occupancy_samples ← 0
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

FUNCTION statistics_step_update(p_statistics, occupied_slots, total_slots, queued_vehicles)

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

    IF queued_vehicles < 0
    THEN
        queued_vehicles ← 0
    END IF

    p_statistics.currently_parked ← occupied_slots
    p_statistics.currently_queued ← queued_vehicles

    p_statistics.parked_vehicle_count_sum ←
        p_statistics.parked_vehicle_count_sum + occupied_slots

    p_statistics.queued_vehicle_count_sum ←
        p_statistics.queued_vehicle_count_sum + queued_vehicles

    p_statistics.time_samples ←
        p_statistics.time_samples + 1

    IF total_slots > 0
    THEN
        occupancy_ratio ← occupied_slots / total_slots

        p_statistics.occupancy_ratio_sum ←
            p_statistics.occupancy_ratio_sum + occupancy_ratio

        p_statistics.occupancy_samples ←
            p_statistics.occupancy_samples + 1
    END IF

END FUNCTION

FUNCTION statistics_print(p_statistics)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    avg_parked_vehicles ← 0.0
    avg_queued_vehicles ← 0.0
    avg_occupancy_percent ← 0.0

    IF p_statistics.time_samples > 0
    THEN
        avg_parked_vehicles ←
            p_statistics.parked_vehicle_count_sum
            / p_statistics.time_samples

        avg_queued_vehicles ←
            p_statistics.queued_vehicle_count_sum
            / p_statistics.time_samples

    END IF

    IF p_statistics.occupancy_samples > 0
    THEN
        avg_occupancy_percent ←
            (p_statistics.occupancy_ratio_sum
             / p_statistics.occupancy_samples) * 100.0
    END IF

    avg_park_duration ← 0.0
    IF p_statistics.departed_vehicle_count > 0
    THEN
        avg_park_duration ←
            p_statistics.total_park_duration
            / p_statistics.departed_vehicle_count
    END IF

    avg_wait_duration ← 0.0
    IF p_statistics.queued_vehicle_count_served > 0
    THEN
        avg_wait_duration ←
            p_statistics.total_wait_duration
            / p_statistics.queued_vehicle_count_served
    END IF

    PRINT "==================== Statistik ===================="
        PRINT "1) Ø parkende Autos             : ",
            avg_parked_vehicles
    PRINT "2) Durchschnittliche Auslastung : ",
          avg_occupancy_percent, "%"
        PRINT "3) Ø wartende Fahrzeuge         : ",
            avg_queued_vehicles
    PRINT "4) Durchschnittliche Parkdauer  : ",
          avg_park_duration
    PRINT "5) Durchschnittliche Wartedauer : ",
          avg_wait_duration
    PRINT "==================================================="

END FUNCTION