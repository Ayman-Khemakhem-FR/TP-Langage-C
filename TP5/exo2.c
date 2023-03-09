#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct array {
	int *content;
	size_t capacity;
	size_t size;
};
typedef struct array array;

array *array_init(size_t capacity){
	array *a=malloc(sizeof(int) + 2 * sizeof(size_t));
	
	if(a == NULL){
		return NULL;
	}
	
	int *c = malloc(capacity * sizeof (int));
	
	if(c == NULL){
		free(a);
		return NULL;
	}
	
	a->content = c;
    	a->capacity = capacity;
    	a->size = 0;
    
	return a;
}

void array_destroy(array *pa){
	free(pa -> content);
	free(pa);
}

int array_get(array *pa, size_t index){
	assert(index <= (pa -> size));
	return (pa -> content[index]);
}

void array_set(array *pa, size_t index, int value){
	assert(index <= (pa -> size));
	pa -> content[index] = value;
}

void array_print(array *pa){
	for (int i =0; i< pa -> size; i++){
		printf("%d ", array_get(pa, i));
	}
	printf("\n");
}

bool array_append(array *pa, int value){
	if(pa -> size < pa -> capacity){
		pa -> size += 1;
		array_set(pa, pa -> size, value);
		return true;
	}
	return false;
}

int *array_search(array *pa, int value){
	for (int i =0; i<= pa -> size; i++){
        	if(array_get(pa,i) == value) 
			return &(pa -> content[i]);
	}
	return NULL;
}

array *array_init_from(int *data, size_t length, size_t capacity){
	assert(capacity >= length);
	array *a = array_init(capacity);
	memcpy(a -> content, data, length * sizeof(int));
	a -> size = length;
	return a;
}

void array_remove(array *pa, size_t index){
	assert(index <= pa -> size);
	memmove(pa -> content + index, pa -> content + index + 1 , (pa -> size- (index+1)) * sizeof(int));
	pa -> size -= 1;
}

int main(){
	int c[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	array *t = array_init_from(c, 10, 10);
	array_remove(t, 3);
	array_print(t);
}
