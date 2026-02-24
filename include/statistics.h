#ifndef STATISTICS_H
#define STATISTICS_H
#include "parking_garage.h"
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
void statistics_on_departure(Statistics *p_statistics,int park_duration);
void statistics_step_update(Statistics *p_statistics,int occupied_slots,int total_slots);
void statistics_print(const Statistics *p_statistics);
#endif /* STATISTICS_H */
