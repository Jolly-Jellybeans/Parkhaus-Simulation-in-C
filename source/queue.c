#include "queue.h"

/**
 * @brief Erzeugt einen neuen Listenknoten mit den Fahrzeugdaten.
 */
static QueueNode *node_create(const Vehicle *p_vehicle);
/**
 * @brief Gibt einen Listenknoten inkl. Fahrzeugdaten frei.
 */
static void node_destroy(QueueNode *p_node);

/*
// Definition eines einzelnen Knotens (QueueNode)
STRUCTURE QueueNode
    data: Vehicle              // Die gespeicherten Fahrzeugdaten
    next: Zeiger auf QueueNode // Verweis auf das nächste Element
END STRUCTURE

*/