#ifndef STATISTICS_H
#define STATISTICS_H
#include "parking_garage.h"

STRUCTURE Statistics

    currently_parked
    currently_queued

    parked_vehicle_count_sum
    queued_vehicle_count_sum
    time_samples

    occupancy_ratio_sum
    occupancy_samples
    queued_vehicle_count_served
    total_park_duration
    departed_vehicle_count
    total_wait_duration

END STRUCTURE
//Hier Programm:
/**
 * @brief Initialisiert die Statistikdaten vor dem Start der Simulation.
 *
 * @param[out] p_statistics Zeiger auf die Statistikstruktur, die zurückgesetzt wird.
 */
void statistics_init(Statistics *p_statistics);
/**
 * @brief Aktualisiert Statistikdaten, wenn ein Fahrzeug in die Warteschlange aufgenommen wird.
 *
 * @param[in,out] p_statistics Statistikstruktur, die aktualisiert wird.
 */
void statistics_on_queued(Statistics *p_statistics);
/**
 * @brief Aktualisiert Statistikdaten, wenn ein wartendes Fahrzeug einen Parkplatz bekommt.
 *
 * @param[in,out] p_statistics Statistikstruktur, die aktualisiert wird.
 * @param[in] wait_duration Wartezeit in Zeiteinheiten, die das Fahrzeug in der Queue verbracht hat.
 */
void statistics_on_parked_from_queue(Statistics *p_statistics,int wait_duration);
/**
 * @brief Aktualisiert Statistikdaten nach der Abfahrt eines Fahrzeugs.
 *
 * @param[in,out] p_statistics Statistikstruktur, die aktualisiert wird.
 * @param[in] park_duration Parkdauer des Fahrzeugs, das das Parkhaus verlässt.
 */
void statistics_on_departure(Statistics *p_statistics,int park_duration);
/**
 * @brief Aktualisiert zeitabhängige Werte (Parkende, Auslastung, Wartende) pro Simulationsschritt.
 *
 * @param[in,out] p_statistics Statistikstruktur, die aktualisiert wird.
 * @param[in] occupied_slots Aktuell belegte Stellplätze.
 * @param[in] total_slots Gesamtanzahl verfügbarer Stellplätze.
 * @param[in] queued_vehicles Aktuell wartende Fahrzeuge in der Warteschlange.
 */
void statistics_step_update(Statistics *p_statistics,int occupied_slots,int total_slots,int queued_vehicles);
/**
 * @brief Gibt die gesammelten Statistikwerte auf der Konsole aus.
 *
 * @param[in] p_statistics Statistikstruktur, die ausgegeben wird.
 */
void statistics_print(const Statistics *p_statistics);
#endif /* STATISTICS_H */
