// list/list.c
// 
// Iplementation for linked list.
//
// Farouk Balogun

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>

#include "list.h"

node_t *node_alloc() {
	node_t* node = (node_t*) malloc(sizeof(node_t));
	node->next = NULL;
	return node;
}

void node_free(node_t *n) {
	free(n);
}

list_t *list_alloc() {
	list_t* list = (list_t*) malloc(sizeof(list_t));
	list->head = NULL;
	return list;
}

void list_free(list_t *l) {
	node_t* curr_ptr = l->head;
	while(curr_ptr != NULL) {
		node_t* temp = curr_ptr;
		curr_ptr = curr_ptr->next;
		node_free(temp);
	}
	free(l->head);
	l->head = NULL;
}


void list_print(list_t *l) {
	if (l == NULL) {
		printf("The list is empty.\n");
		return;
	}
	if (l->head == NULL) {
		printf("The list is empty.\n");
		return;
	}
	node_t* curr_ptr = l->head;
	while (curr_ptr != NULL){
		printf("%d\n", curr_ptr->value);
		curr_ptr = curr_ptr->next;
	}
}

int list_length(list_t *l) {
	if (l == NULL) {
		return 0;
	}
	int length = 0;
	node_t* curr_ptr = l->head;
	while (curr_ptr != NULL){
		length += 1;
		curr_ptr = curr_ptr->next;
	}
	return length;
}

void list_add_to_back(list_t *l, elem value) {
	node_t* new_node = node_alloc();
	new_node->value = value;
	if (l->head == NULL) {
		l->head = new_node;
		return;
	}
	node_t* curr_ptr = l->head;
	while (curr_ptr->next != NULL) {
		curr_ptr = curr_ptr->next;
	}
	curr_ptr->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
	node_t* new_node = node_alloc();
	new_node->value = value;
	if (l->head == NULL) {
		l->head = new_node;
		return;
	}
	new_node->next = l->head;
	l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
	if (index < 0) {
		return;
	}
	if (index >= list_length(l)) {
		list_add_to_back(l, value);
		return;
	}
	if (index == 0) {
		list_add_to_front(l, value);
		return;
	}
	int count = 0;
	node_t* new_node = node_alloc();
	new_node->value = value;
	node_t* curr_ptr = l->head;
	while (count < index-1) {
		curr_ptr = curr_ptr-> next;
		count += 1;
	}
	new_node->next = curr_ptr-> next;
	curr_ptr->next = new_node;
}

elem list_remove_from_back(list_t *l) {
	if (l->head == NULL) {
		return -1;
	}
	if (list_length(l) == 1) {
		node_t* node = l->head;
		elem value = node->value;
		node_free(node);
		l->head = NULL;
		return value;
	}
	node_t* curr_ptr = l->head;
	while (curr_ptr->next->next != NULL) {
		curr_ptr = curr_ptr->next;
	}
	node_t* node = curr_ptr->next;
	elem value = node->value;
	node_free(node);
	curr_ptr->next = NULL;
	return value;
}

elem list_remove_from_front(list_t *l) {
	if (l->head == NULL) {
		return -1;
	}
	if (list_length(l) == 1) {
		node_t* node = l->head;
		elem value = node->value;
		node_free(node);
		l->head = NULL;
		return value;
	}
	node_t* node = l->head;
	elem value = node->value;
	l->head = node->next;
	node_free(node);
	return value;
}

elem list_remove_at_index(list_t *l, int index) {
	if (l->head == NULL) {
		return -1;
	}
	if (index == 0) {
		elem value = list_remove_from_front(l);
		return value;
	}
	if (index >= list_length(l)) {
		return -1;
	}

	int count = 0;
	node_t* curr_ptr = l->head;
	while (count < index-1) {
		curr_ptr = curr_ptr-> next;
		count += 1;
	}
	node_t* node = curr_ptr->next;
	elem value = node->value;
	curr_ptr->next = curr_ptr->next->next;
	node_free(node);
	return value;
}

bool list_is_in(list_t *l, elem value) {
	node_t* curr_ptr = l->head;
	while (curr_ptr != NULL) {
		if (curr_ptr->value == value) {
			return true;
		}
		curr_ptr = curr_ptr->next;
	}
	return false;
}

elem list_get_elem_at(list_t *l, int index) {
	if (l->head == NULL) {
		return;
	}
	if (index < 0 || index >= list_length(l)) {
		return -1;
	}
	int count = 0;
	node_t* curr_ptr = l->head;
	while (count < index) {
		curr_ptr = curr_ptr->next;
		count += 1;
	}
	return curr_ptr->value;
}

int list_get_index_of(list_t *l, elem value) {
	if (l->head == NULL) {
		return -1;
	}
	int index = 0;
	node_t* curr_ptr = l->head;
	while (curr_ptr != NULL) {
		if (curr_ptr->value == value) {
			return index;
		}
		curr_ptr = curr_ptr->next;
		index += 1;
	}
	return -1;
}

