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

// Definition der Warteschlange (Queue)
STRUCTURE Queue
    head: Zeiger auf QueueNode // Anfang der Schlange (Entnahme)
    tail: Zeiger auf QueueNode // Ende der Schlange (Einfügen)
END STRUCTURE

// Erzeugt einen neuen Knoten und initialisiert ihn
FUNCTION node_create(vehicle)
    // 1. Speicher reservieren
    node ← Speicher für QueueNode allozieren
    
    // 2. Prüfen und Daten kopieren
    IF node ungleich NULL THEN
        node.data ← vehicle
        node.next ← NULL
    END IF
    
    RETURN node
END FUNCTION
*/