![logo](../Flask/img/Flask_logo.svg) [](logo-id)

# Flask[](title-id)

### Inhoud[](toc-id)

- [Flask](#flask)
    - [Inhoud](#inhoud)
    - [Inleiding](#inleiding)
  - [Een eenvoudige applicatie](#een-eenvoudige-applicatie)
  - [Docker image](#docker-image)
  - [Flask voorbeeld](#flask-voorbeeld)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor Flask door HU IICT[](author-id).

---

### Inleiding

Flask is een webapplicatie-frameworks. Het voldoet aand Web Server Gateway Interface ([WSGI](https://wsgi.readthedocs.io/en/latest/)), voor de communicatie tussen webservers en webapplicatie-frameworks. Zo kan je met Python ook webapplicaties ontwikkelen.

## Een eenvoudige applicatie

Maak gebruik van Virtual Environment ([venv](../../../hardware-interfacing/communicatie/UART/README.md)) voor je Python ontwikkeling.

```bash
mkdir flaskApp
cd flaskApp
python -m venv venv
source ./venv/bin/activate
```

Nu kan je flask installeren en je eerste Python Flask applicatie maken.
```bash
(venv)$ pip install flask
(venv)$ pip install wheel
(venv)$ pip freeze > requirements.txt
(venv)$ sudo nano flaskApp.py
```

Maak een 'Hello World' serverapplicatie in Flask.
```python
#flaskApp.py
from flask import Flask
app = Flask(__name__)

@app.route("/")
def index():
    return "<h1>Hello World</h1>"

if __name__ == "__main__":
    app.run(host='0.0.0.0', port='5000')
```

Controleer of je applicatie werkt.
```bash
(venv)$ python flaskApp.py 
```

Als het goed is heb je nu een eerste applicatie gemaakt. Navigeer met je browser naar http://< your hostname or ip >:5000

Als alles werkt kunnen we de venv verlaten met `deactivate`.

## Docker image

Maak een [Docker](../../../infrastructuur/Docker/README.md) image aan voor je applicatie. Voeg onderstaand toe aan een Dockerfile een bestand met de naam `Dockerfile` zonder extensie (gebruik nano of vi om het bestand te maken).
```bash
FROM python:3.9.2
WORKDIR /code
COPY requirements.txt /code
RUN pip install -r requirements.txt --no-cache-dir
COPY . /code
CMD python flaskApp.py
```

Maak een Docker image.
```bash
docker build -t flaskapp . 
```

Voer je Flask applicatie uit als een Docker container

```bash
sudo docker run --name flaskapp -d --restart unless-stopped -p 5000:5000 flaskapp
```

## Flask voorbeeld

```python
#Import Raspberry Pi GPIO library
import RPi.GPIO as GPIO 
#Import Flask
from flask import Flask, render_template
app = Flask(__name__)

#Ignore warnings
GPIO.setwarnings(False)
#Use physical pin numbering
GPIO.setmode(GPIO.BOARD)
#Pin 10 as input
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) 

@app.route("/")
def index():
	# Read Sensors Status
	button = GPIO.input(10)
	templateData = {
      'title' : 'GPIO input',
      'button'  : button
      }
	return render_template('index.html', **templateData)
if __name__ == "__main__":
   app.run(host='0.0.0.0', port=80, debug=True)
```

## Referenties
- Flask (<https://flask.palletsprojects.com/en/3.0.x/>)
- Flask logo (<https://commons.wikimedia.org/wiki/File:Flask_logo.svg>)