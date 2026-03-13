#include <stdio.h>
#include "statistics.h"
/*
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

    // Sicherheitsprüfung: Ohne gültige Statistikstruktur keine Verarbeitung.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Negative Wartezeiten sind fachlich ungültig und werden auf 0 begrenzt.
    IF wait_duration < 0
    THEN
        wait_duration ← 0
    END IF

    // Wartezeit des aus der Queue bedienten Fahrzeugs aufsummieren.
    p_statistics.total_wait_duration ←
        p_statistics.total_wait_duration + wait_duration

    // Anzahl der bedienten Queue-Fahrzeuge erhöhen
    // (Basis für durchschnittliche Wartedauer).
    p_statistics.queued_vehicle_count_served ←
        p_statistics.queued_vehicle_count_served + 1

END FUNCTION

FUNCTION statistics_on_departure(p_statistics, park_duration)

    // Sicherheitsprüfung: Ohne gültige Statistikstruktur keine Verarbeitung.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Negative Parkzeiten sind fachlich ungültig und werden auf 0 begrenzt.
    IF park_duration < 0
    THEN
        park_duration ← 0
    END IF

    // Parkdauer des ausgefahrenen Fahrzeugs aufsummieren.
    p_statistics.total_park_duration ←
        p_statistics.total_park_duration + park_duration

    // Anzahl ausgefahrener Fahrzeuge erhöhen
    // (Basis für durchschnittliche Parkdauer).
    p_statistics.departed_vehicle_count ←
        p_statistics.departed_vehicle_count + 1

END FUNCTION

FUNCTION statistics_step_update(p_statistics, occupied_slots, total_slots, queued_vehicles)

    // Sicherheitsprüfung: Ohne gültige Statistikstruktur keine Aktualisierung.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Eingaben normieren, damit keine negativen oder unplausiblen Werte
    // in die Statistik eingehen.
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

    // Aktuelle Momentwerte für die Schrittausgabe speichern.
    p_statistics.currently_parked ← occupied_slots
    p_statistics.currently_queued ← queued_vehicles

    // Zeitliche Summen für spätere Durchschnittswerte aufbauen.
    p_statistics.parked_vehicle_count_sum ←
        p_statistics.parked_vehicle_count_sum + occupied_slots

    p_statistics.queued_vehicle_count_sum ←
        p_statistics.queued_vehicle_count_sum + queued_vehicles

    p_statistics.time_samples ←
        p_statistics.time_samples + 1

    // Auslastung nur berechnen, wenn eine gültige Gesamtkapazität vorhanden ist.
    IF total_slots > 0
    THEN
        occupancy_ratio ← occupied_slots / total_slots

        // Summen/Zähler für durchschnittliche prozentuale Auslastung führen.
        p_statistics.occupancy_ratio_sum ←
            p_statistics.occupancy_ratio_sum + occupancy_ratio

        p_statistics.occupancy_samples ←
            p_statistics.occupancy_samples + 1
    END IF

END FUNCTION

FUNCTION statistics_print_step(p_statistics, current_step, total_steps, total_slots)

    // Sicherheitsprüfung: Ohne gültige Statistikstruktur keine Ausgabe.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Schutz gegen ungültige negative Anzeigeparameter.
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

    // Aktuelle Auslastung für diesen Simulationsschritt berechnen.
    current_occupancy_percent ← 0.0
    IF total_slots > 0
    THEN
        current_occupancy_percent ←
            (p_statistics.currently_parked / total_slots) * 100.0
    END IF

    // Laufende Durchschnittswerte auf Basis bisher abgeschlossener Fahrzeuge.
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

    // Kompakte Live-Ausgabe für Monitoring pro Simulationsschritt.
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

    // Sicherheitsprüfung: Ohne gültige Statistikstruktur keine Ausgabe.
    IF p_statistics = NULL
    THEN
        RETURN
    END IF

    // Enddurchschnitte vorbereiten und mit 0 initialisieren,
    // damit die Ausgabe auch ohne Daten definiert bleibt.
    avg_parked_vehicles ← 0.0
    avg_queued_vehicles ← 0.0
    avg_occupancy_percent ← 0.0

    // Zeitliche Mittelwerte über alle erfassten Simulationsschritte.
    IF p_statistics.time_samples > 0
    THEN
        avg_parked_vehicles ←
            p_statistics.parked_vehicle_count_sum
            / p_statistics.time_samples

        avg_queued_vehicles ←
            p_statistics.queued_vehicle_count_sum
            / p_statistics.time_samples

    END IF

    // Durchschnittliche prozentuale Auslastung nur bei gültigen Samples.
    IF p_statistics.occupancy_samples > 0
    THEN
        avg_occupancy_percent ←
            (p_statistics.occupancy_ratio_sum
             / p_statistics.occupancy_samples) * 100.0
    END IF

    // Durchschnittliche Parkdauer über alle abgefahrenen Fahrzeuge.
    avg_park_duration ← 0.0
    IF p_statistics.departed_vehicle_count > 0
    THEN
        avg_park_duration ←
            p_statistics.total_park_duration
            / p_statistics.departed_vehicle_count
    END IF

    // Durchschnittliche Wartedauer über alle bedienten Queue-Fahrzeuge.
    avg_wait_duration ← 0.0
    IF p_statistics.queued_vehicle_count_served > 0
    THEN
        avg_wait_duration ←
            p_statistics.total_wait_duration
            / p_statistics.queued_vehicle_count_served
    END IF

    // Finale Gesamtauswertung am Ende der Simulation ausgeben.
        PRINT "==================== Gesamt-Statistik ===================="
        PRINT "1) Durchschnittl. parkende Autos     : ", avg_parked_vehicles, " Fahrzeuge"
        PRINT "2) Durchschnittl. Auslastung         : ", avg_occupancy_percent, " Prozent"
        PRINT "3) Durchschnittl. wartende Fahrzeuge : ", avg_queued_vehicles, " Fahrzeuge"
        PRINT "4) Gesamte durchschn. Parkdauer      : ", avg_park_duration, " Zeitschritte"
        PRINT "5) Gesamte durchschn. Wartedauer     : ", avg_wait_duration, " Zeitschritte"
        PRINT "==========================================================="

END FUNCTION
*/

