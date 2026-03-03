#include "simulation.h"

/*
FUNCTION simulation(p_garage, p_stats, config_sim_duration, config_arrival_prob, config_max_duration)

    FOR current_time VON 0 BIS config_sim_duration - 1 DO

        // 1. Abfahren & Nachrücken
        departed_count ← CALL parking_garage_remove_departing(garage, current_time)
        
        IF departed_count > 0 THEN
            
            CALL statistics_on_departure(ADRESSE VON stats, departed_count)
            
            // Nachrücken aus der Warteschlange
            WHILE garage.occupied_count < garage.slot_count UND NICHT CALL queue_is_empty(garage.p_queue) DO
                waiting_vehicle ← Empty Vehicle
                CALL queue_dequeue(garage.p_queue, ADRESSE VON waiting_vehicle)
                wait_duration ← current_time - waiting_vehicle.entry_time
                CALL statistics_on_parked_from_queue(ADRESSE VON stats, wait_duration)
                
                waiting_vehicle.entry_time ← current_time
                CALL parking_garage_park(garage, ADRESSE VON waiting_vehicle, current_time)
            END WHILE
        END IF

        // 2. Ankunft neuer Fahrzeuge
        random_val ← CALL rand() % 100
        
        IF random_val < config_arrival_prob THEN
            
            // Neues Fahrzeug erstellen
            new_vehicle ← Empty Vehicle
            new_vehicle.id ← generiere_neue_id()
            new_vehicle.entry_time ← current_time
            new_vehicle.remaining_duration ← (CALL rand() % config_max_duration) + 1 
            
            // Parkversuch
            result ← CALL parking_garage_park(garage, ADRESSE VON new_vehicle, current_time)
            
            // Ausgabe des Ergebnisses
            CALL print_result_message(result)
            
            // Statistik pflegen
            IF result ist PARKING_QUEUED THEN
                CALL statistics_on_queued(ADRESSE VON p_stats)
            END IF
            
        END IF

        // 3. Status-Update & Visualisierung
        CALL statistics_step_update(ADRESSE VON stats, garage.occupied_count, garage.slot_count)
        
        PRINT "Zeit: ", current_time
        CALL statistics_print(ADRESSE VON stats)
        
    END FOR

END FUNCTION

*/