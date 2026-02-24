#include "queue.h"

/**
 * @brief Erzeugt einen neuen Listenknoten mit den Fahrzeugdaten.
 */
static QueueNode *node_create(const Vehicle *p_vehicle);
static void node_destroy(QueueNode *p_node);