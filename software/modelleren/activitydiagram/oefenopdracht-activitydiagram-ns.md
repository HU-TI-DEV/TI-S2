# Oefenopdracht Activitydiagram NS

Het vereiste inleverformat van deze opdracht (evenals de overige) is
hier te vinden: [Inleverformat ](../inleverformat-voor-modelleeropdrachten.md).

Jackpot! De NS wil een nieuwe trein laten bouwen en de keus is op jou
gevallen om daar de software voor te ontwerpen!

A)  Trein besturen
-   Maak een activity diagram voor de use case: Trein besturen.   
    Samenvatting van die usecase: De machinist kan de trein in beweging
    brengen. Daarbij wordt gecheckt of zich niets voor de trein op het
    spoor bevindt, of het sein voor het betreffende spoordeel niet op
    rood staat en of de deuren al gesloten zijn. Uitzondering: tijdens
    het rijden kan door verschillende bronnen (detectie van obstakels
    voor de trein, trekken aan een noodrem, rood sein) veroorzaakt
    worden dat de trein een noodstop moet maken.

**PS: Checklist/Tips bij Activity Diagrammen:**
-   **Als** je een **activiteit wilt onderbreken** met iets, dan is een
    elegante oplossing: stop de activiteit in een
    “**interruptable activity region**”, samen met een **event** waarop
    gewacht wordt. Verlaat de region via dat even.
-   Als je op iets **wacht**, doe dat in de regel met een **event** (ipv
    een guard).
-   Als je een directe beslissing neemt zonder op iets te wachten,
    gebruik dan een **guard**.
-   Bij **decision nodes** kun je events gebruiken **of** guards,
    maar **niet beide** gemixt.
-   Een **activity** kan een eenvoudige **action** zijn **of** een
    compleet (**ander**) activity-diagram.
-   Dat laatste gebeurt o.a. bij **included of extended sub-use cases**.

B)  Bonus Opdracht
-   Maak nog een activitydiagram, gebaseerd op een voor de trein (of het
    centrale spoorcontrolestation) relevante en enigszins complexe use
    case.
