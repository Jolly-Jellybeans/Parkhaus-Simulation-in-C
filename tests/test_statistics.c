#include <assert.h>
#include "statistics.h"

/*
Test 1:
Die Struktur enthaelt vorab beliebige Werte.
Nach statistics_init muessen alle Statistikfelder auf 0 bzw. 0.0 zurueckgesetzt sein.
*/
void test_statistics_init_resets_all_fields() {
	Statistics stats;

	stats.currently_parked = 4;
	stats.currently_queued = 2;
	stats.parked_vehicle_count_sum = 10;
	stats.queued_vehicle_count_sum = 8;
	stats.time_samples = 3;
	stats.occupancy_ratio_sum = 1.75;
	stats.occupancy_samples = 3;
	stats.queued_vehicle_count_served = 2;
	stats.total_park_duration = 25;
	stats.departed_vehicle_count = 5;
	stats.total_wait_duration = 9;

	statistics_init(&stats);

	assert(stats.currently_parked == 0);
	assert(stats.currently_queued == 0);
	assert(stats.parked_vehicle_count_sum == 0);
	assert(stats.queued_vehicle_count_sum == 0);
	assert(stats.time_samples == 0);
	assert(stats.occupancy_ratio_sum == 0.0);
	assert(stats.occupancy_samples == 0);
	assert(stats.queued_vehicle_count_served == 0);
	assert(stats.total_park_duration == 0);
	assert(stats.departed_vehicle_count == 0);
	assert(stats.total_wait_duration == 0);
}

/*
Test 2:
Frische Struktur ohne Vorbelegung.
Es wird nur geprueft, ob statistics_init den erwarteten Startzustand setzt.
*/
void test_statistics_init_fresh_struct_start_state() {
	Statistics stats = {0};

	statistics_init(&stats);

	assert(stats.currently_parked == 0);
	assert(stats.currently_queued == 0);
	assert(stats.parked_vehicle_count_sum == 0);
	assert(stats.queued_vehicle_count_sum == 0);
	assert(stats.queued_vehicle_count_served == 0);
	assert(stats.total_park_duration == 0);
	assert(stats.total_wait_duration == 0);
	assert(stats.occupancy_ratio_sum == 0.0);
	assert(stats.time_samples == 0);
	assert(stats.departed_vehicle_count == 0);
}

/*
Test 1:
Bei gueltigem aktuellen Warteschlangenstand
soll statistics_on_queued den Wert um 1 erhoehen.
*/
void test_statistics_on_queued_increments_currently_queued() {
	Statistics stats = {0};

	stats.currently_queued = 3;
	stats.time_samples = 5;
	stats.total_wait_duration = 9;

	statistics_on_queued(&stats);

	assert(stats.currently_queued == 4);
	assert(stats.time_samples == 5);
	assert(stats.total_wait_duration == 9);
}

/*
Test 2:
Bei mehreren Aufrufen soll der Warteschlangenstand
bei jedem Queue-Ereignis weiter hochgezaehlt werden.
*/
void test_statistics_on_queued_counts_multiple_queue_events() {
	Statistics stats = {0};

	stats.currently_queued = 0;
	stats.currently_parked = 2;
	stats.queued_vehicle_count_sum = 6;

	statistics_on_queued(&stats);
	statistics_on_queued(&stats);

	assert(stats.currently_queued == 2);
	assert(stats.currently_parked == 2);
	assert(stats.queued_vehicle_count_sum == 6);
}

/*
Test 1:
Bei positiver Wartezeit soll die Wartezeit aufsummiert
und der Zaehler bedienter Queue-Fahrzeuge um 1 erhoeht werden.
*/
void test_statistics_on_parked_from_queue_adds_wait_time() {
	Statistics stats = {0};

	stats.total_wait_duration = 4;
	stats.queued_vehicle_count_served = 2;
	stats.currently_queued = 3;

	statistics_on_parked_from_queue(&stats, 6);

	assert(stats.total_wait_duration == 10);
	assert(stats.queued_vehicle_count_served == 3);
	assert(stats.currently_queued == 3);
}

/*
Test 2:
Negative und null Wartezeit duerfen die Wartesumme nicht erhoehen.
Der Zaehler bedienter Queue-Fahrzeuge soll pro Aufruf steigen.
*/
void test_statistics_on_parked_from_queue_handles_non_positive_wait() {
	Statistics stats = {0};

	stats.total_wait_duration = 8;
	stats.queued_vehicle_count_served = 1;
	stats.time_samples = 5;
	stats.currently_parked = 4;

	statistics_on_parked_from_queue(&stats, -3);
	statistics_on_parked_from_queue(&stats, 0);

	assert(stats.total_wait_duration == 8);
	assert(stats.queued_vehicle_count_served == 3);
	assert(stats.time_samples == 5);
	assert(stats.currently_parked == 4);
}