void statistics_on_queued(Statistics *p_statistics){
    if (p_statistics == NULL)
    {
        return;
    }

    if (p_statistics->currently_queued < 0)
    {
        p_statistics->currently_queued = 0;
    }

    p_statistics->currently_queued += 1;
}
    

void statistics_init(Statistics *p_statistics){
    if (p_statistics == NULL)
    {
        return;
    }

    
    p_statistics->currently_parked = 0;
    p_statistics->currently_queued = 0;

    p_statistics->parked_vehicle_count_sum = 0;
    p_statistics->queued_vehicle_count_sum = 0;
    p_statistics->time_samples = 0;

    p_statistics->occupancy_ratio_sum = 0.0;
    p_statistics->occupancy_samples = 0;
    p_statistics->queued_vehicle_count_served = 0;

    p_statistics->total_park_duration = 0;
    p_statistics->departed_vehicle_count = 0;

    p_statistics->total_wait_duration = 0;
}
void statistics_on_parked_from_queue(Statistics *p_statistics, int wait_duration)
{
    if (p_statistics == NULL)
    {
        return;
    }

    if (wait_duration < 0)
    {
        wait_duration = 0;
    }

    p_statistics->total_wait_duration += wait_duration;
    p_statistics->queued_vehicle_count_served += 1;
}

void statistics_on_departure(Statistics *p_statistics, int park_duration)
{
    if (p_statistics == NULL)
    {
        return;
    }

    if (park_duration < 0)
    {
        park_duration = 0;
    }

    p_statistics->total_park_duration += park_duration;
    p_statistics->departed_vehicle_count += 1;
}

