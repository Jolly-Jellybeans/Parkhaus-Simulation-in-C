# Projektdokumentation – Begründungen

## Warum gab es wenig Diskussionen auf GitHub bzw. hauptsächlich in Pull Requests?

Da zwei Teammitglieder in einer gemeinsamen Wohnung leben und das dritte Teammitglied ebenfalls in unmittelbarer Nähe wohnt, fand ein Großteil des fachlichen Austauschs persönlich statt. Wir haben uns regelmäßig getroffen und zentrale Entscheidungen direkt besprochen. 

Der grundlegende Systementwurf – inklusive Modulstruktur, Funktionsumfang und Aufgabenverteilung – wurde bereits beim ersten Treffen gemeinsam erarbeitet. Die konkrete technische Umsetzung einzelner Komponenten wurde anschließend von Bennet übernommen. 

Dadurch wirkt es in der Commit-Historie teilweise so, als seien Funktionsprototypen „aus dem Nichts“ entstanden. Tatsächlich basieren diese jedoch auf zuvor gemeinsam definierten Konzepten. 

Auch die unterschiedliche Anzahl an Commits erklärt sich daraus: Der Arbeitsumfang war pro Person vergleichbar, jedoch unterscheiden sich Anzahl der Codezeilen und Commits, da nicht jede konzeptionelle Entscheidung unmittelbar in mehreren kleinen Commits sichtbar wird.

---

## Warum nutzten wir `static`-Funktionen?

<!--
Urspruengliche Entscheidung (Teil 1):
In unserem Projekt wurden static-Funktionen bewusst eingesetzt, um interne Hilfsfunktionen
klar von der oeffentlichen Schnittstelle eines Moduls zu trennen.
Dadurch waere die Sichtbarkeit auf die jeweilige .c-Datei beschraenkt gewesen
(bessere Kapselung, weniger Namenskonflikte, keine externen Zugriffe).
-->

Im zweiten Teil des Projekts haben wir diese Entscheidung bewusst angepasst und die `static`-Deklarationen entfernt.

Grund dafuer war die Testanforderung, fuer die relevanten Funktionen gezielte Assert-Tests zu schreiben.  
Durch `static` waeren diese Funktionen nur innerhalb derselben `.c`-Datei sichtbar gewesen und nicht sauber von den Testdateien aus pruefbar.

Deshalb wurden die betroffenen Funktionen als normale (nicht-`static`) Funktionen gefuehrt, damit sie direkt getestet und im Testkontext eindeutig aufgerufen werden koennen.

Damit priorisieren wir in diesem Projektabschnitt bewusst die Testbarkeit und Nachweisbarkeit der geforderten Funktionen.

---

## Warum haben wir diese Modularisierung gewählt?

Die Modularisierung wurde gezielt gewählt, um das Parkhaus-Projekt strukturiert, wartbar und klar getrennt umzusetzen. 

Die Aufteilung in logisch abgegrenzte Module – Parkhauslogik, Warteschlange, Fahrzeugverwaltung, Statistik sowie I/O – sorgt dafür, dass jede Komponente eine eindeutig definierte Verantwortung übernimmt. 

Die fachliche Logik ist vollständig von Ein- und Ausgaben getrennt. Während das I/O-Modul sämtliche Benutzereingaben und Ausgaben bündelt, konzentrieren sich die anderen Module ausschließlich auf die Systemlogik. 

Diese Trennung reduziert Abhängigkeiten und verhindert eine Vermischung von Verantwortlichkeiten. Änderungen an der Benutzeroberfläche beeinflussen somit nicht direkt die Kernlogik und umgekehrt. 

Die gewählte Struktur erleichtert außerdem:
- gezieltes Testen einzelner Module  
- spätere Erweiterungen  
- bessere Nachvollziehbarkeit im Team  

Insgesamt erhöht die Modularisierung Stabilität, Verständlichkeit und langfristige Wartbarkeit des Projekts.

---

## Warum haben wir genau diese Funktionen gewählt?

Die Funktionsauswahl folgt einer konsequenten Modultrennung. Jedes Modul kapselt einen klar abgegrenzten Verantwortungsbereich und stellt ausschließlich die dafür notwendigen Schnittstellen bereit.

### I/O-Modul  
(`print_menu`, `read_menu_choice`, `print_parking_garage_status`, `print_result_message`)

Alle Funktionen zur Benutzerinteraktion sind hier gebündelt. Dadurch bleibt die Kernlogik vollständig unabhängig von Ein- und Ausgaben.  
Änderungen am Menü oder Ausgabeformat haben keinen Einfluss auf die Simulation selbst.  
Gleichzeitig wird die Testbarkeit erhöht, da Logik unabhängig von Konsolenein- oder -ausgaben geprüft werden kann.

