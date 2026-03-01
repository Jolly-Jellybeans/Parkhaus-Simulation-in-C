#ifndef PARKING_GARAGE_H
#define PARKING_GARAGE_H
#include "vehicle.h"
#include "queue.h"

// Hier Programm:

/* typedef struct
{
    int slot_count;          // Gesamtanzahl der Stellplätze
    int occupied_count;      // Anzahl aktuell belegter Stellplätze
    Vehicle *p_slots;        // Dynamisches Array: Stellplätze
    Queue *p_queue;          // Warteschlange für Fahrzeuge
} ParkingGarage;
*/

TYPE Parking Garage
    slot_count               // Gesamtanzahl der Stellplätze
    occupied_count           // Anzahl aktuell belegter Stellplätze
    p_slots                  // Dynamisches Array: Stellplätze
    p_queue                  // Warteschlange für Fahrzeuge

END TYPE


/**
 * @brief Erstellt eine neue Parkhausstruktur mit einer gegebenen Anzahl an Stellplätzen.
 *
 * @param[in] slot_count Anzahl der verfügbaren Stellplätze im Parkhaus.
 * @return Zeiger auf die erzeugte Parkhausstruktur oder NULL bei Fehler.
 */
ParkingGarage *parking_garage_create(int slot_count);
/**
 * @brief Gibt alle Ressourcen eines Parkhauses frei.
 *
 * @param[in,out] p_garage Zeiger auf die zu zerstörende Parkhausstruktur.
 * @return Kein Rückgabewert.
 */
void parking_garage_destroy(ParkingGarage *p_garage);
/**
 * @brief Versuch, ein Fahrzeug im Parkhaus einzuparken.
 *
 * @param[in,out] p_garage Parkhausstruktur, in der der Parkplatz gesucht wird.
 * @param[in] p_vehicle Fahrzeugdaten, die eingeparkt werden sollen.
 * @param[in] current_time Aktueller Simulationszeitpunkt.
 * @return Ergebnisstatus des Parkversuchs.
 */
ParkingResult parking_garage_park(ParkingGarage *p_garage,const Vehicle *p_vehicle,int current_time);

/**
 * @brief Entfernt alle Fahrzeuge mit geplanter Abfahrtszeit (<= current_time).
 *
 * @param[in,out] p_garage Parkhausstruktur, in der die Abfahrten geprüft werden.
 * @param[in] current_time Aktueller Simulationszeitpunkt.
 * @return Anzahl der entfernten Fahrzeuge.
 */
int parking_garage_remove_departing(ParkingGarage *p_garage,int current_time);
#endif /* PARKING_GARAGE_H */
