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

    // Negative Werte absichern und den aktuellen Queue-Zähler erhöhen.
    IF p_statistics.currently_queued < 0
    THEN
        p_statistics.currently_queued ← 0
    END IF

    p_statistics.currently_queued ←
        p_statistics.currently_queued + 1

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

FUNCTION statistics_print_step(p_statistics, current_step, total_steps, total_slots, p_filename)

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

    // Ausgabeziel: immer Terminal; optional zusätzlich Datei.
    IF p_filename != NULL
    THEN
        outputs ← [stdout, Datei(p_filename, append_or_write)]
    ELSE
        outputs ← [stdout]
    END IF

    FOR JEDES output IN outputs
        PRINT Headerblock "AKTUELLER STATUS: Schritt x / y"
        PRINT Tabelle mit Kennzahl/Wert/Einheit

        PRINT Zeile 1 (aktuell parkende Autos)
        PRINT ASCII-Balkenzeile "Belegungsbalken" (relativ zu total_slots)

        PRINT Zeile 2 (aktuelle Auslastung)
        PRINT ASCII-Balkenzeile "Prozentbalken" (relativ zu 100)

        PRINT Zeile 3 (aktuell wartende Fahrzeuge)
        PRINT ASCII-Balkenzeile "Warteschlangenbalken" (relativ zu total_slots)

        PRINT Zeile 4 (aktuelle durchschn. Parkdauer)
        PRINT ASCII-Balkenzeile "Dauerbalken" (relativ zu total_steps)

        PRINT Zeile 5 (aktuelle durchschn. Wartedauer)
        PRINT ASCII-Balkenzeile "Wartezeitbalken" (relativ zu total_steps)
    END FOR

END FUNCTION

FUNCTION statistics_print(p_statistics, p_filename)

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

    // Ausgabeziel: immer Terminal; optional zusätzlich Datei.
    IF p_filename != NULL
    THEN
        outputs ← [stdout, Datei(p_filename, write)]
    ELSE
        outputs ← [stdout]
    END IF

    FOR JEDES output IN outputs
        PRINT Headerblock "GESAMT-STATISTIK (Durchschnittswerte)"
        PRINT Tabelle mit Kennzahl/Wert/Einheit

        PRINT Zeile 1 (Durchschnittl. parkende Autos)
        PRINT ASCII-Balkenzeile "Mittelwert-Balken" (relativ zu time_samples)

        PRINT Zeile 2 (Durchschnittl. Auslastung)
        PRINT ASCII-Balkenzeile "Prozentbalken" (relativ zu 100)

        PRINT Zeile 3 (Durchschnittl. wartende Fahrzeuge)
        PRINT ASCII-Balkenzeile "Warteschlangenbalken" (relativ zu time_samples)

        PRINT Zeile 4 (Gesamte durchschn. Parkdauer)
        PRINT ASCII-Balkenzeile "Dauerbalken" (relativ zu time_samples)

        PRINT Zeile 5 (Gesamte durchschn. Wartedauer)
        PRINT ASCII-Balkenzeile "Wartezeitbalken" (relativ zu time_samples)
    END FOR

END FUNCTION
*/

void statistics_on_queued(Statistics *p_statistics){
    // Ohne gueltige Zielstruktur keine Aktualisierung moeglich.
    if (p_statistics == NULL)
    {
        return;
    }

    // Defensiv: negative Zwischenwerte verhindern.
    if (p_statistics->currently_queued < 0)
    {
        p_statistics->currently_queued = 0;
    }

    // Ein weiteres Fahrzeug ist in der Warteschlange angekommen.
    // +1 bedeutet: genau ein weiteres Fahrzeug wartet jetzt.
    p_statistics->currently_queued += 1;
}
    

