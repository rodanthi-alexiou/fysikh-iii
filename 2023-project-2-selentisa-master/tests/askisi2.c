//////////////////////////////////////////////////////////////////
//
// Unit tests για τον ADT Priority Queue.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing

#include "ADTRectree.h"
#include "ADTMap.h"

// θέτει τα στοιχεία του πίνακα array  σε τυχαία σειρά
void shuffle(int* array[], int size) {
	for (int i = 0; i < size; i++) {
		int new_pos = i + rand() / (RAND_MAX / (size - i) + 1);
		int* temp = array[new_pos];
		array[new_pos] = array[i];
		array[i] = temp;
	}
}

// Επιστρέφει έναν ακέραιο σε νέα μνήμη με τιμή value
int* create_int(int value) {
	int* p = malloc(sizeof(int));
	*p = value;
	return p;
}

int compare_ints(Pointer a, Pointer b) {
	return *(int*)a - *(int*)b;
}

void test_create(void) {
    
	Pointer value = create_int(1);
    RecTree temp = rectree_create(value, NULL, NULL);
	TEST_ASSERT(pqueue != NULL);
	TEST_ASSERT(pqueue_size(pqueue) == 0);


}	

void test_insert(void) {
	PriorityQueue pqueue = pqueue_create(compare_ints, NULL, NULL);
	int N = 1000;
	int* array = malloc(N * sizeof(*array));					// Στο pqueue θα προσθέσουμε pointers προς τα στοιχεία αυτού του πίνακα

	// insert N στοιχεία
	for (int i = 0; i < N; i++) {
		array[i] = i;
		pqueue_insert(pqueue, &array[i]);
		TEST_ASSERT(pqueue_size(pqueue) == i+1);			// Το size ενημερώθηκε;
		TEST_ASSERT(pqueue_max(pqueue) == &array[i]);	// Εισαγωγή σε αύξουσα σειρά, το στοιχείο που μόλις βάλαμε πρέπει να είναι στην κορυφή
	}

	pqueue_destroy(pqueue);
	free(array);
}

void test_remove(void) {
	PriorityQueue pqueue = pqueue_create(compare_ints, free, NULL);

	// προσθήκη δεδομένων, τυχαία σειρά
	int N = 10;
	int** array = malloc(N * sizeof(*array));
	for (int i = 0; i < N; i++)
		array[i] = create_int(i);
	shuffle(array, N);

	for (int i = 0; i < N; i++)
		pqueue_insert(pqueue, array[i]);

	// Διαδοχικά remove ώστε να συμβούν και resizes
	for (int i = N-1; i >= 0; i--) {
		int* value = pqueue_max(pqueue);
		TEST_ASSERT(*value == i);
		TEST_ASSERT(pqueue_max(pqueue) == value);
		pqueue_remove_max(pqueue);
		TEST_ASSERT(pqueue_size(pqueue) == i);
	}

	pqueue_destroy(pqueue);

	// remove από ουρά χωρίς συνάρτηση destroy
	pqueue = pqueue_create(compare_ints, NULL, NULL);
	pqueue_insert(pqueue, &N);
	TEST_ASSERT(pqueue_max(pqueue) == &N);
	pqueue_remove_max(pqueue);
	pqueue_destroy(pqueue);
	free(array);
}


// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "pqueue_create", test_create },
	{ "pqueue_insert", test_insert },
	{ "pqueue_remove_max", test_remove },

	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};