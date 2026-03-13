## Ticket 79 – Review test requirement for "user_input"

Die Funktion "user input" verarbeitet interaktive Konsoleneingaben über "scanf, "printf" und "getchar".
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da Benutzereingaben über "stdin" simuliert und Konsolenausgaben abgefangen werden müssten.
Ohne zusätzliche Testinfrastruktur für Input-/Output-Umleitung würde ein solcher Test nicht stabil und nicht einfach umsetzbar sein.
Daher werden aktuell keine direkten Assert-Tests erstellt. 
Die Funktion wird stattdessen manuell über Konsoleneingaben geprüft.


## Ticket 80 – Review test requirement for "get_config_from-user"

Für die Funktion "get_config_from_user" werden aktuell keine direkten Assert-Tests ergänzt.
Grund dafür ist, dass die Funktion selbst keine eigenständige Fachlogik enthält, sondern mehrere Benutzereingaben über "user_input" abfragt und in einer "SimulationConfig"-Struktur speichert.
Da "user_input" direkt mit interaktiver Konsoleneingabe arbeitet ("scanf", "printf", "getchar"), hängt auch "get_config_from_user" vollständig von "stdin" und Benutzereingaben zur Laufzeit ab.
Ein automatisierter Assert-Test wäre in diesem Fall nur mit zusätzlichem Testaufbau sinnvoll, zum Beispiel durch Umleitung oder Mocking der Eingabe. Solche Tests wären im aktuellen Projektaufbau unnötig aufwendig und würden nicht die eigentliche Programmlogik isoliert prüfen.
Deshalb wird für "get_config_from_user" aktuell keine direkte Assert-Testdatei ergänzt. 
Die Funktion wird stattdessen über manuelle Eingaben im laufenden Programm geprüft.


## Ticket 61 – Review test requirement for "node_destroy"

Die Funktion "node_destroy" gibt den reservierten Speicherplatz eines einzelnen Warteschlangenknotens über die C-Standardfunktion "free" an das Betriebssystem zurück.
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da ein anschließender Lesezugriff zur Überprüfung des gelöschten Speichers nach C-Standard zu undefiniertem Verhalten bzw. einem Programmabsturz führen würde.


## Ticket 63 – Review test requirement for "statistics_print"

Die Funktion "statistics_print" erzeugt ausschließlich formatierte Konsolenausgaben über mehrere "printf"-Aufrufe.
Direkte Assert-Tests sind im aktuellen Projektaufbau dafür nicht sinnvoll, da ohne zusätzliche Testinfrastruktur keine stabile Umleitung und Auswertung von "stdout" möglich ist.
Eine solche Ausgabeprüfung wäre hier zudem fehleranfällig (Formatierung, Rundung, Zeilenumbrüche) und hätte nur begrenzten Mehrwert gegenüber den bereits vorhandenen Logiktests.

Die für die Endausgabe verwendeten Statistikwerte werden bereits über die Tests der Berechnungsfunktionen (z. B. "statistics_step_update", "statistics_on_departure", "statistics_on_parked_from_queue") abgesichert.
Daher wird "statistics_print" aktuell über manuelle Sichtprüfung der Terminalausgabe validiert.
