
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

typedef struct Vector {
	char* head;
	size_t size;
	size_t capacity;
} Vector;

void vector_alloc(Vector* v, uint32_t capacity)
{
	v->head = (char*)malloc(capacity);
	v->capacity = capacity;
	v->size = 0;
}

bool vector_is_empty(Vector* v)
{
	return v->size == 0;
}

size_t vector_size(Vector* v)
{
	return v->size;
}

size_t vector_capacity(Vector* v)
{
	return v->capacity;
}

void vector_push(Vector* v, char c)
{
	char* slot = v->head + v->size;
	*slot = c;
	++v->size;
}

char vector_at(Vector* v, uint32_t i)
{
	return *(v->head + i);
}

void vector_insert(Vector* v, uint32_t index, char c)
{
	uint32_t items_to_move = v->capacity - index;
	for (uint32_t i = index; i < items_to_move; i++)
	{

	}
	char* slot = v->head + index;
	*slot = c;

	++v->size;
}



int main()
{
	uint32_t initial_capacity = 26;

	Vector v;
	vector_alloc(&v, initial_capacity);

	if (v.head)
	{
		printf("v is empty? %s\n", vector_is_empty(&v) ? "true" : "false");
		printf("v size: %zu\n", vector_size(&v));
		printf("v cap: %zu\n", vector_capacity(&v));

		for (uint32_t i = 0, c = (uint32_t)vector_capacity(&v); i < c; i++)
			vector_push(&v, (char)(i + 97));

		for (uint32_t i = 0, c = (uint32_t)vector_capacity(&v); i < c; i++)
			printf("v[%d]: %c\n", i, vector_at(&v, i));
	}
}
