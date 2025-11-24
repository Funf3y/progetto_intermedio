# Convenzioni nomi

- **File, variabili, dati e funzioni membro**: Tutto minuscolo, trattini bassi per separare le parole (snake_case)
- **Classi** (e struct): Prima lettera di ogni parola con la maiuscola, nessuno spazio, nessun trattino basso (CamelCase)
- **Costanti**: Tutto maiuscolo, parole separate da un trattino basso.

# Policy adottate

- **Costruttori classe Inertial Driver**: Se non viene fornito alcun parametro, la dimensione di default sarà 20. Se fornito un valore intero, verrà usato come dimensione del buffer da creare.
- **Copia di Inertial Driver**: Permessa solo se l'Inertial Driver in cui si copia è abbastanza grande per contenere tutti gli elementi da copiare; altrimenti si verifica un errore. Le misure vengono copiate a partire dal primo slot del nouovo buffer. 
- **Costruttori classe Misura**: Tutti i valori non forniti vengono assunti nulli. Se forniti valori extra, si verifica un errore.
- **Conversione da array stile C di Letture a Misura**: Se fornito un array stile C di Letture di dimensione >= 17, allora i primi 17 elementi verranno usati per costruire la misura; se fornito un array di dimensione insufficiente, i valori mancanti saranno garbage. 

# Attività individuali

Giulia B.
- Check e condivisione teoria, supporto (iniziali problemi tecnici)
- Implementati operatori di accesso per lettura e scrittura (Misura)
- Implementata funzione clear_buffer (Inertial Driver)
- Costruttore di default di (Inertial Driver)
- Test sul main di get_reading
- Correzione gestione del buffer circolare 
- Test sul main della sovrascrittura della lettura meno recente in buffer (caso di overflow)
- Controllo correttezza convenzioni



🗝️☁️
- Aggiunto MyVector
- Improntata classe InertialDriver
- Improntato main (verificato che includesse)
- Interfaccia pubblica di InertialDriver
- Completata interfaccia (in sincrono con le altre)
- Aggiunti file MyVector con template
- Gestione generale di commit e push
- Tentata risoluzione con std::array
- Improntata classe Misura
- Improntato costruttori
- Copia (Misura)
- operator<< (Misura)
- Sistemazione coesione stile
- Test sul main (Misura e Lettura)
- Modificato file perché non usino più i template
- Funzione size (Inertial Driver)
- Scrittura pop_front (Inertial Driver )
- operator << (Inertial driver)
- Funzione get_back() (InertialDriver)
- Correzione gestione indici buffer circolare
- getReader() (Inertial driver)
- Conversione da array (stile C) di Lettura a Misura
- Test sul main conversione da array di Lettura a Misura
- Sistemanto costruttore di default (Inertial Driver)
- Copia (Inertial Driver)
- Correzione gestione del buffer circolare 
- Test sul main della sovrascrittura della lettura meno recente in buffer (caso di overflow)
- Controllo correttezza convenzioni

Sara Z.
- Creazione struct Lettura
- Adattamento di MyVector alle nuove esigenze
- Test sul main di scrittura e stampa componente di Lettura
- Costruttore di default (Misura)
- Costruttore con initializer list (Misura)
- Test sul main (Misura e Lettura)
- Test sul main del costruttore di default di Inertial Driver
- Correzione costruttore di default (Inertial Driver)
- Funzione push_back() (Inertial Driver)
- Funzioni is_empty() e is_full() (Inertial Driver)
- Funzione increment() (Inertial Driver)
- Modificato file perché non usino più i template
- Scrittura push_back() (Inertial Driver)
- Funzione size() (InertialDriver)
- Correzione gestione indici buffer circolare
- Funzione get_reader() (Inertial Driver)
- Correzione costruttore di default (Inertial Driver)
- Test sul main dek costruttore di default di Inertial Driver 
- Correzione gestione del buffer circolare 
- Test della sovrascrittura della lettura meno recente in buffer (caso di overflow)

# TODO

- Fare in modo che BUFFER_DIM rappresenti effettivamente il numero di misure contenibili, non la dimensione del buffer
- pop_front(): quando si richiede un array stile C, la conversione funziona, ma quando lo si restituisce? Guarda forum.
- Giustifica mancato aggiornamento di attributi MyVector
- CONFRONTARE CODICE CON SPECIFICHE E CONVENZIONI (SLIDE) PER VEDERE SE E' TUTTO OK E CONSEGNABILE