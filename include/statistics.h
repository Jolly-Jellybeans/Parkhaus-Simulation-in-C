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
void statistics_on_queued(Statistics *p_statistics);
void statistics_on_parked_from_queue(Statistics *p_statistics,int wait_duration);
void statistics_on_departure(Statistics *p_statistics,int park_duration);
void statistics_step_update(Statistics *p_statistics,int occupied_slots,int total_slots);
void statistics_print(const Statistics *p_statistics);
#endif /* STATISTICS_H */
