#include "queue.h"
#include <stdlib.h>
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
    p_next: Zeiger auf QueueNode // Verweis auf das nächste Element
END STRUCTURE

// Definition der Warteschlange (Queue)
STRUCTURE Queue
    p_head: Zeiger auf QueueNode // Anfang der Schlange (Entnahme)
    p_tail: Zeiger auf QueueNode // Ende der Schlange (Einfügen)
END STRUCTURE

// Erzeugt einen neuen Knoten und initialisiert ihn
FUNCTION node_create(p_vehicle)
    // 1. Speicher reservieren
    p_node ← Speicher für QueueNode allozieren
    
    // 2. Prüfen und Daten kopieren
    IF p_node ungleich NULL THEN
        p_node.data ← p_vehicle
        p_node.p_next ← NULL
    END IF
    
    RETURN p_node
END FUNCTION

// Gibt einen Knoten sicher frei
FUNCTION node_destroy(p_node)
    IF p_node ungleich NULL THEN
        Speicher für p_node freigeben
    END IF
END FUNCTION

// Erstellt eine neue Warteschlange
FUNCTION queue_create()
    p_queue ← Speicher für Queue-Struktur allozieren
    
    IF p_queue ungleich NULL THEN
        p_queue.p_head ← NULL
        p_queue.p_tail ← NULL
    END IF
    
    RETURN p_queue
END FUNCTION

// Löscht die gesamte Warteschlange
FUNCTION queue_destroy(p_queue)
    IF p_queue ist NULL THEN
        RETURN
    END IF

    p_current ← p_queue.p_head
    
    // Iteriere durch die Liste und lösche jeden Knoten
    WHILE p_current ungleich NULL DO
        p_next_node ← p_current.p_next
        
        // Nutze Hilfsfunktion zum Löschen
        CALL node_destroy(p_current)
        
        p_current ← p_next_node
    END WHILE

    // Container selbst freigeben
    Speicher für p_queue freigeben
END FUNCTION

// Fügt ein Fahrzeug am Ende hinzu
FUNCTION queue_enqueue(p_queue, p_vehicle)
    // Sicherheitschecks
    IF p_queue ist NULL ODER p_vehicle ist NULL THEN
        RETURN FALSE
    END IF

    // Nutze Hilfsfunktion zum Erstellen (kapselt malloc)
    p_new_node ← CALL node_create(p_vehicle)
    
    // Prüfen, ob Speicher voll war
    IF p_new_node ist NULL THEN
        RETURN FALSE
    END IF

    // Einfügen am Ende (Tail)
    IF p_queue.p_tail ist NULL THEN
        // Fall: Liste war leer -> Head und Tail zeigen auf neuen Knoten
        p_queue.p_head ← p_new_node
        p_queue.p_tail ← p_new_node
    ELSE
        // Fall: Liste nicht leer -> Anfügen und Tail aktualisieren
        p_queue.p_tail.p_next ← p_new_node
        p_queue.p_tail ← p_new_node
    END IF

    RETURN TRUE
END FUNCTION

// Entfernt das vorderste Fahrzeug
FUNCTION queue_dequeue(p_queue, p_out_vehicle)
    // Prüfen ob Queue existiert, Zielstruktur da ist oder Queue leer ist
    IF p_queue ist NULL ODER p_out_vehicle ist NULL ODER p_queue.p_head ist NULL THEN
        RETURN FALSE
    END IF

    // Den ersten Knoten merken
    p_temp_node ← p_queue.p_head
    
    // Daten in die Zielstruktur kopieren
    p_out_vehicle ← p_temp_node.data

    // Head weitersetzen (auf das zweite Element)
    p_queue.p_head ← p_temp_node.p_next

    // Sonderfall: Wenn Liste jetzt leer ist (Head ist NULL), muss auch Tail NULL sein
    IF p_queue.p_head ist NULL THEN
        p_queue.p_tail ← NULL
    END IF

    // Alten Knoten mit Hilfsfunktion freigeben
    CALL node_destroy(p_temp_node)
    
    RETURN TRUE
END FUNCTION

// Prüft auf Leere
FUNCTION queue_is_empty(p_queue)
    IF p_queue ist NULL THEN
        RETURN TRUE
    END IF
    
    // Queue ist leer, wenn Head NULL ist
    IF p_queue.p_head ist NULL THEN
        RETURN TRUE
    ELSE
        RETURN FALSE
    END IF
