# ΑΡΧΙΤΕΚΤΟΝΙΚΗ ΠΡΟΗΓΜΕΝΩΝ ΥΠΟΛΟΓΙΣΤΩΝ

## Εργαστήριο Β' - Ομάδα 14
 
* 
* 

### **1η Εργαστηριακή Άσκηση: Εισαγωγή στον εξομοιωτή GEM5**



  Το θέμα της πρώτης εργαστηριακής άσκησης ήταν η εξοικείωση με τον εξομοιωτή υπολογιστικών συστημάτων _GEM5_, η οποία περιλάμβανε μια σειρά ερωτημάτων σκοπός των οποίων ήταν η κατανόηση των διαφορετικών μοντέλων CPU καθώς και του τρόπου με τον οποίο διάφορες παράμετροι επηρεάζουν την απόδοση του εικονικού συστήματος.



**Προεργασία:**


     Το πρόγραμμα GEM5 απαιτεί περιβάλλον Linux για την εγκατάσταση και την εκτέλεσή του. Για όσους φοιτητές δεν
    έχουν Linux στον υπολογιστή τους υπήρχε η δυνατότητα της εγκατάστασης μίας (πρόσφατης) έκδοσης Ubuntu εντός
    virtual machine πχ. πρόγραμμα VirtualBox ή στο VMWare Workstation Player 15. Επόμενο βήμα ήταν η εγκατάσταση
    μιας σειράς από βοηθητικά προγράμματα μέσω της γραμμής εντολών. Μετά ξεκινούσε το build του GEM5 με βάση
    αρχιτεκτονική τύπου ARM. Με την ολοκλήρωση αυτού του βήματος ξεκινούσε το κύριο μέρος της άσκησης.



**Ερωτήματα:**


  Μετά την επιτυχή εγκατάσταση του _GEM5_ σαν πρώτη δοκιμή έγινε εκτέλεση του προγράμματος _Hello World_ σαν πρώτο βήμα προς εξοικείωση. Σειρά είχαν τα ερωτήματα:

**Ερώτημα 1:** Ανοίξτε το αρχείο _starter_se.py_ που χρησιμοποιήσατε στο παράδειγμα του _Hello World_ και προσπαθήστε να καταλάβετε ποιες είναι βασικές παράμετροι που έχει περάσει στον gem5 για το σύστημα προς εξομοίωση. Καταγράψτε τα βασικά χαρακτηριστικά του συστήματος, όπως τύπος CPU, συχνότητα λειτουργίας, βασικές μονάδες, caches, μνήμη κτλ.                                                                                                                              

Κατεγράφησαν τα παρακάτω χαρακτηριστικά: τύπος MinorCPU, συχνότητα λειτουργίας 1GHz, 1 core, 2 private L1 caches (1 I-cache και 1 D-cache) μαζί με μία shared L2 cache και μία walk cache, όλες των 64 bytes και μνήμη χωρίς ranks μεγέθους 2GB και τύπου  DDR3_1600_8x8 που χρησιμοποιεί 2 κανάλια.


**Ερώτημα 2:** Εκτός από το αρχείο εξόδου _stats.txt_ που παράγεται στο τέλος της εξομοίωσης, ο _GEM5_ παράγει και τα αρχεία _config.ini_ και _config.json_. Τα αρχεία αυτά παρέχουν πληροφορίες για το σύστημα που εξομοιώνει ο _GEM5_.   

a. Αρχείο _config.ini_: Γραμμή 65: type=MinorCPU , γραμμή 15: cache_line_size=64

   Αρχείο _config.json_: Γραμμή 84: “cxx_class”: “MinorCPU”
                                                
b. Σύμφωνα με το αρχείο stats.txt οι «committed» εντολές είναι 5028. Οι «committed operations» είναι 5834. Τα δύο νούμερα είναι διαφορετικά γιατί κάθε εντολή (instruction) μπορεί να "αναπτύσσεται" σε μία ή περισσότερες «committed operations».Άρα οι «committed operations» είναι ίσες οι περισσότερες σε αριθμό από τις «committed instructions».

c. Σύμφωνα με το αρχείο stats.txt η L2 cache προσπελάστηκε συνολικά 479 φορές. Αν αυτή η πληροφορία δε δινόταν έτοιμη από τον εξομοιωτή θα μπορούσαμε να αθροίσουμε τις συνολικές προσπελάσεις της L2 cache για εντολές (instructions) και δεδομένα (data).                                        


