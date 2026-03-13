# Parkhaus-Simulation-in-C

Programmentwurf für eine Parkhaus-Simulation in C.
Die Anwendung simuliert über diskrete Zeitschritte:

- ankommende Fahrzeuge,
- Einparken auf freien Stellplätzen,
- Warteschlange bei vollem Parkhaus,
- Abfahrten und statistische Auswertung.

## Build und Start


### Kompilieren

Im Projektordner ausführen:

```bash
cc -g -I./include ./source/*.c -o ./parkhaus_sim
```

Alternative mit `gcc`:

```bash
gcc -g -I./include ./source/*.c -o ./parkhaus_sim
```

### Starten

```bash
./parkhaus_sim
```

Die Konfigurationswerte (z. B. Anzahl Stellplätze, Simulationsdauer, Ankunftswahrscheinlichkeit) werden beim Start abgefragt.

## Unit-Tests ausführen

Die Unit-Tests sind assert-basiert und werden über einen Test-Runner gestartet.

### Test-Binary bauen

```bash
cc -g -I./include \
	./tests/*.c \
	./source/io.c \
	./source/parking_garage.c \
	./source/queue.c \
	./source/simulation.c \
	./source/statistics.c \
	./source/vehicle.c \
	-o ./tests/unit_tests
```

### Tests starten

```bash
./tests/unit_tests
```

Wenn kein `assert` fehlschlägt, endet das Programm erfolgreich und gibt eine Bestätigung aus.

## Projektstruktur

### Projektbaum

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

## Entwickler

Programmentwurf von Bennet Weith, Niklas Reutter und Arne Stützle.
