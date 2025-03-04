#pragma once // #include το πολύ μία φορά

#include "common_types.h"
#include "ADTSet.h"

// Επιστρέφει την μοναδική τιμή του set που είναι ισοδύναμη με value,
// ή αν δεν υπάρχει, την μικρότερη τιμή του set που είναι μεγαλύτερη
// από value. Αν δεν υπάρχει καμία τότε επιστρέφει NULL.

//Η υλοποίηση πρέπει να είναι αποδοτική, χωρίς να διατρέχει ολόκληρο το set.

Pointer set_find_eq_or_greater(Set set, Pointer value);



// Επιστρέφει την μοναδική τιμή του set που είναι ισοδύναμη με value,
// ή αν δεν υπάρχει, την μεγαλύτερη τιμή του set που είναι μικρότερη
// από value. Αν δεν υπάρχει καμία τότε επιστρέφει NULL.

Pointer set_find_eq_or_smaller(Set set, Pointer value);