void statistics_step_update(Statistics *p_statistics,int occupied_slots,int total_slots,int queued_vehicles){
    if (p_statistics == NULL)
    {
        return;
    }

    if (occupied_slots < 0)
    {
        occupied_slots = 0;
    }

    if (total_slots > 0 && occupied_slots > total_slots)
    {
        occupied_slots = total_slots;
    }

    if (queued_vehicles < 0)
    {
        queued_vehicles = 0;
    }

    p_statistics->currently_parked = occupied_slots;
    p_statistics->currently_queued = queued_vehicles;

    p_statistics->parked_vehicle_count_sum += occupied_slots;
    p_statistics->queued_vehicle_count_sum += queued_vehicles;
    p_statistics->time_samples += 1;

    if (total_slots > 0)
    {
        double occupancy_ratio = (double)occupied_slots / total_slots;
        p_statistics->occupancy_ratio_sum += occupancy_ratio;
        p_statistics->occupancy_samples += 1;
    }
}
void statistics_print_step(const Statistics *p_statistics, int current_step, int total_steps, int total_slots, const char *p_filename)
{
    if (p_statistics == NULL)
    {
        return;
    }

    if (current_step < 0) { current_step = 0; }
    if (total_steps < 0)  { total_steps  = 0; }
    if (total_slots < 0)  { total_slots  = 0; }

    double current_occupancy_percent = 0.0;
    if (total_slots > 0)
    {
        current_occupancy_percent = ((double)p_statistics->currently_parked / total_slots) * 100.0;
    }

    double current_avg_park_duration = 0.0;
    if (p_statistics->departed_vehicle_count > 0)
    {
        current_avg_park_duration = (double)p_statistics->total_park_duration / p_statistics->departed_vehicle_count;
    }

    double current_avg_wait_duration = 0.0;
    if (p_statistics->queued_vehicle_count_served > 0)
    {
        current_avg_wait_duration = (double)p_statistics->total_wait_duration / p_statistics->queued_vehicle_count_served;
    }

    char header[60];
    snprintf(header, sizeof(header), "| AKTUELLER STATUS: Schritt %d / %d", current_step, total_steps);

    printf("+--------------------------------------------+------------+-----------------+\n");
    printf("%-45s| Wert       | Einheit         |\n", header);
    printf("+--------------------------------------------+------------+-----------------+\n");
    printf("| %-42s|%11d | Fahrzeuge       |\n", "1. Aktuell parkende Autos", p_statistics->currently_parked);
    printf("| %-42s|%11.1f | Prozent         |\n", "2. Aktuelle Auslastung", current_occupancy_percent);
    printf("| %-42s|%11d | Fahrzeuge       |\n", "3. Aktuell wartende Fahrzeuge", p_statistics->currently_queued);
    printf("| %-42s|%11.1f | Zeitschritte    |\n", "4. Aktuelle durchschn. Parkdauer", current_avg_park_duration);
    printf("| %-42s|%11.1f | Zeitschritte    |\n", "5. Aktuelle durchschn. Wartedauer", current_avg_wait_duration);
    printf("+--------------------------------------------+------------+-----------------+\n");

    if (p_filename != NULL)
    {
        FILE *p_file = fopen(p_filename, current_step <= 1 ? "w" : "a");
        if (p_file != NULL)
        {
            fprintf(p_file, "+--------------------------------------------+------------+-----------------+\n");
            fprintf(p_file, "%-45s| Wert       | Einheit         |\n", header);
            fprintf(p_file, "+--------------------------------------------+------------+-----------------+\n");
            fprintf(p_file, "| %-42s|%11d | Fahrzeuge       |\n", "1. Aktuell parkende Autos", p_statistics->currently_parked);
            fprintf(p_file, "| %-42s|%11.1f | Prozent         |\n", "2. Aktuelle Auslastung", current_occupancy_percent);
            fprintf(p_file, "| %-42s|%11d | Fahrzeuge       |\n", "3. Aktuell wartende Fahrzeuge", p_statistics->currently_queued);
            fprintf(p_file, "| %-42s|%11.1f | Zeitschritte    |\n", "4. Aktuelle durchschn. Parkdauer", current_avg_park_duration);
            fprintf(p_file, "| %-42s|%11.1f | Zeitschritte    |\n", "5. Aktuelle durchschn. Wartedauer", current_avg_wait_duration);
            fprintf(p_file, "+--------------------------------------------+------------+-----------------+\n");
            fclose(p_file);
        }
    }
}

