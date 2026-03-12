## Ticket 79 – Review test requirement for "user_input"

Die Funktion "user input" verarbeitet interaktive Konsoleneingaben über "scanf, "printf" und "getchar".
Automatisierte Assert-Tests sind für diese Funktion im aktuellen Projektaufbau nicht sinnvoll, da Benutzereingaben über "stdin" simuliert und Konsolenausgaben abgefangen werden müssten.
Ohne zusätzliche Testinfrastruktur für Input-/Output-Umleitung würde ein solcher Test nicht stabil und nicht einfach umsetzbar sein.
Daher werden aktuell keine direkten Assert-Tests erstellt. 
Die Funktion wird stattdessen manuell über Konsoleneingaben geprüft.
