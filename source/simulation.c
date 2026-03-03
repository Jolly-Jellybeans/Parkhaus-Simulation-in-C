#include "simulation.h"

/*
FUNCTION simulation(p_garage, p_stats, config_sim_duration, config_arrival_prob, config_max_duration)

    FOR current_time VON 0 BIS config_sim_duration - 1 DO

        // 1. Abfahrten: Parkdauer je Fahrzeug erfassen, bevor der Slot geräumt wird.
        FOR i VON 0 BIS p_garage.slot_count - 1
            IF p_garage.p_slots[i].is_occupied = true
               AND p_garage.p_slots[i].departure_time <= current_time
            THEN
                park_duration ← current_time - p_garage.p_slots[i].vehicle.entry_time
                CALL statistics_on_departure(ADRESSE VON p_stats, park_duration)
            END IF
        END FOR

        // Erkannte Fahrzeuge aus ihren Stellplätzen entfernen.
        CALL parking_garage_remove_departing(p_garage, current_time)

        // 2. Nachrücken aus der Warteschlange, solange freie Plätze vorhanden sind.
        WHILE p_garage.occupied_count < p_garage.slot_count
              AND NOT CALL queue_is_empty(p_garage.p_queue) DO

            waiting_vehicle ← Empty Vehicle
            CALL queue_dequeue(p_garage.p_queue, ADRESSE VON waiting_vehicle)

            wait_duration ← current_time - waiting_vehicle.entry_time
            CALL statistics_on_parked_from_queue(ADRESSE VON p_stats, wait_duration)

            waiting_vehicle.entry_time ← current_time
            CALL parking_garage_park(p_garage, ADRESSE VON waiting_vehicle, current_time)

        END WHILE

        // 3. Ankunft neuer Fahrzeuge (zufallsbasiert).
        random_val ← CALL rand() % 100

        IF random_val < config_arrival_prob THEN

            new_vehicle ← Empty Vehicle
            new_vehicle.id ← current_time + 1
            new_vehicle.entry_time ← current_time
            new_vehicle.remaining_duration ← (CALL rand() % config_max_duration) + 1

            result ← CALL parking_garage_park(p_garage, ADRESSE VON new_vehicle, current_time)

            CALL print_result_message(result)

            IF result ist PARKING_QUEUED THEN
                CALL statistics_on_queued(ADRESSE VON p_stats)
            END IF

        END IF

        // 4. Zeitabhängige Statistiken aktualisieren und Live-Status ausgeben.
        queued_count ← CALL queue_size(p_garage.p_queue)

        CALL statistics_step_update(ADRESSE VON p_stats,
                                    p_garage.occupied_count,
                                    p_garage.slot_count,
                                    queued_count)

        CALL statistics_print_step(ADRESSE VON p_stats,
                                   current_time + 1,
                                   config_sim_duration,
                                   p_garage.slot_count)

    END FOR

END FUNCTION

*/