#ifndef SIMULATION_H
#define SIMULATION_H

#include "parking_garage.h"
#include "statistics.h"
#include "io.h"
#include "vehicle.h"

/**
 * @brief Hauptfunktion der Parkhaus-Simulation. Initialisiert die Simulation, führt die Hauptschleife aus und gibt die Ergebnisse aus.
 *
 * @param[in,out] p_garage Parkhausstruktur, die simuliert wird.
 * @param[in,out] p_stats Statistikstruktur, die die Ergebnisse speichert.
 * @param[in] config_sim_duration Dauer der Simulation in Zeitpunkten.
 * @param[in] config_arrival_prob Wahrscheinlichkeit für ein neues Fahrzeug in Prozent.
 * @param[in] config_max_duration Maximale Parkdauer eines Fahrzeugs in Zeitpunkten.
 */
void simulation(ParkingGarage *p_garage, Statistics *p_stats, int config_sim_duration, int config_arrival_prob, int config_max_duration);

#endif /* SIMULATION_H */