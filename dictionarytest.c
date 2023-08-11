#include <stdio.h>
#include "dictionary.h"
#include "linkedlist.h"
#include "node.h"

int main()
{

    /* Hash table test */
    Dictionary* dict = CreateDictionary(10);
    char *keys[] = {"hey", "sup", "morning", "goodbye", "there", "abcde", "cedba", "baedc"};
    char *vals[] = {"hola", "que pasa", "manana", "adios", "alli", "anagram 1", "anagram 2", "anagram 3"};

    printf("Adding items to dictionary:\n");
    for (int i=0; i<8; ++i)
    {
        printf("`%s` hashed to %d\n", keys[i], dictionary_set(dict, keys[i], vals[i], STRING));
    }

    printf("\nDisplaying Dictionary\n");
    dictionary_display(dict);

    printf("Adding items to dictionary:\n");
    dictionary_set(dict, "morning", &(int){1234}, INT);
    dictionary_set(dict, "a new key", "a new val", STRING);

    printf("\nDisplaying Dictionary\n");
    dictionary_display(dict);


    Node* target = dictionary_get(dict, "abcde");
    node_print(target);
    printf("\n");

    target = dictionary_get(dict, "baedc");
    node_print(target);
    printf("\n");

    target = dictionary_get(dict, "sdfasdfa");
    node_print(target);
    printf("\n");

    return 0;
}
