#ifndef ITEM_H
#define ITEM_H

typedef struct s_item {
    char    *name;       // Nom de l'objet
    int      x;          // Position x sur la carte
    int      y;          // Position y sur la carte
    int      collected;  // 1 si collecté, 0 sinon
	struct s_item *next;
	
} t_item;

#endif