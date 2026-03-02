#include "simulation.h"

/*
FUNCTION simulation(garage, stats, config_sim_duration, config_arrival_prob, config_max_duration)

    FOR current_time VON 0 BIS config_sim_duration - 1 DO

        // 1. Abfahren & Nachrücken
        departed_count ← CALL parking_garage_remove_departing(garage, current_time)
        
        IF departed_count > 0 THEN
            CALL statistics_on_departure(ADRESSE VON stats, departed_count)
        END IF

        // 2. Ankunft neuer Fahrzeuge
        random_val ← CALL rand() % 100
        
        IF random_val < config_arrival_prob THEN
            
            // Neues Fahrzeug erstellen
            new_vehicle ← Leeres Vehicle
            new_vehicle.id ← generiere_neue_id()
            new_vehicle.entry_time ← current_time
            new_vehicle.remaining_duration ← (CALL rand() % config_max_duration) + 1 
            
            // Parkversuch
            result ← CALL parking_garage_park(garage, ADRESSE VON new_vehicle, current_time)
            
            // Ausgabe des Ergebnisses
            CALL print_result_message(result)
            
            // Statistik pflegen
            IF result ist PARKING_QUEUED THEN
                CALL statistics_on_queued(ADRESSE VON stats)
            END IF
            
        END IF

        // 3. Status-Update & Visualisierung
        CALL statistics_step_update(ADRESSE VON stats, garage.occupied_count, garage.slot_count)
        
        PRINT "Zeit: ", current_time
        CALL print_parking_garage_status(garage)
        
    END FOR

END FUNCTION

*/