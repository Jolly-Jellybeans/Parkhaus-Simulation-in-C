#include "statistics.h"
FUNCTION statistics_init(p_statistics)

    // Sicherheitsprüfung: Ohne gültige Zielstruktur gibt es nichts zu initialisieren.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Momentane Zustandswerte zu Simulationsbeginn.
    p_statistics.currently_parked ← 0
    p_statistics.currently_queued ← 0

    // Laufende Summen und Zeit-Samples für Mittelwerte zurücksetzen.
    p_statistics.parked_vehicle_count_sum ← 0
    p_statistics.queued_vehicle_count_sum ← 0
    p_statistics.time_samples ← 0

    // Auslastungsbezogene Summen/Zähler initialisieren.
    p_statistics.occupancy_ratio_sum ← 0.0
    p_statistics.occupancy_samples ← 0
    p_statistics.queued_vehicle_count_served ← 0

    // Summen/Zähler für Parkdauer initialisieren.
    p_statistics.total_park_duration ← 0
    p_statistics.departed_vehicle_count ← 0

    // Summe der Wartezeiten initialisieren.
    p_statistics.total_wait_duration ← 0

END FUNCTION

FUNCTION statistics_on_queued(p_statistics)

    // Sicherheitsprüfung: Ohne gültige Statistikstruktur keine Verarbeitung.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Aktuell kein direkter Zähler-Update nötig:
    // Die Kennzahl "wartende Fahrzeuge" wird pro Zeitschritt in
    // statistics_step_update(...) über die aktuelle Queue-Länge erfasst.

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

FUNCTION statistics_print_step(p_statistics, current_step, total_steps, total_slots)

    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    IF current_step < 0
    THEN
        current_step ← 0
    END IF

    IF total_steps < 0
    THEN
        total_steps ← 0
    END IF

    IF total_slots < 0
    THEN
        total_slots ← 0
    END IF

    current_occupancy_percent ← 0.0
    IF total_slots > 0
    THEN
        current_occupancy_percent ←
            (p_statistics.currently_parked / total_slots) * 100.0
    END IF

    current_avg_park_duration ← 0.0
    IF p_statistics.departed_vehicle_count > 0
    THEN
        current_avg_park_duration ←
            p_statistics.total_park_duration
            / p_statistics.departed_vehicle_count
    END IF

    current_avg_wait_duration ← 0.0
    IF p_statistics.queued_vehicle_count_served > 0
    THEN
        current_avg_wait_duration ←
            p_statistics.total_wait_duration
            / p_statistics.queued_vehicle_count_served
    END IF

    PRINT "------------------- Aktueller Status -------------------"
    PRINT "AKTUELLER STATUS: Schritt ", current_step, " / ", total_steps
    PRINT "1) Aktuell parkende Autos         : ", p_statistics.currently_parked, " Fahrzeuge"
    PRINT "2) Aktuelle Auslastung            : ", current_occupancy_percent, " Prozent"
    PRINT "3) Aktuell wartende Fahrzeuge     : ", p_statistics.currently_queued, " Fahrzeuge"
    PRINT "4) Aktuelle durchschn. Parkdauer  : ", current_avg_park_duration, " Zeitschritte"
    PRINT "5) Aktuelle durchschn. Wartedauer : ", current_avg_wait_duration, " Zeitschritte"
    PRINT "--------------------------------------------------------"

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

        PRINT "==================== Gesamt-Statistik ===================="
        PRINT "1) Durchschnittl. parkende Autos     : ", avg_parked_vehicles, " Fahrzeuge"
        PRINT "2) Durchschnittl. Auslastung         : ", avg_occupancy_percent, " Prozent"
        PRINT "3) Durchschnittl. wartende Fahrzeuge : ", avg_queued_vehicles, " Fahrzeuge"
        PRINT "4) Gesamte durchschn. Parkdauer      : ", avg_park_duration, " Zeitschritte"
        PRINT "5) Gesamte durchschn. Wartedauer     : ", avg_wait_duration, " Zeitschritte"
        PRINT "==========================================================="

END FUNCTION