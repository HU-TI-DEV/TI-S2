# Python op VSCode

Om Python te gebruiken met Visual Studio Code (VSCode) op Windows, volg je deze stappen:

1. **Installeer Python**: Als je Python nog niet op je systeem hebt geïnstalleerd, download en installeer dan Python vanaf de officiële website: [Python Downloads](https://www.python.org/downloads/). Tijdens de installatie kun je ervoor kiezen om Python toe te voegen aan het systeem-PATH, wat handig is om Python-opdrachten vanaf de opdrachtprompt/terminal te gebruiken.

2. **Installeer Visual Studio Code**: Als je Visual Studio Code nog niet hebt geïnstalleerd, download en installeer het dan vanaf de officiële website: [Visual Studio Code](https://code.visualstudio.com/).

3. **Installeer de Python-extensie**: Open Visual Studio Code en ga naar het tabblad "Extensions" (of druk op `Ctrl+Shift+X`). Zoek naar "Python" in de extensiebibliotheek en installeer de officiële Python-extensie van Microsoft.

4. **Open een map of start een nieuw project**: Open Visual Studio Code en open de map waarin je wilt werken of maak een nieuw project.

5. **Maak een nieuw Python-bestand**: Klik op het pictogram voor het maken van een nieuw bestand (of druk op `Ctrl+N`) en sla het op met de extensie ".py", bijvoorbeeld "mijn_programma.py".

6. **Schrijf je Python-code**: Typ je Python-code in het nieuwe bestand.

7. **Selecteer de Python-interpreter**: Als je meerdere Python-versies op je systeem hebt geïnstalleerd, moet je mogelijk de Python-interpreter selecteren die je wilt gebruiken. Klik hiervoor op de onderste statusbalk van VSCode waar "Selecteer de Python-interpreter" staat geschreven en kies de gewenste interpreter.

8. **Voer je Python-programma uit**: Je kunt je Python-programma direct vanuit VSCode uitvoeren. Klik op de groene knop "Run" bovenaan het bestand, of gebruik de sneltoets `Ctrl+Shift+P` en typ "Python: Run Python File in Terminal".

## Pippen

Meestal heb je voor je python project ook andere libraries nodig.
Een manier om dat te beheren is:

- ga in de command-line (ik gebruik Git Bash als commandline) naar de folder van je python project.

- type daar: 
  virtualenv venv
  Dat maakt een folder met de naam venv (afkorting voor virtual environment) aan.
  (soms staat virtualenv nog niet in je pad. als dat niet het geval is, is het handig om dat meteen even te doen. bij mij stond het hier:    C:\Users\mariu\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.12_qbz5n2kfra8p0\LocalCache\local-packages\Python312\Scripts)

- Activeer je venv met 
  source ./myvenv/Scripts/activate

- Aan de prompt kun je zien dat de virtual environment nu geactiveerd is.
  Je kunt nu libraries toevoegen met pip. Voorbeeld:
  pip install matplotlib

- Je kunt ook na activeren van je venv visual code opstarten met:
  code . &
  Dan start het in de juiste project folder en gebruikt het de zojuist geactiveerde venv.
