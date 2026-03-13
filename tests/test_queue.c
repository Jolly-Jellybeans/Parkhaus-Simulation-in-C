#include <assert.h>
#include "queue.h"

/*
Test node_create:
Ein Knoten wird mit einmal mit normalen und leerem Fahrzeug erstellt.
Dann wird überprüft ob der Knoten korrekt initialisiert wurde und am Ende freigegeben.
*/

void test_node_create() {
    Vehicle v = {.id = 123, .entry_time = 10};
    
    QueueNode *node1 = node_create(&v);

    // Speicher reserviert 
    assert(node1 != NULL);
    
    // Daten korrekt kopiert
    assert(node1->data.id == 123);
    assert(node1->data.entry_time == 10);
    
    // Nachfolger auf NULL gesetzt
    assert(node1->p_next == NULL);

    free(node1);

 // Test mit leerem Auto 
    Vehicle v_empty = {0}; 

    QueueNode *node2 = node_create(&v_empty);

    assert(node2 != NULL);
    assert(node2->data.id == 0);
    assert(node2->p_next == NULL);

    node_destroy(node2);
}