#include "parking_garage.h"
#include "statistics.h"
#include "queue.h"
#include "vehicle.h"
#include "io.h"



//int main(void)
// {
//      bool running = true;
//
//      ParkingGarage *garage = parking_garage_create(10);
//      Statistics stats;
//      statistic_init(&stats);
//
//      while (running)
//      {
//          print_menu();
//          int choice = read_menu_choice();
//          
//          switch (choice)
//          {
//              case 1:
//                  // Fahrzeug einparken
//                  break;
//
//              case 2:
//                  // Abfahrten verarbeiten
//                  break;
//
//              case 3:
//                  print_parking_garage_status(garage);
//                  break;
//
//              case 4:
//                  statistics_print(&stats);
//                  break;
//
//              case 0:
//                  running = false;
//                  break;
//
//              default:
//                  printf("Ungültige Eingabe!\n);
//                  break;
//            }
//      }
//
//      parking_garage_destroy(garage);
//      return 0;
//  }



// -----------------------------------------------
// PSEUDOCODE
//------------------------------------------------

PROGRAM Main

    CREATE parking garage with fixed number of slots
    INITIALIZE statistics structure

    SET running = true

    WHILE running DO

        DISPLAY main menu
        READ user choice

        IF choice == 1 THEN
            READ vehicle data from user
            VALIDATE vehicle data
            TRY to park vehicle in garage
            DISPLAY result message
            UPDATE statistics if necessary

        ELSE IF choice == 2 THEN
            PROCESS departures based on current simulation time
            UPDATE statistics

        ELSE IF choice == 3 THEN
            DISPLAY current parking garage status

        ELSE IF choice == 4 THEN
            DISPLAY collected statistics

        ELSE IF choice == 0 THEN
            SET running = false

        ELSE
            DISPLAY "Invalid input"

        END IF

    END WHILE

    DESTROY parking garage
    TERMINATE program

END PROGRAM
