#ifndef QUEUE_H
#define QUEUE_H
#include "vehicle.h"
#include <stdbool.h>
// Definition eines einzelnen Knotens
typedef struct QueueNode {
    Vehicle data;               
    struct QueueNode *p_next;   
} QueueNode;

typedef struct Queue {
    QueueNode *p_head; // Anfang der Schlange
    QueueNode *p_tail; // Ende der Schlange
} Queue;
/**
 * @brief Erzeugt einen neuen Queue-Knoten mit kopierten Fahrzeugdaten.
 *
 * @param[in] p_vehicle Fahrzeugdaten, die im Knoten gespeichert werden.
 * @return Zeiger auf den neuen Knoten oder NULL bei Fehler.
 */
QueueNode *node_create(const Vehicle *p_vehicle);
/**
 * @brief Gibt einen zuvor erzeugten Queue-Knoten frei.
 *
 * @param[in,out] p_node Zu loeschender Knoten.
 * @return Kein Rueckgabewert.
 */
void node_destroy(QueueNode *p_node);
/**
 * @brief Erstellt eine neue Fahrzeugwarteschlange.
 *
 * @return Zeiger auf die erzeugte Queue oder NULL bei Misserfolg.
 */
Queue *queue_create(void);
/**
 * @brief Gibt die Queue und ihre Ressourcen frei.
 *
 * @param[in,out] p_queue Zu zerstörende Queue.
 * @return Kein Rückgabewert.
 */
void queue_destroy(Queue *p_queue);
/**
 * @brief Fügt ein Fahrzeug ans Ende der Warteschlange an.
 *
 * @param[in,out] p_queue Zielwarteschlange.
 * @param[in] p_vehicle Fahrzeugdaten zum Hinzufügen.
 * @return true bei Erfolg, false wenn die Queue voll ist.
 */
bool queue_enqueue(Queue *p_queue,const Vehicle *p_vehicle);
/**
 * @brief Entfernt das vorderste Fahrzeug aus der Warteschlange.
 *
 * @param[in,out] p_queue Queue, aus der das Fahrzeug entfernt wird.
 * @param[out] p_out_vehicle Zielstruktur für das entfernte Fahrzeug.
 * @return true bei Erfolg, false wenn die Queue leer ist.
 */
bool queue_dequeue(Queue *p_queue,Vehicle *p_out_vehicle);
/**
 * @brief Prüft, ob die Warteschlange leer ist.
 *
 * @param[in] p_queue Zu prüfende Queue.
 * @return true, wenn keine Fahrzeuge warten, sonst false.
 */
bool queue_is_empty(const Queue *p_queue);
/**
 * @brief Gibt die aktuelle Anzahl wartender Fahrzeuge in der Queue zurück.
 *
 * @param[in] p_queue Zu zählende Queue.
 * @return Anzahl der Fahrzeuge in der Warteschlange (0 bei NULL oder leerer Queue).
 */
int queue_size(const Queue *p_queue);
#endif /* QUEUE_H */
