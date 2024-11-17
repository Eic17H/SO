# Settimana 1

Il regolamento esiste per rispondere a dubbi e domande.
Se fai una domanda che non è nel regolamento, viene risposta e aggiunta al regolamento.

Questo corso trasforma gli studenti in programmatori veri e propri.
Il progetto si consegna quando è pronto. Intanto continui a correggere.

Per ora conosciamo un po' il C. Dopo il progetto lo conosceremo davvero.

Il docente di questo modulo è un po' particolare. Ha fondato un'azienda e ha due lavori.

Le mail si mandano a sistemioperativi.unica@gmail.com.
Agli indirizzi individuali non rispondono.
Bisogna fare sempre "rispondi a tutti", pessimo errore altrimenti.
Siamo (imperativo) tech-literate. Studiamo informatica, dobbiamo sapere come mandare una mail in modo corretto.

Nel mondo del lavoro capiterà spesso di dover subire le conseguenze degli errori di comunicazione.
Piccolo spoiler del nostro futuro:
> "Mettila in linea" - poco specifico
> \*la mette in linea\*
> "Noo, ma io intendo..."

Tra l'altro, sul progetto, le mail col collega in CC, sempre.
Se no è da stronzi. Succede raramente, ma comunque non è professionale.
Tu magari comunichi un sacco di cose ai docenti e il collega non ne sa nulla. Brutto.

Se copi il progetto tanto non sai fare nulla e lavoro non ne trovi.
E della laurea che te ne fai?
Ce n'era uno così, tirocinante, nell'azienda di prof. Carta. Non sapeva fare nulla.
Ma neanche ti accorgi dei tuoi difetti. E non impari niente.

Elearning. Materiale e anche esami. Leggi il regolamento.
Simulazioni di esame durante il semestre.
Il voto si può rifiutare una sola volta. In totale, quindi o teoria o pratica. Entro 7 giorni.

Per passare un modulo, la media deve essere sufficiente, anche se il singolo parziale non lo è.
Fatte tutte le esercitazioni, hai uno scheletro del progetto.
Se sai la teoria sai la pratica, quindi puoi fare il progetto.
A settembre si resettano i voti dei singoli moduli, ma non il progetto.

Il modulo di teoria ha 14 sottomoduli.
Libro di testo. E anche materiale scritto dal professor Carta.
Il libro ha problemi gravi.

Questo corso è ARE con vari strati di software a basso livello.
Ci sono cose che non si possono fare senza questo corso.
Il modo migliore per apprezzare l'aria è non respirare.
Il DevOps si occupa della parte sistemistica.
La parte applicativa e quella sistemistica si mischiano.

Noi sappiamo che dal C si passa all'ASM e poi quello gira.
Se vuoi capire cosa fa un sistema operativo devi sapere a cosa serve.
Impareremo a mappare il codice C al codice ISA.
<span class="blue">Macchina sequenziale</span>: azioni singole legate ad un clock. #termine

Alcuni argomenti del corso saranno:
- Interfacce HW-SW.
- Instruction set diverso da 8088.
- Gestione della memoria e delle periferiche.
- Usare computer senza un sistema operativo.
  
Architetture di elaborazione. Partiamo dal basso.
Cos'è un <span class="blue">processore</span>?  #termine
Macchina sequenziale che esegue esclusivamente operazioni della propria ISA.
Le <span class="green">istruzioni</span> sono stringhe di bit che stanno nella memoria, che il processore legge, decodifica ed esegue.
Le istruzioni eseguite sono legate alla lettura scrittura manipolazione di dati.
Leggere, manipolare, riscrivere dati. Dal punto di vista del processore, questo è il mondo.
Non è limitante? E le periferiche? Come fa a gestire tutto così?
Astraiamo un po'.
Dal punto di vista del processore la memoria è un indirizzo su cui scrivere e leggere. Il processore è master, il resto è slave.
Un'immagine sul monitor è una matrice di pixel, di caselle, contenenti numeri.
Il processore definisce tutto come valori negli indirizzi del data buffer.
Adesso l'universo è processore, memoria dati, memoria istruzioni, e i bus.
Cosa c'entra il codice C con questa roba qua?  
Ci si arriva, usando altre tecnologie.
Tramite la tecnologia della compilazione, la rappresentazione in codice C diventa una rappresentazione della stessa funzione in assembly.
Il programma assemblato non è più generico, ma specifico a quell'ISA.
Il codice assembly è testo, ancora non lo posso usare. Ora serve l'<span class="blue">assembler</span>.
L'<span class="blue">assembler</span> associa alle istruzioni assembly le giuste sequenze di bit. #termine