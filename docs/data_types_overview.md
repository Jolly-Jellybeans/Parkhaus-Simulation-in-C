# Data Types Overview
This document provides an overview of all custom data types used in the Parking Garage project.

## 1. Vehicle (include/vehicle.h)

**Purpose**
Represents a vehicle in the parking system.

**Attributes**
- 'int id' -- Unique identifier of the vehicle
- 'int remaining_duration' -- Remaining parking duration
- 'int entry_time' -- Time of entry into parking garage

**Used by:**
- Queue
- ParkingGarage
- IO Module

---

## 2. Queue (include/queue.h)

**Purpose:**  
Represents the waiting queue for vehicles when the parking garage is full.

**Structure:**  
Currently not publicly defined in the header file.

**Main Functions:**
- queue_create
- queue_destroy
- queue_enqueue
- queue_dequeue
- queue_is_empty

---

## 3. ParkingGarage (include/parking_garage.h)

**Purpose:**  
Represents the complete parking garage including parking slots and waiting queue.

**Main Functions:**
- parking_garage_create
- parking_garage_destroy
- parking_garage_park
- parking_garage_unpark
- parking_garage_remove_departing

---

## 4. Statistics (include/statistics.h)

**Purpose:**  
Handles statistical tracking of parking events.

**Main Functions:**
- statistics_init
- statistics_on_queued
- statistics_on_parked_from_queue
- statistics_on_departure
- statistics_step_update
- statistics_print

---

## 5. ParkingResult

**Purpose:**  
Represents the result of parking or unparking operations.
