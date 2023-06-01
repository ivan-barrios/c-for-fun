#include <stdio.h>
#include <stdlib.h>
#include "istack.h"


Stack* s_create () {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->length = 0;
    return s;
}

int s_push(Stack* s, int n) {
    Nodo *aux = (Nodo *) malloc(sizeof(Nodo));
    aux->dato = n;
    aux->ptr = s->top;
    s->top = aux;
    s->length++;
    return n;
}

int s_pop (Stack* s){
    if(s->top == NULL)
        return -1;
    int n = s->top->dato;
    Nodo *aux = s->top;
    s->top = s->top->ptr;
    free(aux);
    s->length--;
    return n;
}

int s_top (Stack s){
    if (s.top == NULL)
        return -1;
    return s.top->dato;
}

int s_empty(Stack s){
    return ((s.top == NULL) || (s.length == 0));
}
int s_length(Stack s){
    return s.length;
}
