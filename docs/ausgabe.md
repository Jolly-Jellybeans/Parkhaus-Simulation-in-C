# Statistik Terminalausgaben

## Pro Zeitschritt:

```text
+--------------------------------------------+------------+-----------------+ 
| AKTUELLER STATUS: Schritt %d / %d          | Wert       | Einheit         |
+--------------------------------------------+------------+-----------------+
| 1. Aktuell parkende Autos                  |         12 | Fahrzeuge       |
| 2. Aktuelle Auslastung                     |       60.0 | Prozent         |
| 3. Aktuell wartende Fahrzeuge              |         24 | Fahrzeuge       |
| 4. Aktuelle durchschn. Parkdauer           |       14.2 | Zeitschritte    |
| 5. Aktuelle durchschn. Wartedauer          |        4.8 | Zeitschritte    |
+--------------------------------------------+------------+-----------------+
```

## Ausgabe am Ende:

```text
+--------------------------------------------+------------+-----------------+
| GESAMT-STATISTIK (Durchschnittswerte)      | Wert       | Einheit         |
+--------------------------------------------+------------+-----------------+
| 1. Durchschnittl. parkende Autos           |        8.5 | Fahrzeuge       |
| 2. Durchschnittl. Auslastung               |       74.2 | Prozent         |
| 3. Durchschnittl. wartende Fahrzeuge       |        2.1 | Fahrzeuge       |
| 4. Gesamte durchschn. Parkdauer            |       15.8 | Zeitschritte    |
| 5. Gesamte durchschn. Wartedauer           |        5.1 | Zeitschritte    |
+--------------------------------------------+------------+-----------------+
```
Falls wir die Balkendiagramm Idee noch umsetzen würde es wie folgt aussehen (s. Begründungen):
## Pro Zeitschritt:
+---------------------------------------------------------------+
| AKTUELLER STATUS: Schritt 12 / 100                           |
+---------------------------------------------------------------+

+--------------------------------------------+------------+-----------------+
| Kennzahl                                   | Wert       | Einheit         |
+--------------------------------------------+------------+-----------------+
| 1. Aktuell parkende Autos                  |         12 | Fahrzeuge       |
|    Belegungsbalken                         | ##########---------- |
|
| 2. Aktuelle Auslastung                     |       60.0 | Prozent         |
|    Prozentbalken                           | ############-------- |
|
| 3. Aktuell wartende Fahrzeuge              |         24 | Fahrzeuge       |
|    Warteschlangenbalken                    | ################---- |
|
| 4. Aktuelle durchschn. Parkdauer           |       14.2 | Zeitschritte    |
|    Dauerbalken                             | ###########--------- |
|
| 5. Aktuelle durchschn. Wartedauer          |        4.8 | Zeitschritte    |
|    Wartezeitbalken                         | ####---------------- |
+--------------------------------------------+------------+-----------------+

## Ausgabe am Ende:
+---------------------------------------------------------------+
| GESAMT-STATISTIK (Durchschnittswerte)                         |
+---------------------------------------------------------------+

+--------------------------------------------+------------+-----------------+
| Kennzahl                                   | Wert       | Einheit         |
+--------------------------------------------+------------+-----------------+
| 1. Durchschnittl. parkende Autos           |        8.5 | Fahrzeuge       |
|    Mittelwert-Balken                       | #######------------- |
|
| 2. Durchschnittl. Auslastung               |       74.2 | Prozent         |
|    Prozentbalken                           | ###############----- |
|
| 3. Durchschnittl. wartende Fahrzeuge       |        2.1 | Fahrzeuge       |
|    Warteschlangenbalken                    | ##------------------ |
|
| 4. Gesamte durchschn. Parkdauer            |       15.8 | Zeitschritte    |
|    Dauerbalken                             | ############-------- |
|
| 5. Gesamte durchschn. Wartedauer           |        5.1 | Zeitschritte    |
|    Wartezeitbalken                         | #####--------------- |
+--------------------------------------------+------------+-----------------+
