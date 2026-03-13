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

### source/

Enthält die Implementierungen der Programmlogik:

- `main.c` – Einstiegspunkt, Initialisierung und Ablaufstart
- `simulation.c` – Hauptschleife der Simulation
- `parking_garage.c` – Parkhauslogik (Parken, Abfahrten, Stellplatzverwaltung)
- `queue.c` – Warteschlange für Fahrzeuge
- `statistics.c` – Erfassung und Ausgabe von Kennzahlen
- `vehicle.c` – Fahrzeug-Validierung
- `io.c` – Ein-/Ausgabe und Benutzereingaben

### include/

Header-Dateien mit Datentypen und Funktionsschnittstellen:

- `parking_garage.h`
- `simulation.h`
- `queue.h`
- `statistics.h`
- `vehicle.h`
- `io.h`

### docs/

Dokumentation, Flussdiagramme und ergänzende Projektunterlagen.

### tests/

Testdateien für einzelne Komponenten (z. B. Queue-Verhalten).

## Entwickler

Programmentwurf von Bennet Weith, Niklas Reutter und Arne Stützle.
