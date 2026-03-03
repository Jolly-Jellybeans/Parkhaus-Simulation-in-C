## 5 Statistiken



### 1. Parkende Autos

Beschreibt die Anzahl der belegten Stellplätze im Parkhaus.

Diese Kennzahl gibt an, wie viele Fahrzeuge sich zu einem bestimmten Zeitpunkt im Parkhaus befinden. In der Gesamtauswertung wird daraus der Mittelwert über die gesamte Simulationsdauer gebildet. Sie ermöglicht eine direkte Einschätzung der tatsächlichen Nutzung des Parkhauses und stellt eine absolute Betrachtung der Systemauslastung dar.

Darüber hinaus dient diese Größe als Basis für weitere Kennzahlen wie die prozentuale Auslastung. Veränderungen im zeitlichen Verlauf geben Aufschluss über typische Nutzungsmuster und Belastungsphasen innerhalb der Simulation.

Am Ende der Simulation wird der über den gesamten Zeitraum ermittelte Gesamtwert ausgegeben.



### 2. Auslastung

Beschreibt die prozentuale Belegung des Parkhauses relativ zur Gesamtkapazität.

Diese Kennzahl normiert die Anzahl parkender Fahrzeuge auf die vorhandene Stellplatzkapazität und erlaubt dadurch eine vergleichbare Bewertung der Systemauslastung. In der Gesamtauswertung zeigt sie, wie effizient die vorhandene Kapazität genutzt wurde.

Da die Auslastung unabhängig von der absoluten Stellplatzanzahl ist, eignet sie sich besonders für Szenarienvergleiche mit unterschiedlichen Kapazitäten. Sie ermöglicht somit eine objektive Beurteilung der Dimensionierung des Parkhauses.

Am Ende der Simulation wird die über die gesamte Laufzeit berechnete Gesamtauslastung ausgegeben.



### 3. Wartende Fahrzeuge

Gibt die Anzahl der Fahrzeuge an, die sich in der Warteschlange befinden.

Diese Kennzahl macht sichtbar, wie stark die Nachfrage die unmittelbare Parkkapazität übersteigt. Eine dauerhaft hohe Anzahl wartender Fahrzeuge deutet auf eine strukturelle Überlastung hin und zeigt, dass das Parkhaus regelmäßig an seine Kapazitätsgrenze stößt.

Da die Warteschlange unbegrenzt ist, spiegelt diese Größe direkt den Nachfrageüberhang wider. Ein kontinuierliches Anwachsen der Warteschlange weist darauf hin, dass das System langfristig nicht im Gleichgewicht arbeitet.

Am Ende der Simulation wird der über den gesamten Zeitraum berechnete Gesamtwert ausgegeben.



### 4. Parkdauer

Beschreibt die Zeitspanne, die ein Fahrzeug vom Einparken bis zur Ausfahrt im Parkhaus verbringt.

Diese Kennzahl analysiert das Nutzungsverhalten der Fahrzeuge. Eine lange Parkdauer reduziert die Umschlagshäufigkeit der Stellplätze, während eine kurze Parkdauer zu häufigeren Fahrzeugwechseln und höherer Dynamik im System führt. In der Gesamtauswertung wird der Mittelwert aller Parkzeiten betrachtet.

Die Parkdauer beeinflusst maßgeblich die Systemdynamik, da sie bestimmt, wie schnell Stellplätze wieder verfügbar werden. Sie ist somit ein zentraler Faktor für die Kapazitätsauslastung und das Entstehen von Warteschlangen.

Am Ende der Simulation wird die über alle Fahrzeuge berechnete Gesamtauswertung ausgegeben.



### 5. Wartedauer

Gibt die Zeitspanne an, die ein Fahrzeug in der Warteschlange verbringt, bevor es einen Parkplatz erhält.

Diese Kennzahl bewertet die Servicequalität des Systems aus Nutzersicht. Während die Anzahl wartender Fahrzeuge die Systembelastung beschreibt, zeigt die Wartedauer die individuelle Verzögerung einzelner Fahrzeuge. Hohe Werte weisen auf deutliche Engpässe und eine starke Auslastung hin.

Die Wartedauer ist besonders relevant für die Bewertung der Nutzerzufriedenheit, da lange Wartezeiten die Akzeptanz des Systems negativ beeinflussen können. Sie ergänzt somit die rein systemorientierten Kennzahlen um eine qualitative Betrachtung.

Am Ende der Simulation wird die über alle wartenden Fahrzeuge berechnete Gesamtauswertung ausgegeben.