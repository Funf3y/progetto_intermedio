# Convenzioni nomi

- **File, variabili, dati e funzioni membro**: Tutto minuscolo, trattini bassi per separare le parole (snake_case)
- **Classi** (e struct): Prima lettera di ogni parola con la maiuscola, nessuno spazio, nessun trattino basso (CamelCase)
- **Costanti**: Tutto maiuscolo, parole separate da un trattino basso.

# Policy adottate

- **Costruttori classe Misura**: Tutti i valori non forniti vengono assunti nulli. Se forniti valori extra, si verifica un errore.
- **Costruttori classe Inertial Driver**: Se non viene fornito alcun parametro, la dimensione di default sarà 20. Se fornito un valore intero, verrà usato come dimensione del buffer da creare.
- **Conversione da array stile C di Letture a Misura**: Se fornito un array stile C di Letture di dimensione >= 17, allora i primi 17 elementi verranno usati per costruire la misura; se fornito un array di dimensione insufficiente, i valori mancanti saranno garbage. 

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
- Modificato file perché non usino più i template
- Funzione size (Inertial Driver)
- Scrittura del pop_front in inertial driver 
- operator << per inertial driver 
- getBack() (InertialDriver)
- Correzione gestione indici buffer circolare
- getReader() in Inertial driver
- Conversione da array (stile C) di Lettura a Misura
- Test conversione da array di Lettura a Misura


Sara Z.
- creazione della struct che rappresenta una lettura con le relative misure (tutte double, 2 per direzione --> v e a)
- adattamento di MyVector alle nuove esigenze
- test di scrittura e stampa componente della struct lettura
- costruttore di default di Misura 
- costruttore con initializer list di Misura 
- test di misura 
- test del costruttore di default di inertial_driver
- correzione costruttore di default 
- push_back() di inertial_driver 
- aggiunta is_empty e is_full in inertial_driver
- aggiunta di increment in inertial_driver
- Modificato file perché non usino più i template
- scrittura del push_back in inertial driver
- size() (InertialDriver)
- Correzione gestione indici buffer circolare
- getReader() in Inertial Driver

# TODO

- Sistemare costruttore di default di Inertial Driver
- Copia e move Inertial Driver
- Distruttore di Inertial Driver
- TEST DI GETREADER (poi il resto delle funzioni di inertial driver)
- Test delle varie eccezioni lanciate (es. [] con indice fuori dal range)
- Test delle funzioni Inerial Driver
- Sistemare alcuni commenti per le funzioni di inertial driver --> Zane: "ho scritto in velocità intanto per farvi capire cosa volevo fare"
- ULTIME 
    - SISTEMARE I COMMENTI 
    - Sistemare stampa delle spiegazioni dei test sul main
    - CONFRONTARE CODICE CON SPECIFICHE E CONVENZIONI (SLIDE) PER VEDERE SE E' TUTTO OK E CONSEGNABILE


# Problemi riscontrati e non risolti

- Costruttore di default di Inertial Driver inizializza con un buffer vuoto (invece della dimensione arbitraria decisa da noi)