void statistics_init(Statistics *p_statistics){
    // Sicherheitspruefung gegen NULL-Zeiger.
    if (p_statistics == NULL)
    {
        return;
    }

    // Momentane Zustandswerte zur Laufzeit.
    p_statistics->currently_parked = 0;   // aktuell parkende Fahrzeuge
    p_statistics->currently_queued = 0;   // aktuell wartende Fahrzeuge

    // Summen fuer zeitliche Mittelwerte.
    p_statistics->parked_vehicle_count_sum = 0; // Summe "parkend" ueber alle Schritte
    p_statistics->queued_vehicle_count_sum = 0; // Summe "wartend" ueber alle Schritte
    p_statistics->time_samples = 0;             // Anzahl erfasster Zeitschritte

    // Summen/Zaehler fuer Auslastung und Queue-Auswertung.
    p_statistics->occupancy_ratio_sum = 0.0;    // Summe von occupied/total
    p_statistics->occupancy_samples = 0;        // Zaehler fuer gueltige Auslastungssamples
    p_statistics->queued_vehicle_count_served = 0; // Anzahl aus Queue bedient

    // Summen/Zaehler fuer Park- und Wartezeiten.
    p_statistics->total_park_duration = 0;   // Summe aller Parkdauern
    p_statistics->departed_vehicle_count = 0; // Anzahl abgefahrener Fahrzeuge

    p_statistics->total_wait_duration = 0;   // Summe aller Wartezeiten
}
void statistics_on_parked_from_queue(Statistics *p_statistics, int wait_duration)
{
    // Ohne Struktur kein Update.
    if (p_statistics == NULL)
    {
        return;
    }

    // Fachlich ungueltige negative Wartezeiten auf 0 begrenzen.
    if (wait_duration < 0)
    {
        wait_duration = 0;
    }

    // Wartezeit aufsummieren und bediente Queue-Fahrzeuge zaehlen.
    p_statistics->total_wait_duration += wait_duration;   // neue Wartezeit aufsummieren
    p_statistics->queued_vehicle_count_served += 1;       // ein Queue-Fahrzeug wurde bedient
}

void statistics_on_departure(Statistics *p_statistics, int park_duration)
{
    // Ohne Struktur kein Update.
    if (p_statistics == NULL)
    {
        return;
    }

    // Fachlich ungueltige negative Parkdauer auf 0 begrenzen.
    if (park_duration < 0)
    {
        park_duration = 0;
    }

    // Parkdauer aufsummieren und Abfahrten zaehlen.
    p_statistics->total_park_duration += park_duration; // Parkdauer dieses Fahrzeugs addieren
    p_statistics->departed_vehicle_count += 1;         // eine weitere Abfahrt registrieren
}

void statistics_step_update(Statistics *p_statistics,int occupied_slots,int total_slots,int queued_vehicles){
    // Ohne gueltige Struktur keine Schrittauswertung.
    if (p_statistics == NULL)
    {
        return;
    }

    // Eingaben normalisieren, damit keine unplausiblen Werte eingehen.
    if (occupied_slots < 0)
    {
        occupied_slots = 0;
    }

    if (total_slots > 0 && occupied_slots > total_slots)
    {
        // Mehr belegte Plaetze als vorhanden sind unmoeglich -> deckeln.
        occupied_slots = total_slots;
    }

    if (queued_vehicles < 0)
    {
        queued_vehicles = 0;
    }

    // Aktuelle Momentaufnahme speichern.
    p_statistics->currently_parked = occupied_slots; // Snapshot: belegte Plaetze jetzt
    p_statistics->currently_queued = queued_vehicles; // Snapshot: Queue-Laenge jetzt

    // Laufende Summen fuer spaetere Durchschnittswerte fortschreiben.
    p_statistics->parked_vehicle_count_sum += occupied_slots; // fuer spaeteren Mittelwert
    p_statistics->queued_vehicle_count_sum += queued_vehicles; // fuer spaeteren Mittelwert
    p_statistics->time_samples += 1; // ein neuer Zeitschritt wurde erfasst

    // Auslastungsratio nur mit gueltiger Slot-Anzahl erfassen.
    if (total_slots > 0)
    {
        double occupancy_ratio = (double)occupied_slots / total_slots; // Wert zwischen 0 und 1
        p_statistics->occupancy_ratio_sum += occupancy_ratio; // fuer mittlere Auslastung
        p_statistics->occupancy_samples += 1; // gueltiges Sample gezaehlt
    }
}

