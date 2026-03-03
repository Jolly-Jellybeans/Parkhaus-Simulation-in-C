# Data Types Overview
This document provides an overview of all custom data types used in the Parking Garage project.

## 1. Vehicle (include/vehicle.h)

**Purpose**
Represents a single vehicle in the parking simulation.

**Type:** struct Vehicle

**Structure:** 
typedef struct
{ 
    int id;
    int remaining_duration;
    int entry_time;
} Vehicle;

**Attributes**
- 'int id' -- Unique identifier of the vehicle
- 'int remaining_duration' -- Remaining parking duration
- 'int entry_time' -- Time of entry into parking garage

**Used by:**
- Queue
- ParkingGarage
- IO Module
- Simulation logic

---

## 2. Queue (include/queue.h)

**Purpose:**  
Represents the waiting queue for vehicles when the parking garage is full.

**Type:** struct Queue

**Structure (short overview):**
- QueueNode stores a Vehicle and a pointer to the next node
- Queue stores pointers to the first and last node

**Structure:**  
QueueNode:
- Stores a Vehicle
- Pointer to next node

Queue:
- Pointer to first element (head)
- Pointer to last element (head)

**Used by:**
- ParkingGarage

---

## 3. ParkingGarage (include/parking_garage.h)

**Purpose:**  
Represents the complete parking garage including parking slots and waiting queue.

**Type:** struct ParkingGarage

**Structure:**
- Total number of slots
- Number of occupied slots
- Array/list of parking slots (vehicles)
- Waiting queue (Queue)

**Attributes:**
- int slot_count -- Total number of parking slots
- int occupied_count -- Currently occupied slots
- Vehicle* p_slots -- Dynamic array of parking slots
- Queue* p_queue -- Waiting queue for vehicles

**Used by:**
- Main program
- Simulation
- IO Module
- Statistics

---
## 4. ParkingResult (include/parking_garage.h)

**Purpose:**
Describes the result of a parking attempt.

**Type:**
-enum ParkingResult

**Possible Values:**
- PARKING_SUCCESS -- Vehicle successfully parked
- PARKING_QUEUED -- Vehicle added to waiting queue
- PARKING_QUEUE_FULL -- Queue is full
- PARKING_INVALID -- Invalid vehicle data

**Used by:
- ParkingGarage
- IO Module

---
## 5. Statistics (include/statistics.h)

**Purpose:**  
Stores statistical data about the parking simulation

**Typical Attributes:**
- Total vehicles processed
- Vehicles parked
- Vehicles rejected
- Average parking time
- Utilizaion rate

**Uses by:**
- Simulation
- Main programm
- Output module

