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

    node_destroy(node1);

 // Test mit leerem Auto 
    Vehicle v_empty = {0}; 

    QueueNode *node2 = node_create(&v_empty);

    assert(node2 != NULL);
    assert(node2->data.id == 0);
    assert(node2->p_next == NULL);

    node_destroy(node2);
}

/* Test queue_create:
Überprüft on eine leere Schlange richtig erstellt wurde
*/

void test_queue_create() {
    Queue *q = queue_create();

    // Speicherebene prüfen
    assert(q != NULL);

    // Initialisierung prüfen 
    assert(q->p_head == NULL);
    assert(q->p_tail == NULL);

    queue_destroy(q);
}

/* Test queue_destroy:
Bei fehlerhaften Funktionen stürzt das Programm ab, 
eine Überprüfung ob Speicher freigegeben wurde, ist mit assert nicht möglich
*/
void test_queue_destroy() {

    // Test 1: NULL-Pointer 
    // Überprüfung ob NULL-Pointer ignoriert wird
    queue_destroy(NULL);
  

    // Test 2: Gefüllte Queue 
    // Prüft, ob die while-Schleife auf keine fehlerhaften Adressen zeigt
    Queue *q_filled = queue_create();
    assert(q_filled != NULL);

    Vehicle v1 = {.id = 101, .entry_time = 5};
    Vehicle v2 = {.id = 102, .entry_time = 6};
    Vehicle v3 = {.id = 103, .entry_time = 7};

    enqueue(q_filled, &v1);
    enqueue(q_filled, &v2);
    enqueue(q_filled, &v3);

    queue_destroy(q_filled);
}

/* Test queue_dequeue:
Überprüft das sichere Entnehmen von Elementen und das Nachrücken der Zeiger.
*/
void test_queue_dequeue() {
    Queue *q = queue_create();
    Vehicle out_v = {0};
    Vehicle v1 = {.id = 101, .entry_time = 5};

    // Test 1: Ungültige Eingaben & Leere Queue
    // Überprüfung, ob Entnahmeversuche ohne Daten sicher abgefangen werden
    assert(queue_dequeue(NULL, &out_v) == false);
    assert(queue_dequeue(q, &out_v) == false);

    // Test 2: Entnahme und kritischer Pfad
    // Prüft die korrekte Datenübergabe und den Reset beim Entnehmen des letzten Elements
    queue_enqueue(q, &v1);
    assert(queue_dequeue(q, &out_v) == true);
    assert(out_v.id == 101);
    assert(q->p_head == NULL && q->p_tail == NULL);

    queue_destroy(q);
}
