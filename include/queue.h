#ifndef QUEUE_H
#define QUEUE_H
#include "vehicle.h"
//Hier Programm:
/**
 * @brief Erstellt eine neue Fahrzeugwarteschlange.
 *
 * @return Zeiger auf die erzeugte Queue oder NULL bei Misserfolg.
 */
Queue *queue_create(void);
void queue_destroy(Queue *p_queue);
bool queue_enqueue(Queue *p_queue,const Vehicle *p_vehicle);
bool queue_dequeue(Queue *p_queue,Vehicle *p_out_vehicle);
bool queue_is_empty(const Queue *p_queue);
#endif /* QUEUE_H */
