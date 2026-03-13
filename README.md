# Parkhaus-Simulation-in-C
von Niklas Reutter, Bennet Weith, Arne Stützle

| | |
| :--- | :--- |
| Kurs | TSA/TSL 25 |
| Studiengang | Embedded Systems |
| Fach | Programmieren 1 |
| Sprache | C |



## Projektstruktur

```bash
Parkhaus-Simulation-in-C/
├── .vscode/
│   ├── c_cpp_properties.json     
│   ├── launch.json                
│   ├── settings.json              
│   └── tasks.json                 
├── additional_items/
│   └── c_coding_conventions_for_embedded_systems.md
├── docs/
│   ├── 5_Statistiken.md
│   ├── ausgabe.md
│   ├── begruendungs.md
│   ├── data_types_overview_v2.md
│   └── *.drawio                   Flussdiagramme und Ablaufskizzen
├── include/
│   ├── io.h                       Ein-/Ausgabe und Konfiguration
│   ├── parking_garage.h           Parkhaus- und Stellplatzdaten
│   ├── queue.h                    Warteschlangen-API
│   ├── simulation.h               Simulationsablauf
│   ├── statistics.h               Statistikdaten und Ausgaben
│   └── vehicle.h                  Fahrzeugdaten und Validierung
├── source/
│   ├── io.c                       Eingaben und Ergebnis-Meldungen
│   ├── main.c                     Programmstart und Ablaufsteuerung
│   ├── parking_garage.c           Ein-/Ausparken und Slot-Verwaltung
│   ├── queue.c                    Queue-Operationen
│   ├── simulation.c               Simulationsschritte
│   ├── statistics.c               Statistikberechnung/-ausgabe
│   └── vehicle.c                  Fahrzeugvalidierung
├── tests/
│   ├── test_main.c                Test-Runner
│   ├── test_parking_garage.c      Tests Parkhaus
│   ├── test_queue.c               Tests Queue
│   ├── test_statistics.c          Tests Statistik
│   ├── test_io.c                  Tests Input/Output
│   └── test_simulation.c          Tests Simulation
├── README.md
└── parkhaus_sim                   erzeugtes Programm (nach Build)
```

