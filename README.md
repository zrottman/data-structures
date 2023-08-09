# Data Structures

A data structures library in C.

## Node
- `CreateNode()`: create new node whose members are key/value pairs (currently supporting strings only)
- `DestroyNode()`: free memory used by Node and its members

## Linked List
Wrapper struct to hold references to head and tail plus maintain an ongoing length count.
- `CreateLinkedList()`: created new linked list
- `DestroyLinkedList()`: delete all nodes and then delete linked list
- `ll_append()`: append node to linked list
- `ll_display()`: display linked list
- `ll_delete_node()`: delete first matching node
- `ll_search()`: search for node

## Queue
Wrapper struct to hold references to head and tail plus maintain ongoing length count.
- `CreateQueue()`: create new queue
- `DestroyQueue()`: delete all nodes in queue and then delete queue
- `q_enqueue()`: add new node to queue
- `q_dequeue()`: remove node from head of queue
- `q_display()`: display all nodes in queue

## Stack
Wrapper struct to hold reference to top of stack and count.
- `CreateStack()`: allocate memory for new stack;
- `DestroyStack()`: destroy all nodes in stack and free memory for stack
- `s_pop()`: return `s->top` Node and set `s->top = s->top->next`
- `s_push()`: push new Node to top of stack and point `s->top` to it

## HashTable
- `CreateHashTable()`: creates new hashtable (size specified as argument)
- `DestroyHashTable()`: *TODO*
- `hash()`: simple hashing function that sums the ASCII values of a string and mods by hashtable size
- `ht_insert()`: inserts new key/value pair into hash table
- `ht_display()`: pretty-prints hash table
- `ht_get()`: gets matching `value` given `key`

## Graph
*TODO*

## Trie
*TODO*

## Heap
*TODO*

## Tree
*TODO*
