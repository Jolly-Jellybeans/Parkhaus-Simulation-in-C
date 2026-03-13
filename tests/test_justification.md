## Ticket 79 – Review test requirement for "user_input"

Die Funktion "user input" verarbeitet interaktive Konsoleneingaben über "scanf, "printf" und "getchar".
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da Benutzereingaben über "stdin" simuliert und Konsolenausgaben abgefangen werden müssten.
Ohne zusätzliche Testinfrastruktur für Input-/Output-Umleitung würde ein solcher Test nicht stabil und nicht einfach umsetzbar sein.
Daher werden aktuell keine direkten Assert-Tests erstellt. 
Die Funktion wird stattdessen manuell über Konsoleneingaben geprüft.


## Ticket 61 – Review test requirement for "node_destroy"

Die Funktion "node_destroy" gibt den reservierten Speicherplatz eines einzelnen Warteschlangenknotens über die C-Standardfunktion "free" an das Betriebssystem zurück.
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da ein anschließender Lesezugriff zur Überprüfung des gelöschten Speichers nach C-Standard zu undefiniertem Verhalten bzw. einem Programmabsturz führen würde.


## Ticket 77 - Review test requirement for "statistics_print_step"

Die Funktion "statistics_print_step" erzeugt formatierten Konsolen-Output über mehrere "printf"-Aufrufe.
Automatisierte Assert-Tests sind im aktuellen Projektaufbau dafür nicht sinnvoll, da ohne zusätzliche Testinfrastruktur keine robuste Umleitung und Auswertung von "stdout" erfolgt.
Die Prüfung einzelner Zeichenketten wäre dadurch fehleranfällig (z. B. wegen Formatierung, Rundung und Zeilenumbrüchen) und hätte im Vergleich zur Kernlogik nur begrenzten Mehrwert.

Die zugrunde liegende Rechenlogik wird bereits indirekt über die Tests von "statistics_step_update", "statistics_on_departure" und "statistics_on_parked_from_queue" abgedeckt.
Daher wird "statistics_print_step" im aktuellen Stand über manuelle Sichtprüfung der Terminalausgabe validiert.