### Queue-Modul  
(`queue_create`, `queue_destroy`, `queue_enqueue`, `queue_dequeue`, `queue_is_empty`)

Die Warteschlangenlogik ist als eigenständige Datenstruktur implementiert.  
Da das Warten ein separater Prozess innerhalb der Simulation ist, wurde es bewusst nicht in die Parkhauslogik integriert.  

Die FIFO-Struktur bildet reale Abläufe korrekt ab und kann unabhängig getestet oder bei Bedarf ausgetauscht werden.  
Dies verbessert Wiederverwendbarkeit und klare Verantwortungsabgrenzung.

### ParkingGarage-Modul  
(`parking_garage_create`, `parking_garage_destroy`, `parking_garage_park`, `parking_garage_remove_departing`)

Dieses Modul enthält die zentrale Systemlogik. Hier werden Stellplätze verwaltet, Fahrzeuge eingeparkt und Abfahrten verarbeitet.  

Die klare Trennung in definierte Operationen (Erzeugen, Zerstören, Parken, Entfernen) ermöglicht eine kontrollierte Zustandsverwaltung.  
Alle Änderungen am Parkhaus erfolgen ausschließlich über definierte Schnittstellen.

### Statistics-Modul  

Das Statistics-Modul bündelt alle Auswertungsfunktionen. Es unterscheidet bewusst zwischen:

- Initialisierung
- Ereignisbasierten Updates (z. B. Warteschlangenaufnahme oder Abfahrt)
- Zeitbasierten Schrittaktualisierungen
- Schrittweiser Ausgabe
- Gesamtauswertung am Ende

Diese Differenzierung ermöglicht sowohl eine Live-Analyse während der Simulation als auch eine fundierte Gesamtbewertung nach Abschluss.  

Insgesamt stellt die Funktionsstruktur sicher, dass jede Komponente logisch abgegrenzt, klar definiert und erweiterbar bleibt.

---

## Warum wurden genau diese Statistiken gewählt?

Die gewählten Kennzahlen ermöglichen eine ganzheitliche Bewertung der Simulation aus technischer, wirtschaftlicher und nutzerbezogener Perspektive.

Die Anzahl parkender Fahrzeuge bildet die unmittelbare Grundlage zur Bewertung der tatsächlichen Nutzung.  
Sie erlaubt Aussagen über Einnahmepotenzial und Auslastungssituation.

Die Auslastung setzt diese Werte ins Verhältnis zur Gesamtkapazität und ermöglicht eine objektive Bewertung der Dimensionierung.  
Dadurch lassen sich Szenarien vergleichen und mögliche Erweiterungen abschätzen.

Die Anzahl wartender Fahrzeuge zeigt, wann die Nachfrage die verfügbare Kapazität übersteigt.  
Sie liefert konkrete Hinweise auf Unterdimensionierung und potenziellen Erweiterungsbedarf.

Die Parkdauer analysiert das Nutzungsverhalten und beeinflusst die Dynamik der Stellplatzverfügbarkeit.  
Sie eröffnet zudem wirtschaftliche Strategien wie Kurzzeit- oder Langzeittarife.

Die Wartedauer bewertet die Servicequalität.  
Sie spiegelt die Nutzerzufriedenheit wider und hilft abzuschätzen, ob Wartezeiten akzeptabel sind oder potenziell zur Abwanderung führen.

Gemeinsam ermöglichen diese Kennzahlen eine ausgewogene Bewertung von Effizienz, Wirtschaftlichkeit und Attraktivität des Systems.

---

## Warum ist unser Ausgabeformat so gestaltet?

Das Ausgabeformat wurde bewusst tabellarisch und klar strukturiert gewählt, um eine übersichtliche Darstellung im Terminal zu gewährleisten.

Die feste Spaltenstruktur mit Bezeichnung, Wert und Einheit ermöglicht eine konsistente und leicht vergleichbare Darstellung der Kennzahlen – sowohl zwischen einzelnen Zeitschritten als auch in der Gesamtauswertung.

Eine grafische Darstellung wurde zunächst in Betracht gezogen. Diese hätte jedoch zusätzliche Extensions oder externe Programme erfordert und wäre nicht plattformunabhängig gewesen.  

Um eine ohne Zusatzsoftware lauffähige Lösung sicherzustellen, fiel die Entscheidung bewusst zugunsten einer strukturierten Terminalausgabe.

Zusätzlich wurde über eine visuelle Aufwertung mittels ASCII-Darstellungen (z. B. Balken oder einfache Diagramme) nachgedacht. Ob diese Erweiterung final umgesetzt wird, bleibt projektintern zu entscheiden.

Das gewählte Format bietet jedoch bereits eine stabile, reproduzierbare und technisch saubere Lösung ohne zusätzliche Abhängigkeiten.