END FUNCTION

// Zählt die Elemente in der Queue
FUNCTION queue_size(p_queue)
    IF p_queue ist NULL ODER p_queue.p_head ist NULL THEN
        RETURN 0
    END IF

    count ← 0
    p_current ← p_queue.p_head

    WHILE p_current ungleich NULL DO
        count ← count + 1
        p_current ← p_current.p_next
    END WHILE

    RETURN count
END FUNCTION
*/


// Definition eines einzelnen Knotens
typedef struct QueueNode {
    Vehicle data;               
    struct QueueNode *p_next;   
} QueueNode;

typedef struct Queue {
    QueueNode *p_head; // Anfang der Schlange
    QueueNode *p_tail; // Ende der Schlange
} Queue;

static QueueNode *node_create(const Vehicle *p_vehicle) {
    QueueNode *p_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (p_node != NULL) {
        p_node->data = *p_vehicle; // Kopiere die Fahrzeugdaten
        p_node->p_next = NULL;     // Nächster Knoten ist zunächst NULL
    }
    return p_node;
}

void queue_destroy(Queue *p_queue) {
    if (p_queue == NULL) {
        return;
    }

    QueueNode *p_current = p_queue->p_head;
    while (p_current != NULL) {
        QueueNode *p_next_node = p_current->p_next; // Nächsten Knoten merken
        node_destroy(p_current); // Aktuellen Knoten freigeben
        p_current = p_next_node; // Zum nächsten Knoten wechseln
    }

    // Verhindern von Dangling Pointern
    p_queue->p_head = NULL;
    p_queue->p_tail = NULL;
    free(p_queue);
}

Queue *queue_create() {
    Queue *p_queue = (Queue *)malloc(sizeof(Queue));
    if (p_queue != NULL) {
        p_queue->p_head = NULL; 
        p_queue->p_tail = NULL; 
    }
    return p_queue;
}

static void node_destroy(QueueNode *p_node) {
    if (p_node != NULL) {
        free(p_node); // Speicher für den Knoten freigeben
    }
}

bool queue_enqueue(Queue *p_queue, const Vehicle *p_vehicle) {
    if (p_queue == NULL || p_vehicle == NULL) {
        return false; // Ungültige Eingabe
    }

    QueueNode *p_new_node = node_create(p_vehicle);
    if (p_new_node == NULL) {
        return false; 
    }

    if (p_queue->p_tail == NULL) {
        // Queue ist leer, neuer Knoten wird zum Head und Tail
        p_queue->p_head = p_new_node;
        p_queue->p_tail = p_new_node;
    } 
    else {
        // Anfügen am Ende der Queue
        p_queue->p_tail->p_next = p_new_node;
        p_queue->p_tail = p_new_node;
    }
    return true;
}

int queue_size(const Queue *p_queue) {
    if (p_queue == NULL || p_queue->p_head == NULL) {
        return 0; // Keine Elemente in der Queue
    }

    int count = 0;
    QueueNode *p_current = p_queue->p_head;
    while (p_current != NULL) {
        count++;
        p_current = p_current->p_next; // Zum nächsten Knoten wechseln
    }
    return count;
}

bool queue_is_empty(const Queue *p_queue) {
    if (p_queue == NULL || p_queue->p_head == NULL) {
        return true; // Eine NULL-Queue gilt als leer
    }
    return false;
}

bool queue_dequeue(Queue *p_queue, Vehicle *p_out_vehicle) {
    if (p_queue == NULL || p_out_vehicle == NULL || p_queue->p_head == NULL) {
        return false; 
    }

    QueueNode *p_temp_node = p_queue->p_head; // Ersten Knoten merken
    *p_out_vehicle = p_temp_node->data; // Fahrzeugdaten kopieren

    // Head auf den nächsten Knoten setzen
    p_queue->p_head = p_temp_node->p_next;

    // Wenn die Queue jetzt leer ist, Tail auch auf NULL setzen
    if (p_queue->p_head == NULL) {
        p_queue->p_tail = NULL;
    }

    node_destroy(p_temp_node); // Alten Knoten freigeben
    return true;
}