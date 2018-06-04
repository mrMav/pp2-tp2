/*
	<license>
	MIT License

	Copyright(c) 2018 Jorge Noro

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files(the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions :

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
	</license>
	<author> Jorge Noro </author>
	<version>1.0.0</version>
	<summary>Hashstbale functions implementation</summary>
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "HashTable.h"
#include "InfoOutput.h"
#include "Utils.h"

HashTable* CreateHashTable() {

	HashTable* h = malloc(sizeof(HashTable));

	// error handling
	if (h == NULL) {

		return NULL;

	}

	for (int i = 0; i < HASH_MAX_SIZE; i++) {

		h->table[i] = NULL;

	}

	return h;

}

Node* CreateNode(int key, Flight* data) {

	Node* n = (Node*)malloc(sizeof(Node));

	// error handling
	if (n == NULL) {

		return NULL;

	}

	n->key = key;
	n->flightData = data;
	n->next = NULL;

	return n;

}

Node* AddNodeAfter(Node* node, Node* toAdd) {

	if (node == NULL || toAdd == NULL) {
		
		return NULL;

	}

	Node* n = node;

	while (n != NULL) {

		if (n == node) {

			// found node, establish links
			toAdd->next = node->next;
			node->next = toAdd;

			return toAdd;

		}

		n = n->next;

	}

	return NULL;

}

Node* ListSortAscending(Node* head) {

	if (head == NULL) {
		
		return NULL;

	}

	// bubble sort method
	// see: https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/

	Node* start;
	Node* finish = NULL;
	int swapped;

	do {

		swapped = 0;
		start = head;

		while (start->next != finish) {

			// sort criteria

			time_t startTime = mktime(start->flightData->Departure);
			time_t nextTime  = mktime(start->next->flightData->Departure);

			if (startTime > nextTime) {

				SwapNodes(start, start->next);
				swapped = 1;

			}

			start = start->next;

		}

		// this is for circular lists:
		//finish = start;

	} while (swapped);


	return head;

}

void SwapNodes(Node* a, Node* b) {

	if (a == NULL || b == NULL) {
		
		return;

	}

	Flight* temp = a->flightData;
	a->flightData = b->flightData;
	b->flightData = temp;
}

int AddNodeToHashTable(HashTable* ht, Node* n) {

	// error handling
	if (ht == NULL || n == NULL) {

		return -1;

	}

	int index = HashFunction(n->key);

	if (ht->table[index] == NULL) {
		// insert right here

		ht->table[index] = n;

	}
	else {
		
		AddNodeAfter(ht->table[index], n);

	}

	return index;

}

Node* GetNodeByKeyInList(Node* head, int key) {

	Node* n = head;

	if (n == NULL) return NULL;

	while (n != NULL) {

		if (n->key == key) {

			return n;

		}

		n = n->next;

	}

	return NULL;

}

Node* GetNodeByKeyInHashTable(HashTable* ht, int key) {

	// error handling
	if (ht == NULL) {
		
		return NULL;

	}

	int index = HashFunction(key);

	if (ht->table[index] == NULL) {

		return NULL;

	}

	return GetNodeByKeyInList(ht->table[index], key);

}

Node* RemoveNodeFromHashTable(HashTable* ht, int key) {
	// Returns the list head Node.

	if (ht == NULL) {
		
		return NULL;

	}

	Node* head = ht->table[HashFunction(key)];
	Node* toRemove = GetNodeByKeyInHashTable(ht, key);

	Node* previous = head;
	Node* current = head;

	while (current != NULL) {

		if (current == toRemove) {

			if (current == head) {
				// we are removing the top node

				ht->table[HashFunction(key)] = current->next;

				current->next = NULL;

				return current;

			}

			// found node, break links
			previous->next = current->next;
			current->next = NULL;

			return current;

		}

		previous = current;
		current = current->next;

	}

	return NULL;

}

/*
Returns flight data from the hashtable, by the unique identifier
*/
Flight* CheckHashTableForFlightID(HashTable* ht, long int id) {

	// error handling
	if (ht == NULL) {

		return NULL;

	}

	// extract key from id
	int key = ExtractKeyFromID(id);

	if (id < 1000000 && (key < 0 || key >= HASH_MAX_SIZE)) {

		return NULL;

	}

	//printf("id is %ld, key is %i\n", id, key);

	Node* head = ht->table[key];
		
	while (head != NULL) {

		if (head->flightData->ID->value == id) {

			return head->flightData;

		}

		head = head->next;
	}

	return NULL;

}

int HashFunction(int key) {

	//int sum = 0;

	//for (int i = 0; i < strlen(key); i++) {

	//	sum += (int)key[i];

	//}

	//return sum % HASH_MAX_SIZE;

	return (key - 1) % HASH_MAX_SIZE;

}

void PrintCompleteHashTable(HashTable* ht) {

	if (ht == NULL) {

		return;

	}

	for (int i = 0; i < HASH_MAX_SIZE; i++) {

		Node* head = ht->table[i];

		printf("%02i: ", i);

		while (head != NULL) {

			printf("{key: %i, data: \n", head->key);

			PrintFlight(head->flightData);

			printf("next: %p } -> \n", (void*)head->next);

			head = head->next;
		}

		printf("{ NULL } \n");

	}

}

void PrintHashTable(HashTable* ht) {

	if (ht == NULL) {

		return;

	}

	for (int i = 0; i < HASH_MAX_SIZE; i++) {

		Node* head = ht->table[i];

		if (head == NULL) continue;

		//printf("%02i: ", i);

		while (head != NULL) {

			//printf("{key: %i, data: \n", head->key);

			PrintFlightPretty(head->flightData);

			//printf("next: %p } -> \n", (void*)head->next);

			head = head->next;
		}

		//printf("{ NULL } \n");

	}

}

void DeleteNode(Node** node) {

	free(*node);
	*node = NULL;

}