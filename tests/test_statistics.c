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
