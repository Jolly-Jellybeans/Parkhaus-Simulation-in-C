#include <assert.h>
#include "queue.h"

void test_node_create() {
    Vehicle v = {.id = 123, .entry_time = 10};
    
    QueueNode *node = node_create(&v);

    // Speicher reserviert 
    assert(node != NULL);
    
    // Daten korrekt kopiert
    assert(node->data.id == 123);
    assert(node->data.entry_time == 10);
    
    // Nachfolger auf NULL gesetzt
    assert(node->p_next == NULL);

    free(node);
}