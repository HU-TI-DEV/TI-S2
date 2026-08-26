# Scripts
Deze folder bevat een aantal scripts die tooling bieden voor het integreren van git (GitHub) en Canvas. In dit bestand volgt enige uitleg over het gebruik en de opzet van deze scripts.

## Kopiëren data van git naar Canvas

Opzet:
1. Zorg dat in [metadata.json](metadata.json) de informatie juist staat ingesteld;
   - courseID: de cursus code van de betreffende cursus op Canvas
   - githubRepoURL: de link naar de bijbehorende github repo
2. Zorg dat je [uv](https://docs.astral.sh/uv/getting-started/installation/) hebt geïnstalleerd voor de virtual environment
3. Zorg dat de opdrachten op Canvas dezelfde naam hebben als in Git
4. Zorg dat de opdrachten op Git het [template](../templates/t-opdracht.md) volgen
5. Zorg dat je, via onderstaande stappen, een Canvas API key beschikbaar hebt 

<details>
<summary> Genereren en opslaan van een Canvas API key </summary>

<br>

**Genereren Canvas API key:**
1. Ga naar canvas.hu.nl en log in
2. Klik links bovenin op je account
3. Ga naar instellingen
4. Scroll naar beneden en klik op de blauwe knop met '+ Nieuw toegangstoken'
5. Geef je toegangstoken een duidelijke naam (bijvoorbeeld CanvasGitIntegratie) en stel de vervaldatum in
   - Na de vervaldatum zul je je token moeten vervangen
6. Genereer je token. **LET OP** Dit is het enige moment dat je je token te zien gaat krijgen, dus kopiëer deze!

Token opslaan:
1. Maak een kopie van het .env_EXAMPLE bestand uit de folder /scripts/ en hernoem naar .env
2. Overschrijf in de .env file de waarde van de variabele CANVAS_API_TOKEN met je gegenereerde token
3. Sla op

N.B. .env staat in de .gitignore en zal dus niet getracked worden door git

------------------------------------------------------------

</details>


Uitvoeren:
1. Als je uv hebt geïnstalleerd kun je vanaf de command line met `uv run copyExaminationInfo.py` het script starten
2. uv zal nu een virtual environment creëren en indien nodig hierbinnen de juiste Python versie installeren en de benodigde externe modules installeren
3. Het script voert nu de volgende stappen uit:
   1. Het inladen van de metadata
   2. Het creëren van een Canvas API object
   3. Het ophalen van de lijst van opdrachten
   4. Het printen van de lijst van opdrachten
4. Kies vanuit het gegeven menu de opdracht die je wilt updaten
5. Het script voert nu de volgende stappen uit:
   1. Het genereren van een Canvas Assignment object voor de gekozen opdracht
   2. Het vinden van de bijbehorende markdown file in de **lokale** git repo
   3. Het extraheren van de toetsingsinformatie (alles onder ## Opleveren)
   4. Het 'preprocessen' van de markdown text (verwijderen van commentaar)
   5. Het genereren van de link naar de opdracht op GitHub
   6. Het combineren van de link en de toetsingsinformatie
   7. Het vertalen van de markdown text naar HTML
6. Het script zal nu het Canvas Assignment object updaten met de vertaalde HTML beschrijving

<details>
<summary><h3> Uitleg scripts </h3></summary>

### metadataLoader\.py
Dit script (grotendeels door AI gegenereerd) biedt een interface om de metadata.json uit te lezen om te achterhalen vanuit welke git repo scripts worden gerund en bij welke Canvas cursus de repo hoort.

### canvasIntegration\.py
Dit script biedt een wrapper om de Python implementatie van de Canvas API aan voor veilige interactie met Canvas. Het is **niet** de bedoeling om dit script direct aan te roepen, maar het bevat wel een 'main' om te controleren of de connectie met Canvas goed werkt. 


##### Benodigdheden
Om gebruik te kunnen maken van de functies in dit script dient de gebruiker een Canvas API token in de environment variables geplaatst te hebben. 
<details> 
<summary> Informatie over het genereren van een Canvas API token 
</summary>

Informatie over het genereren van een API token vind je [hier](https://community.instructure.com/en/kb/articles/662901-how-do-i-manage-api-access-tokens-in-my-user-account). 
**Let op**: een Canvas API token is persoonlijk, maar kan wel door iedereen gebruikt worden. Een API token biedt alle mogelijkheden (en meer) van een gebruikersaccount. Bewaar deze dus veilig, en gebruik altijd een environment loader om de API key op te halen. Plaats deze niet in plaintext in code.
</details>
<br>

Daarnaast is het nodig om de `canvasapi` module te installeren, bijvoorbeeld met `pip install canvasapi`. Voor meer informatie over de Python implementatie van de Canvas API kun je de [documentatie bekijken](https://canvasapi.readthedocs.io/en/stable/).

##### Functies
Dit script biedt functies voor het maken van een Canvas API object waarmee het ophalen van een lijst van alle Assignments binnen een cursus, het ophalen van de deadline van een Assignment, en het updaten van de beschrijving van een Assignment mogelijk wordt. Andere velden van een Assignment kunnen door gebruik van dit script (momenteel) niet aangepast worden.

### githubIntegration\.py
Dit script maakt momenteel niet écht gebruik van GitHub, maar werkt vanuit de lokale repo van waaruit het script wordt aangeroepen. Het is **niet** de bedoeling om dit script direct uit te voeren, maar het biedt wel een 'main' om te testen of het ophalen van de informatie en het vertalen naar een HTML format werkt. Dit maakt nu wel gebruik van een hard-coded opdracht.

##### Benodigdheden
Voor het vertalen van de Markdown naar HTML wordt gebruik gemaakt van [markdown-it](https://pypi.org/project/markdown-it-py/), te installeren met `pip install markdown-it-py`.

##### Functies
De functie `getExaminationInfo(opdrachtnaam: str)` geeft in HTML format de toetsingsinformatie terug van de meegegeven opdracht. Bovenaan de toetsingsinformatie komt ook de link naar de bijbehorende GitHub URL te staan, zodat de output klaar is om naar Canvas geschreven te worden.

Deze functie maakt gebruik van de `extractExaminationInfo` functie, welke het juiste bestand vindt (met de `findMarkdownFile` functie), hier enkel de toetsingsinformatie uit filtert (alles onder `## Opleveren`), dit d.m.v. `preprocessMarkdown` voorbewerkt voor het verwijderen van comments, de GitHub URL herconstrueert met `getGithubURL` en deze boven de toetsingsinformatie plakt.

Uiteindelijk vertaalt translateToHTML de Markdown output van `extractExaminationInfo` naar HTML in het format dat verwacht wordt door Canvas.

Call tree:
- getExaminationInfo
  - extractExaminationInfo
    - findMarkdownFile
    - preprocessMarkdown
    - getGithubURL
  - translateToHTML

### copyExaminationInfo\.py
Het script copyExaminationInfo.py is opgezet om bovenstaande scripts te combineren om op die manier informatie vanuit de git repo naar Canvas te kopiëren. 

</details>