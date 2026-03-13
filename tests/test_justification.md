## Ticket 79 – Review test requirement for "user_input"

Die Funktion "user input" verarbeitet interaktive Konsoleneingaben über "scanf, "printf" und "getchar".
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da Benutzereingaben über "stdin" simuliert und Konsolenausgaben abgefangen werden müssten.
Ohne zusätzliche Testinfrastruktur für Input-/Output-Umleitung würde ein solcher Test nicht stabil und nicht einfach umsetzbar sein.
Daher werden aktuell keine direkten Assert-Tests erstellt. 
Die Funktion wird stattdessen manuell über Konsoleneingaben geprüft.


## Ticket 80 – Review test requirement for "node_destroy"

Die Funktion "node_destroy" gibt den reservierten Speicherplatz eines einzelnen Warteschlangenknotens über die C-Standardfunktion "free" an das Betriebssystem zurück.
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da ein anschließender Lesezugriff zur Überprüfung des gelöschten Speichers nach C-Standard zu undefiniertem Verhalten bzw. einem Programmabsturz führen würde.