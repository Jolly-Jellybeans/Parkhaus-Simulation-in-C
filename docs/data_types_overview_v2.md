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
## 4. ParkingResult (include/parking_garage.h)
## 5. Statistics (include/statistics.h)
