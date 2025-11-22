# Convenzioni nomi

- **File**: tutto minuscolo, trattini bassi per separare le parole (snake_case)
- **Classi** (e struct): prima lettera di ogni parola con la maiuscola, nessuno spazio, nessun trattino basso (CamelCase)

# Policy adottate

- **Costruttori classe Misura: tutti i valori non forniti vengono assunti nulli. Se forniti valori extra, si verifica un errore.

# Attività individuali

Giulia B.
- Check e condivisione teoria, supporto (iniziali problemi tecnici)
- Implementati operatori di accesso per lettura e scrittura (misura.cpp)
- Implementata funzione clear_buffer
- Costruttore di default di inertial_driver

🗝️☁️
- Aggiunto MyVector dal lab04
- Improntata classe InertialDriver
- Improntato main (verificato che includesse)
- Interfaccia pubblica di InertialDriver (nel .h)
- Completata interfaccia (in sincrono con le altre)
- Aggiunti file MyVector con template
- Gestione generale di commit e push
- Tentata risoluzione con std::array
- Iniziato tentativo di risoluzione con una classe addizionale (misura)
- Rinominato file
- Improntato costruttori
- Copia (Misura)
- operator<< (Misura)
- Sistemazione coesione stile
- Test sul main

Sara Z.
- creazione della struct che rappresenta una lettura con le relative misure (tutte double, 2 per direzione --> v e a)
- adattamento di MyVector alle nuove esigenze
- test di scrittura e stampa componente della struct lettura
- costruttore di default di Misura 
- costruttore con initializer list di Misura 
- test di misura 
NUOVE - 22/11
- test del costruttore di default di inertial_driver
- correzione costruttore di default 
- push_back() di inertial_driver 
- aggiunta is_empty e is_full in inertial_driver
- aggiunta di increment in inertial_driver

# TODO

- Bloccare esplicitamente copia e move non effettuate (Misura)
- Classe InertialDriver
- test delle varie eccezioni lanciate (es. [] con indice fuori dal range)
- sistemare alcuni commenti per le funzioni di inertial driver --> Zane: "ho scritto in velocità intanto per farvi capire cosa volevo fare"

# Problemi riscontrati e non risolti (eventualmente)