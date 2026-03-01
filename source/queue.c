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

// Gibt einen Knoten sicher frei
FUNCTION node_destroy(node)
    IF node ungleich NULL THEN
        Speicher für node freigeben
    END IF
END FUNCTION

// Erstellt eine neue Warteschlange
FUNCTION queue_create()
    queue ← Speicher für Queue-Struktur allozieren
    
    IF queue ungleich NULL THEN
        queue.head ← NULL
        queue.tail ← NULL
    END IF
    
    RETURN queue
END FUNCTION

// Löscht die gesamte Warteschlange
FUNCTION queue_destroy(queue)
    IF queue ist NULL THEN
        RETURN
    END IF

    current ← queue.head
    
    // Iteriere durch die Liste und lösche jeden Knoten
    WHILE current ungleich NULL DO
        next_node ← current.next
        
        // Nutze Hilfsfunktion zum Löschen
        CALL node_destroy(current)
        
        current ← next_node
    END WHILE

    // Container selbst freigeben
    Speicher für queue freigeben
END FUNCTION

// Fügt ein Fahrzeug am Ende hinzu
FUNCTION queue_enqueue(queue, vehicle)
    // Sicherheitschecks
    IF queue ist NULL ODER vehicle ist NULL THEN
        RETURN FALSE
    END IF

    // Nutze Hilfsfunktion zum Erstellen (kapselt malloc)
    new_node ← CALL node_create(vehicle)
    
    // Prüfen, ob Speicher voll war
    IF new_node ist NULL THEN
        RETURN FALSE
    END IF

    // Einfügen am Ende (Tail)
    IF queue.tail ist NULL THEN
        // Fall: Liste war leer -> Head und Tail zeigen auf neuen Knoten
        queue.head ← new_node
        queue.tail ← new_node
    ELSE
        // Fall: Liste nicht leer -> Anfügen und Tail aktualisieren
        queue.tail.next ← new_node
        queue.tail ← new_node
    END IF

    RETURN TRUE
END FUNCTION

// Entfernt das vorderste Fahrzeug
FUNCTION queue_dequeue(queue, out_vehicle)
    // Prüfen ob Queue existiert, Zielstruktur da ist oder Queue leer ist
    IF queue ist NULL ODER out_vehicle ist NULL ODER queue.head ist NULL THEN
        RETURN FALSE
    END IF

    // Den ersten Knoten merken
    temp_node ← queue.head
    
    // Daten in die Zielstruktur kopieren
    out_vehicle ← temp_node.data

    // Head weitersetzen (auf das zweite Element)
    queue.head ← temp_node.next

    // Sonderfall: Wenn Liste jetzt leer ist (Head ist NULL), muss auch Tail NULL sein
    IF queue.head ist NULL THEN
        queue.tail ← NULL
    END IF

    // Alten Knoten mit Hilfsfunktion freigeben
    CALL node_destroy(temp_node)
    
    RETURN TRUE
END FUNCTION
*/