void statistics_print_step(const Statistics *p_statistics, int current_step, int total_steps, int total_slots, const char *p_filename)
{
    // Ohne Statistikdaten keine Ausgabe.
    if (p_statistics == NULL)
    {
        return;
    }

    // Negative Anzeigeparameter auf 0 begrenzen.
    if (current_step < 0) { current_step = 0; } // negative Schrittanzeige verhindern
    if (total_steps < 0)  { total_steps  = 0; } // negative Simulationslaenge verhindern
    if (total_slots < 0)  { total_slots  = 0; } // negative Slot-Anzahl verhindern

    // Kennzahl 2: aktuelle prozentuale Auslastung.
    double current_occupancy_percent = 0.0;
    if (total_slots > 0)
    {
        current_occupancy_percent = ((double)p_statistics->currently_parked / total_slots) * 100.0;
    }

    // Kennzahl 4: laufender Durchschnitt der Parkdauer.
    double current_avg_park_duration = 0.0;
    if (p_statistics->departed_vehicle_count > 0)
    {
        current_avg_park_duration = (double)p_statistics->total_park_duration / p_statistics->departed_vehicle_count;
    }

    // Kennzahl 5: laufender Durchschnitt der Wartedauer.
    double current_avg_wait_duration = 0.0;
    if (p_statistics->queued_vehicle_count_served > 0)
    {
        current_avg_wait_duration = (double)p_statistics->total_wait_duration / p_statistics->queued_vehicle_count_served;
    }

    // Immer Terminal; optional zusaetzlich Schrittdatei.
    int target_count = (p_filename != NULL) ? 2 : 1; // 1=Terminal, 2=Terminal+Datei
    for (int t = 0; t < target_count; t++)
    {
        FILE *p_out;
        if (t == 0)
        {
            p_out = stdout; // erster Durchlauf immer Konsole
        }
        else
        {
            // Schritt 1 startet mit neuer Datei, danach anhaengen.
            p_out = fopen(p_filename, current_step <= 1 ? "w" : "a");
            if (p_out == NULL) { continue; }
        }

        char header[64]; // enthaelt den Schritttext fuer Kopfzeile
        snprintf(header, sizeof(header), "| AKTUELLER STATUS: Schritt %d / %d", current_step, total_steps);

        fprintf(p_out, "+---------------------------------------------------------------+\n");
        fprintf(p_out, "%-64s|\n", header);
        fprintf(p_out, "+---------------------------------------------------------------+\n");
        fprintf(p_out, "\n");
        fprintf(p_out, "+--------------------------------------------+------------+-----------------+\n");
        fprintf(p_out, "| %-42s| Wert       | Einheit         |\n", "Kennzahl");
        fprintf(p_out, "+--------------------------------------------+------------+-----------------+\n");

        // 1. Aktuell parkende Autos + Balken relativ zu total_slots.
        fprintf(p_out, "| %-42s|%11d | Fahrzeuge       |\n", "1. Aktuell parkende Autos", p_statistics->currently_parked);
        {
            int bar_filled = 0;
            if (total_slots > 0)
                bar_filled = (int)((double)p_statistics->currently_parked / total_slots * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // nie mehr als Balkenbreite
            fprintf(p_out, "|    %-38s | ", "Belegungsbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, " |\n");
        }
        fprintf(p_out, "|\n");

        // 2. Aktuelle Auslastung + Balken relativ zu 100 Prozent.
        fprintf(p_out, "| %-42s|%11.1f | Prozent         |\n", "2. Aktuelle Auslastung", current_occupancy_percent);
        {
            int bar_filled = (int)(current_occupancy_percent / 100.0 * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // oberes Limit fuer Balkenlaenge
            fprintf(p_out, "|    %-38s | ", "Prozentbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, " |\n");
        }
        fprintf(p_out, "|\n");

        // 3. Aktuell wartende Fahrzeuge + Balken relativ zu total_slots.
        fprintf(p_out, "| %-42s|%11d | Fahrzeuge       |\n", "3. Aktuell wartende Fahrzeuge", p_statistics->currently_queued);
        {
            int bar_filled = 0;
            if (total_slots > 0)
                bar_filled = (int)((double)p_statistics->currently_queued / total_slots * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // deckeln auf 20 Zeichen
            fprintf(p_out, "|    %-38s | ", "Warteschlangenbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, " |\n");
        }
        fprintf(p_out, "|\n");

        // 4. Aktuelle durchschn. Parkdauer + Balken relativ zu total_steps.
        fprintf(p_out, "| %-42s|%11.1f | Zeitschritte    |\n", "4. Aktuelle durchschn. Parkdauer", current_avg_park_duration);
        {
            int bar_filled = 0;
            if (total_steps > 0)
                bar_filled = (int)(current_avg_park_duration / total_steps * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // maximale Balkenbreite
            fprintf(p_out, "|    %-38s | ", "Dauerbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, " |\n");
        }
        fprintf(p_out, "|\n");

        // 5. Aktuelle durchschn. Wartedauer + Balken relativ zu total_steps.
        fprintf(p_out, "| %-42s|%11.1f | Zeitschritte    |\n", "5. Aktuelle durchschn. Wartedauer", current_avg_wait_duration);
        {
            int bar_filled = 0;
            if (total_steps > 0)
                bar_filled = (int)(current_avg_wait_duration / total_steps * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // maximale Balkenbreite
            fprintf(p_out, "|    %-38s | ", "Wartezeitbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, " |\n");
        }

        fprintf(p_out, "+--------------------------------------------+------------+-----------------+\n");

        if (t != 0) { fclose(p_out); } // nur Datei-Handle schliessen
    }
}



void statistics_print(const Statistics *p_statistics, const char *p_filename)
{
    // Ohne Statistikdaten keine Ausgabe.
    if (p_statistics == NULL)
    {
        return;
    }

    // Endmittelwerte, standardmaessig 0 fuer den Fall ohne Samples.
    double avg_parked_vehicles = 0.0;   // Kennzahl 1
    double avg_queued_vehicles = 0.0;   // Kennzahl 3
    double avg_occupancy_percent = 0.0; // Kennzahl 2

    if (p_statistics->time_samples > 0)
    {
        // Zeitliche Mittelwerte ueber alle Zeitschritte.
        avg_parked_vehicles = (double)p_statistics->parked_vehicle_count_sum / p_statistics->time_samples;
        avg_queued_vehicles = (double)p_statistics->queued_vehicle_count_sum / p_statistics->time_samples;
    }

    if (p_statistics->occupancy_samples > 0)
    {
        // Durchschnittliche prozentuale Auslastung.
        avg_occupancy_percent = (p_statistics->occupancy_ratio_sum / p_statistics->occupancy_samples) * 100.0;
    }

    double avg_park_duration = 0.0; // Kennzahl 4
    if (p_statistics->departed_vehicle_count > 0)
    {
        // Durchschnittliche Parkdauer ueber alle abgefahrenen Fahrzeuge.
        avg_park_duration = (double)p_statistics->total_park_duration / p_statistics->departed_vehicle_count;
    }

    double avg_wait_duration = 0.0; // Kennzahl 5
    if (p_statistics->queued_vehicle_count_served > 0)
    {
        // Durchschnittliche Wartedauer ueber alle aus der Queue bedienten Fahrzeuge.
        avg_wait_duration = (double)p_statistics->total_wait_duration / p_statistics->queued_vehicle_count_served;
    }

    // Immer Terminal; optional zusaetzlich Gesamtauswertung in Datei.
    int target_count = (p_filename != NULL) ? 2 : 1; // 1=Terminal, 2=Terminal+Datei
    for (int t = 0; t < target_count; t++)
    {
        FILE *p_out;
        if (t == 0)
        {
            p_out = stdout; // erster Ausgabekanal: Konsole
        }
        else
        {
            // Endauswertung immer neu schreiben (nicht anhaengen).
            p_out = fopen(p_filename, "w");
            if (p_out == NULL) { continue; }
        }

        fprintf(p_out, "+---------------------------------------------------------------+\n");
        fprintf(p_out, "| %-61s |\n", "GESAMT-STATISTIK (Durchschnittswerte)");
        fprintf(p_out, "+---------------------------------------------------------------+\n");
        fprintf(p_out, "\n");
        fprintf(p_out, "+-------------------------------------------+------------+-----------------+\n");
        fprintf(p_out, "| %-42s| Wert       | Einheit         |\n", "Kennzahl");
        fprintf(p_out, "+-------------------------------------------+------------+-----------------+\n");

        // 1. Durchschnittl. parkende Autos + Balken relativ zu time_samples.
        fprintf(p_out, "| %-42s|%11.1f | Fahrzeuge       |\n", "1. Durchschnittl. parkende Autos", avg_parked_vehicles);
        {
            int bar_filled = 0;
            if (p_statistics->time_samples > 0)
                bar_filled = (int)(avg_parked_vehicles / p_statistics->time_samples * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // Balken auf max. 20 Zeichen begrenzen
            fprintf(p_out, "|    %-38s | ", "Mittelwert-Balken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, "         |\n");
        }
        fprintf(p_out, "|\n");

        // 2. Durchschnittl. Auslastung + Balken relativ zu 100 Prozent.
        fprintf(p_out, "| %-42s|%11.1f | Prozent         |\n", "2. Durchschnittl. Auslastung", avg_occupancy_percent);
        {
            int bar_filled = (int)(avg_occupancy_percent / 100.0 * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // Balken auf max. 20 Zeichen begrenzen
            fprintf(p_out, "|    %-38s | ", "Prozentbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, "         |\n");
        }
        fprintf(p_out, "|\n");

        // 3. Durchschnittl. wartende Fahrzeuge + Balken relativ zu time_samples.
        fprintf(p_out, "| %-42s|%11.1f | Fahrzeuge       |\n", "3. Durchschnittl. wartende Fahrzeuge", avg_queued_vehicles);
        {
            int bar_filled = 0;
            if (p_statistics->time_samples > 0)
                bar_filled = (int)(avg_queued_vehicles / p_statistics->time_samples * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // Balken auf max. 20 Zeichen begrenzen
            fprintf(p_out, "|    %-38s | ", "Warteschlangenbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, "         |\n");
        }
        fprintf(p_out, "|\n");

        // 4. Gesamte durchschn. Parkdauer + Balken relativ zu time_samples.
        fprintf(p_out, "| %-42s|%11.1f | Zeitschritte    |\n", "4. Gesamte durchschn. Parkdauer", avg_park_duration);
        {
            int bar_filled = 0;
            if (p_statistics->time_samples > 0)
                bar_filled = (int)(avg_park_duration / p_statistics->time_samples * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // Balken auf max. 20 Zeichen begrenzen
            fprintf(p_out, "|    %-38s | ", "Dauerbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, "         |\n");
        }
        fprintf(p_out, "|\n");

        // 5. Gesamte durchschn. Wartedauer + Balken relativ zu time_samples.
        fprintf(p_out, "| %-42s|%11.1f | Zeitschritte    |\n", "5. Gesamte durchschn. Wartedauer", avg_wait_duration);
        {
            int bar_filled = 0;
            if (p_statistics->time_samples > 0)
                bar_filled = (int)(avg_wait_duration / p_statistics->time_samples * 20.0 + 0.5);
            if (bar_filled > 20) bar_filled = 20; // Balken auf max. 20 Zeichen begrenzen
            fprintf(p_out, "|    %-38s | ", "Wartezeitbalken");
            for (int i = 0; i < bar_filled; i++)      fprintf(p_out, "#");
            for (int i = bar_filled; i < 20; i++) fprintf(p_out, "-");
            fprintf(p_out, "         |\n");
        }

        fprintf(p_out, "+-------------------------------------------+------------+-----------------+\n");

        if (t != 0) { fclose(p_out); } // nur Datei-Handle schliessen
    }
}
