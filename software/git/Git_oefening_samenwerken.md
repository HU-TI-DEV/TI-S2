# GitLab Groepsproject Oefening

## Oefening: Werken met Git in een team

### Doel
Leer om effectief samen te werken aan jullie groeps-repository via de command line, inclusief het maken van branches, commit messages schrijven, pull requests (merge requests) indienen, en het oplossen van merge conflicts. 

### Vereisten
- Een bestaande groeps repository op Gitlab waar alle teamleden toegang toe hebben.
- Git geïnstalleerd op elke computer.

### Situatie
Jullie werken gezamenlijk aan een simpele To-Do List applicatie geschreven in Python. De repository bevat één bestand: [todo.py](./todo.py), met basisfunctionaliteit voor het weergeven van een lijst.

### Stappen

#### 1. Clone de Repository (Iedereen)

Als het goed is heb je deze stap al gedaan van zowel de groeps repository als je prive repository!
```bash
$ git clone <REPOSITORY_URL>
$ cd <REPOSITORY_FOLDER>
```

#### 2. Maak een nieuwe Branch (Iedereen)
Elke deelnemer maakt een eigen branch om een nieuwe functionaliteit toe te voegen.

```bash
$ git checkout -b <branch-naam>  
```
Voorbeeld:
```bash
$ git checkout -b add-task-feature
```

#### 3. Voeg Functionaliteit Toe (Iedereen)

Voeg in `todo.py` een functie toe in de branch waar je aan werkt. Bijvoorbeeld:
```python
# In todo.py

tasks = []

def add_task(task):
    tasks.append(task)
    print(f'Task toegevoegd: {task}')
```

#### 4. Commit je wijzigingen (Iedereen)
```bash
$ git add .
$ git commit -m "Voeg functie toe om taken toe te voegen"
```

#### 5. Push de Branch naar GitLab (Iedereen)
```bash
$ git push -u origin <branch-naam>
```

#### 6. Maak een Merge Request (Iedereen)
Maak een Merge Request aan via de GitLab interface en wijs één van je teamleden toe als reviewer.

#### 7. Review en Merge (Reviewer)
- Review de code via GitLab.
- Geef feedback indien nodig.
- Merge de branch naar `main` als alles goed is.

#### 8. Conflict Simulatie (Team)
Laten we nu een conflict genereren! Twee deelnemers moeten de **zelfde regel code wijzigen** in hun eigen branches en proberen deze naar `main` te mergen. Dit leidt tot een conflict.

#### 9. Merge Conflict Oplossen (Iedereen)

- Pull de nieuwste `main` naar je lokale branch:
```bash
$ git checkout <branch-naam>
$ git pull origin main
```
- Wanneer er een conflict optreedt, wordt dit aangegeven. Open het conflict in Visual Studio Code:
```bash
$ code .
```
- Los het conflict op en commit de oplossing:
```bash
$ git add .
$ git commit -m "Los merge conflict op"
```
- Push de opgeloste branch naar GitLab:
```bash
$ git push
```

#### 10. Herhaal het Proces (Team)
Blijf samenwerken aan nieuwe functionaliteiten en herhaal de bovenstaande stappen. Zorg dat jullie regelmatig pullen van de `main` branch om conflicts te minimaliseren.

### Evaluatie
Bespreek als team hoe jullie samenwerking is verlopen:
- Hoe vaak kwamen merge conflicts voor?
- Waren de commit messages duidelijk?
- Hoe was de kwaliteit van de reviews?

### Tip
Git commit berichten mogen in het engels.

### Referentie
- ChatGPT-4 was gebruikt om een deel van de opdracht te maken.

