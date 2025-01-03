
/* 
 * File:   funcionesAuxiliares.h
 * Author: Miguelito
 *
 * Created on 25 de abril de 2024, 17:38
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void reinicia_cola(struct Cola &, struct Pila &, struct Pila &, int );
void reclasifica_pilas(struct Pila &, struct Pila &);
void ordenarPila(struct Pila &, struct Pila &);
void imprimirResultados(const struct Cola &, const struct Pila &, const struct Pila &) ;

#endif /* FUNCIONESAUXILIARES_H */