**Ερώτημα 3:** Τα μοντέλα που χρησιμοποιεί ο _GEM5_ είναι τα εξής:

   -  _MinorCPU_: μοντέλο σειριακού επεξεργαστή με fixed pipeline και configurable δομές δεδομένων (data structures). Επιτρέπει την οπτικοποίηση της θέσης μιας εντολής μέσα στο pipeline και χρησιμοποιείται κυρίως στη μικρο-αρχιτεκτονική

 - _SimpleCPU_: καθαρά λειτουργικό μοντέλο που δεν απαιτεί λεπτομέρεια. Πλέον υπάρχουν τρία διαφορετικά μοντέλα: 1) BaseSimpleCPU: περιλαμβάνει συναρτήσεις που ελέγχουν για interrupts, διαμορφώνουν αιτήματα προσπέλασης και γενικά ετοιμάζουν το σύστημα για την εκτέλέση μιας εντολής. 2) AtomicSimpleCPU: εκτίμηση συνολικού χρόνου πρόσβασης στην cache μέσω της εκτίμησης latency σε ατομικές προσβάσεις. Επίσης υλοποιεί συναρτήσεις r/w, υπολογίζει τα ticks και συνδέει την CPU με την cache. 3) TimingSimpleCPU: χρησιμοποιεί συγχρονισμένες προσβάσεις στη μνήμη. Αναμένει την απόκριση της RAM πριν συνεχίσει άρα καθυστερεί την πρόσβαση στην cache.

  - _TraceCPU_: επικεντρώνεται στην επίτευξη ταχύτητας και ακρίβειας στη συνεργασία μνήμης-συστήματος.


a. Το αρχείο _trial.c_ περιέχει κώδικα που υπολογίζει το εσωτερικό γινόμενο ενός διανύσματος (σε μορφή πίνακα) με τον εαυτό του. Μετά την εκτέλεσή του το αρχείο stats.txt που δημιουργήθηκε στον αντίστοιχο φάκελο έδινε τις εξής τιμές: 16,8ms για MinorCPU και 46,172ms για TimingSimpleCPU.

b. Παρατηρείται ότι το μοντέλο TimingSimpleCPU χρειάζεται περίπου τριπλάσιο χρόνο ώστε να εκτελέσει το ίδιο πρόγραμμα. Όπως εξηγήθηκε πιο πάνω, το συγκεκριμένο μοντέλο προκαλεί σκόπιμα καθυστερήσεις στο σύστημα, ενώ το MinorCPU χρησιμοποιεί pipeline, με αποτέλεσμα να είναι πιο γρήγορο.






c. Οι τιμές των πρώτων δύο μετρήσεων πραγματοποιήθηκαν για συχνότητα λειτουργίας ίσης με 1GHz. Αυξάνοντας τη συχνότητα σε 20GHz παίρνουμε από το stats.txt χρόνο εκτέλεσης ίσο με 307μs για το MinorCPU και 366μs για το TimingSimpleCPU. Παρατηρούμε δύο πράγματα: 1) οι χρόνοι εκτέλεσης έχουν μειωθεί κατά δύο τάξεις μεγέθους και 2) ο λόγος των δύο χρόνων έχει μειωθεί στο 1,2 (από 3). Το συμπέρασμα είναι ότι ο εικοσαπλασιασμός της συχνότητας αύξησε σημαντικά την απόδοση του συστήματος, το οποίο ωστόσο δε θα συνέβαινε αν το πρόγραμμα trial.c ήταν περίπλοκο και απαιτητικό. Επίσης η μείωση τις διαφοράς οφείλεται στη μείωση των καθυστερήσεων από πλευράς της TimingSimpleCPU, η οποία τώρα αναμένει για μικρότερο χρονικό διάστημα την απόκριση της RAM.

**Συνοπτικά οι μετρήσεις:**

| CPU model       | 1GHz      | 20GHz  |  
| --------------- |:---------:|:------:|  
| MinorCPU        | 16.8   ms | 307 μs |  
| TimingSimpleCPU | 46.172 ms | 366 μs |

**Πηγές:**

   www.gem5.org

   www.m5sim.org
