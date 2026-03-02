# Data Types Overview
This document provides an overview of all custom data types used in the Parking Garage project.

## 1. Vehicle (include/vehicle.h)

**Purpose**
Represents a single vehicle in the parking simulation.

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
## 5. Statistics (include/statistics.h)
