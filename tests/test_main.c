#include <stdio.h>

/*
Kompilieren und Ausführen aller Unit-Tests:
cc -g -I./include ./tests/\\*.c ./source/parking_garage.c ./source/queue.c \
./source/vehicle.c ./source/statistics.c -o ./tests/unit_tests && ./tests/unit_tests
*/

// test_parking_garage.c
void test_find_free_slot_index_free_slot_exists(void);
void test_find_free_slot_index_no_free_slot(void);
void test_clear_slot_resets_all_fields(void);
void test_clear_slot_with_null_pointer(void);
void test_parking_garage_remove_departing_removes_due_vehicles(void);
void test_parking_garage_remove_departing_keeps_future_vehicles(void);
void test_parking_garage_park_direct_success(void);
void test_parking_garage_park_queued_when_no_slot_free(void);
void test_parking_garage_create_valid_slot_count(void);
void test_parking_garage_create_invalid_slot_count(void);

// test_statistics.c
void test_statistics_init_resets_all_fields(void);
void test_statistics_init_fresh_struct_start_state(void);
void test_statistics_on_queued_increments_currently_queued(void);
void test_statistics_on_queued_counts_multiple_queue_events(void);
void test_statistics_on_parked_from_queue_adds_wait_time(void);
void test_statistics_on_parked_from_queue_handles_non_positive_wait(void);
void test_statistics_step_update_updates_state_and_sums(void);
void test_statistics_step_update_normalizes_invalid_inputs(void);
void test_statistics_on_departure_adds_park_duration(void);
void test_statistics_on_departure_normalizes_negative_duration(void);

// test_queue.c
void test_node_create(void);
void test_queue_create(void);
void test_queue_destroy(void);
void test_queue_dequeue(void);
void test_queue_is_empty(void);
void test_queue_enqueue(void);
void test_queue_size(void);

// test_vehicle.c
void test_vehicle_is_valid_with_null_pointer(void);
void test_vehicle_is_valid_with_valid_vehicle(void);

int main(void)
{
	// parking_garage
	test_find_free_slot_index_free_slot_exists();
	test_find_free_slot_index_no_free_slot();
	test_clear_slot_resets_all_fields();
	test_clear_slot_with_null_pointer();
	test_parking_garage_remove_departing_removes_due_vehicles();
	test_parking_garage_remove_departing_keeps_future_vehicles();
	test_parking_garage_park_direct_success();
	test_parking_garage_park_queued_when_no_slot_free();
	test_parking_garage_create_valid_slot_count();
	test_parking_garage_create_invalid_slot_count();

	// statistics
	test_statistics_init_resets_all_fields();
	test_statistics_init_fresh_struct_start_state();
	test_statistics_on_queued_increments_currently_queued();
	test_statistics_on_queued_counts_multiple_queue_events();
	test_statistics_on_parked_from_queue_adds_wait_time();
	test_statistics_on_parked_from_queue_handles_non_positive_wait();
	test_statistics_step_update_updates_state_and_sums();
	test_statistics_step_update_normalizes_invalid_inputs();
	test_statistics_on_departure_adds_park_duration();
	test_statistics_on_departure_normalizes_negative_duration();

	// queue
	test_node_create();
	test_queue_create();
	test_queue_destroy();
	test_queue_dequeue();
	test_queue_is_empty();
	test_queue_enqueue();
	test_queue_size();

	// vehicle
	test_vehicle_is_valid_with_null_pointer();
	test_vehicle_is_valid_with_valid_vehicle();

	printf("Alle Unit-Tests erfolgreich.\n");
	return 0;
}
