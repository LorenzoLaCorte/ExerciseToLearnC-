#ifndef _LIST_H_
#define _LIST_H_

struct cell;

typedef cell * list;

cell * newcell(const double);

cell * push_front(list&, const double);

cell * push_back(list&, const double);

cell * insert_after(list, double, int);

cell * clear(list);

void printlist(const list&);

int length(list);

list remove(list&, int);

list remove_cont(list&, double);

bool is_present(list, double);

cell * find_first(list&, double);

cell * at(list, int);

void reverse(list&);

void sort(list&);

void ordered_insert(list& mylist, double cont);

list unique(list&);

list merge(list, list);

cell * nth_from_last(list, double);

#endif
