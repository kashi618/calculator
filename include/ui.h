#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>

/* Macros */
#define BUTTON_SPACING 5  // Sets spacing between buttons (try to keep it at 5)
#define BUTTON_SIZE 80    // Sets size of buttons


/* Function Signatures */
void activate(GApplication *, gpointer);
void button_setup(GtkWidget *);
void create_button(GtkWidget *, char *, int, int, int);
void button_clicked(GtkWidget *, gpointer);

#endif
