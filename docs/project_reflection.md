# Projektreflexion 

## 1. Wie haben Sie die Aufgabenstellung gelöst?

Zu Beginn des Projekts wurde zunächst die Problemstellung analysiert und in einzelne Teilbereiche zerlegt. Dabei orientierten wir uns an grundlegenden Prinzipien der Softwareentwicklung und der strukturierten Programmierung. Als Vorlage dienten selbstverständlich die Skripte der Vorlesung sowie die dort vermittelten Inhalte. Ein zentraler Schritt bestand darin, das Gesamtsystem in mehrere logisch getrennten Module zu unterteilen (Modularisierung). Dadurch konnte der Code übersichtlich gehalten und die einzelnen Funktionen klar voneinander abgegrenzt werden. Dies erleichterte gleichzeitig auch die Aufgabenverteilung im Team.
 
Das System besteht aus mehreren zentralen Komponenten sowie verschiedenen Strukturen, die während der Simulation wichtige Daten aufnehmen und verarbeiten.
 
Ein zentraler Bestandteil ist das Parkhaus selbst. Das Parkhaus verwaltet eine feste Anzahl an Stellplätzen, die während der Simulation entweder belegt oder frei sein können. Jeder Stellplatz enthält Informationen darüber, ob er aktuell belegt ist und welches Fahrzeug dort parkt.
 
Zusätzlich wurde eine Warteschlange implementiert, um Fahrzeuge zu verwalten, die nicht sofort einen freien Parkplatz erhalten. Sobald das Parkhaus vollständig belegt ist, werden neu ankommende Fahrzeuge in diese Warteschlange eingefügt. Die Warteschlange folgt dem FIFO-Prinzip (First In – First Out), was bedeutet, dass Fahrzeuge in der Reihenfolge abgearbeitet werden, in der sie angekommen sind. Diese Struktur entspricht auch dem realistischen Verhalten einer Warteschlange an einer Parkhauseinfahrt.
 
Die Simulation selbst läuft über eine definierte Anzahl von Zeitschritten. In jedem Zeitschritt werden mehrere Prozesse ausgeführt. Zunächst wird geprüft, ob neue Fahrzeuge ankommen. Anschließend werden Fahrzeuge entfernt, deren Parkdauer abgelaufen ist. Danach wird überprüft, ob Fahrzeuge aus der Warteschlange auf frei gewordene Stellplätze nachrücken können. Dieser Ablauf wird so lange wiederholt, bis alle Simulationsschritte abgearbeitet wurden.
 
Während der Simulation werden außerdem verschiedene statistische Werte erfasst. Diese Statistiken dienen dazu, das Verhalten und die Auslastung des Parkhauses über den gesamten Simulationszeitraum hinweg zu analysieren. Am Ende der Simulation werden diese Daten zusammengefasst und ausgegeben.
 
Ein weiterer wichtiger Bestandteil des Projekts war die Nutzung eines Versionsverwaltungssystems. Für die Zusammenarbeit im Team wurde Git in Kombination mit GitHub verwendet. Änderungen am Code wurden in Form von Commits dokumentiert und über Branches organisiert. Neue Funktionen wurden in separaten Branches entwickelt und anschließend über Pull Requests in den Hauptbranch integriert. Dieses Vorgehen hat dazu beigetragen, den Überblick über Änderungen zu behalten und mögliche Fehler frühzeitig zu erkennen.
 
Sehr wichtig war für uns außerdem der direkte und häufige Austausch – entweder in Präsenz oder über Microsoft Teams, wodurch auftretende Probleme meist schnell gelöst werden konnten. Dabei wurden stets alle Teammitglieder einbezogen, sodass niemand vernachlässigt wurde und alle gleichermaßen zum Projekterfolg beitragen konnten.

## 2. Welche anderen Optionen hatten Sie im Team hinsichtlich der Struktur oder Umsetzung diskutiert?

Während der Planungsphase wurden im Team verschiedene mögliche Ansätze zur Umsetzung des Projekts diskutiert. Dabei ging es insbesondere um die Struktur des Programms, die Wahl geeigneter Datenstrukturen sowie die Organisation der einzelnen Module.
 
Eine erste Überlegung betraf die Modularisierung der Dateien. Die Anzahl und konkrete Aufteilung der Dateien war dabei ein Diskussionspunkt. Hier waren wir uns zunächst nicht einig und mussten einen Kompromiss zwischen einer sehr starken Modularisierung mit vielen Dateien und einer Lösung mit möglichst wenigen Dateien finden. Es gab Vorschläge und Überlegungen, die von drei bis hin zu etwa fünfzehn C- beziehungsweise Header-Dateien reichten.
 
Eine weitere ausführliche Diskussion entstand im Zusammenhang mit der Umsetzung und Darstellung der Statistiken. Dabei gab es unterschiedliche Vorstellungen darüber, wie die Ergebnisse visualisiert werden sollten. Ein Vorschlag war, die Statistiken mithilfe einer Extension grafisch darzustellen. Dem gegenüber stand jedoch der Einwand, dass eine solche Lösung möglicherweise zu komplex und unübersichtlich für den Rahmen des Projekts sein könnte. Eine andere Idee war daher eine ausschließlich textuelle Ausgabe. Der letztendliche Kompromiss bestand darin, eine Visualisierung direkt in der Konsole mithilfe von ASCII-Zeichen umzusetzen. Dadurch konnten beide Ansätze teilweise berücksichtigt werden.
 
Solche Diskussionen fanden entweder in Präsenz oder über Microsoft Teams statt und konnten teilweise sehr lange dauern, bis sich eine gemeinsame Lösung durchsetzen konnte.
 
Auch die Frage der Korrektheit und Sorgfalt im Code wurde intensiv diskutiert. Beispielsweise ging es darum, ob jeder Pointer grundsätzlich zunächst auf `NULL` überprüft werden sollte und ob Eingabewerte des Benutzers vor der Weiterverarbeitung validiert werden müssen. Solche alternativen Vorgehensweisen wurden im Team ausführlich besprochen und anschließend anhand der jeweiligen Argumente gegeneinander abgewogen.
 
In den Kommentaren der Pull Requests lässt sich außerdem erkennen, dass auch die Organisation der Tests Gegenstand einer Diskussion war. Es gab beispielsweise den Vorschlag, alle Tests in einer einzigen Datei zu bündeln, anstatt diese entsprechend der einzelnen Module beziehungsweise Header- und C-Dateien zu strukturieren.

## 3. Warum haben Sie sich gegen die anderen Optionen entschieden bzw. für die gewählte Variante gemeinsam entschieden?

## 4. Gab es Schwierigkeiten oder Herausforderungen bei der Zusammenarbeit?

## 5. Was ist Ihnen im Team einfach gefallen bzw. sehr gut gelungen?
