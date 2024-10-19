![logo](../Docker/img/Docker_(container_engine)_logo.svg) [](logo-id)

# Docker[](title-id)

### Inhoud[](toc-id)

- [Docker](#docker)
    - [Inhoud](#inhoud)
    - [Inleiding](#inleiding)
    - [Installeer Docker](#installeer-docker)
    - [Docker parameters](#docker-parameters)
    - [Docker commands](#docker-commands)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor Docker en installatie instructies door HU IICT[](author-id).

---

### Inleiding

Docker is a tool for creating, deploying, and running applications in containers. The software is popular among developers as it speeds up the development process and does not use a lot of resources. With docker you can automate the deployment of applications in lightweight containers. Multiple applications can run in an isolated environement. 

With Docker you can compartmentalise an individual application based on their dependencies, but allow them to still “share” libraries with other applications without duplicating them. All the applications will share the same host Operating System (OS), without the extra layer of a guest OS that is present in the virtual machine set-up.

### Installeer Docker

[Update je systeem](../OS/Raspberry-Pi-OS/README.md) en installeer dan Docker met behulp van een shell script.

```bash
curl -sSL https://get.docker.com | sh
```

### Docker parameters

Je kunt een docker opstarten met verschillende parameters. Onderstaand een voorbeeld van een opstart-configuratie van een Docker voor een PostgreSQL database.

Voorbeeld:
```bash
sudo docker run --name postgres -d --restart unless-stopped -p 5432:5432 -e POSTGRES_PASSWORD=123456 -v ${PWD}/data:/var/lib/postgresql/data postgres:16
```

- **--name postgres** De naam van je container.
- **-d** Uitvoeren op de achtergrond (demonized).
- **--restart unless-stopped** Opstarten na een reboot.
- **-p** De TCP poort voor ***clients*** om mee te verbinden.
- **-e** Wachtwoord voor de postgres admin account.
- **-v ${PWD}/data:...** Mount data-directory.
- **postgres:16** De versie van Postgress die we willen starten.

### Docker commands

Controleer het logbestand.
```bash
docker logs postgres
```

Laat de actieve containers zien.
```bash
docker ps
```

Verwijder een container
```bash
docker remove <container>
```

## Referenties
- Docker (<https://en.wikipedia.org/wiki/Docker_(software)>)