void statistics_print(const Statistics *p_statistics, const char *p_filename){
    if (p_statistics == NULL)
    {
        return;
    }

    double avg_parked_vehicles = 0.0;
    double avg_queued_vehicles = 0.0;
    double avg_occupancy_percent = 0.0;

    if (p_statistics->time_samples > 0)
    {
        avg_parked_vehicles = (double)p_statistics->parked_vehicle_count_sum / p_statistics->time_samples;
        avg_queued_vehicles = (double)p_statistics->queued_vehicle_count_sum / p_statistics->time_samples;
    }

    if (p_statistics->occupancy_samples > 0)
    {
        avg_occupancy_percent = (p_statistics->occupancy_ratio_sum / p_statistics->occupancy_samples) * 100.0;
    }

    double avg_park_duration = 0.0;
    if (p_statistics->departed_vehicle_count > 0)
    {
        avg_park_duration = (double)p_statistics->total_park_duration / p_statistics->departed_vehicle_count;
    }

    double avg_wait_duration = 0.0;
    if (p_statistics->queued_vehicle_count_served > 0)
    {
        avg_wait_duration = (double)p_statistics->total_wait_duration / p_statistics->queued_vehicle_count_served;
    }

    printf("+--------------------------------------------+------------+-----------------+\n");
    printf("| %-42s| Wert       | Einheit         |\n", "GESAMT-STATISTIK (Durchschnittswerte)");
    printf("+--------------------------------------------+------------+-----------------+\n");
    printf("| %-42s|%11.1f | Fahrzeuge       |\n", "1. Durchschnittl. parkende Autos", avg_parked_vehicles);
    printf("| %-42s|%11.1f | Prozent         |\n", "2. Durchschnittl. Auslastung", avg_occupancy_percent);
    printf("| %-42s|%11.1f | Fahrzeuge       |\n", "3. Durchschnittl. wartende Fahrzeuge", avg_queued_vehicles);
    printf("| %-42s|%11.1f | Zeitschritte    |\n", "4. Gesamte durchschn. Parkdauer", avg_park_duration);
    printf("| %-42s|%11.1f | Zeitschritte    |\n", "5. Gesamte durchschn. Wartedauer", avg_wait_duration);
    printf("+--------------------------------------------+------------+-----------------+\n");

    if (p_filename != NULL)
    {
        FILE *p_file = fopen(p_filename, "w");
        if (p_file != NULL)
        {
            fprintf(p_file, "+--------------------------------------------+------------+-----------------+\n");
            fprintf(p_file, "| %-42s| Wert       | Einheit         |\n", "GESAMT-STATISTIK (Durchschnittswerte)");
            fprintf(p_file, "+--------------------------------------------+------------+-----------------+\n");
            fprintf(p_file, "| %-42s|%11.1f | Fahrzeuge       |\n", "1. Durchschnittl. parkende Autos", avg_parked_vehicles);
            fprintf(p_file, "| %-42s|%11.1f | Prozent         |\n", "2. Durchschnittl. Auslastung", avg_occupancy_percent);
            fprintf(p_file, "| %-42s|%11.1f | Fahrzeuge       |\n", "3. Durchschnittl. wartende Fahrzeuge", avg_queued_vehicles);
            fprintf(p_file, "| %-42s|%11.1f | Zeitschritte    |\n", "4. Gesamte durchschn. Parkdauer", avg_park_duration);
            fprintf(p_file, "| %-42s|%11.1f | Zeitschritte    |\n", "5. Gesamte durchschn. Wartedauer", avg_wait_duration);
            fprintf(p_file, "+--------------------------------------------+------------+-----------------+\n");
            fclose(p_file);
        }
    }
}