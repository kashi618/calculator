#include <gtk/gtk.h>

#define BUTTON_SPACING 5
#define BUTTON_SIZE 80
#define MAX_EQUATION 100 // Maximum amount of operators and digits

static void activate(GApplication *, gpointer);
static void button_setup(GtkWidget *);
static void create_button(GtkWidget *, char *, int, int, int);
static void button_clicked(GtkWidget *, gpointer);
static void calculate();

static int  is_operator(char);
static int  is_empty(char);

char calcEq[MAX_EQUATION] = {"\0"};
int calcIndex = 0; // 0 means empty. 1 means there is one element stored at index=0

int main(int argc, char* argv[]) {
    // Setup GTK
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.github.kashi618.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}


// Starts Calculator
static void activate(GApplication *app, gpointer user_data) {
    int i;
    GtkWidget *win;

    // Window setup and properties
    win = gtk_application_window_new(GTK_APPLICATION(app));

    gtk_window_set_title(GTK_WINDOW(win), "GTK Calculator");
    gtk_window_set_default_size(GTK_WINDOW(win), 600, 800);
    gtk_window_set_resizable(GTK_WINDOW(win), FALSE);
    gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));

    // Calculator Buttons
    GtkWidget *buttonGrid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(buttonGrid), BUTTON_SPACING);
    gtk_grid_set_row_spacing(GTK_GRID(buttonGrid), BUTTON_SPACING);

    button_setup(buttonGrid);

    // Show window
    gtk_window_set_child(GTK_WINDOW(win), buttonGrid);
    gtk_window_present(GTK_WINDOW(win));

} // END activate


// Set up Calculator buttons
static void button_setup(GtkWidget *grid) {
    GtkWidget *button;
    int row, col;
    char *keys[4][5] = {
        {"7", "8", "9", "Del", "AC"},
        {"4", "5", "6", "x", "/"},
        {"1", "2", "3", "+", "-"},
        {"0",  "", ".", "=",  ""}
    };

    // Grid of keys
    for (row=0; row<4; row++) {
        for (col=0; col<5; col++) {
            // Skip second part of double grid buttons
            if (row==3 && (col==1 || col==4)) {
                continue;
            }

            button = gtk_button_new_with_label(keys[row][col]);
            gtk_widget_set_size_request(button, BUTTON_SIZE, BUTTON_SIZE);
            g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);

            // Double grid Keys (0 and =)
            if (row==3 && (col==0 || col==3)) {
                gtk_grid_attach(GTK_GRID(grid), button, col, row, 2, 1);
            }

            // Del and AC keys
            else if (row==0 && col>=3) {
                if (col==3) {
                    gtk_widget_set_margin_end(button, -BUTTON_SPACING/2);
                }
                else { // (col==4)
                    gtk_widget_set_margin_start(button, -BUTTON_SPACING/2);
                }
                gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
            }

            // Single grid keys (digits, operators, decimal)
            else {
                gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
            }
        }
    } // END for loop
} // END button_setup


static void button_clicked(GtkWidget *button, gpointer user_data) {
    const char *label = gtk_button_get_label(GTK_BUTTON(button));
    switch (label[0]) {
        case '=':
            if (is_operator(calcEq[calcIndex-1])) {
                printf("Cannot end with operator\n");
                break;
            }

            calculate();
            break;

        case 'D':
            if (calcIndex>0) {
                printf("Deleted %c\n", calcEq[--calcIndex]);
                calcEq[calcIndex] = '\0';
            }
            else {
                printf("No operations\n");
            }
            break;

        case 'A':
            printf("AC!\n");

            calcEq[0] = '\0';
            calcIndex = -1;
            break;

        default:
            // Checks if starts with operator
            if (calcIndex==0 && is_operator(label[0])) {
                printf("Cannot start with an operator!\n");
                break;
            }

            // Check if operators are repeated
            if (is_operator(calcEq[calcIndex-1]) && is_operator(label[0])) {
                printf("Cannot have multiple operators in a row\n");
                break;
            }

            // Increment calcIndex, and set it to input
            calcEq[calcIndex] = label[0];
            calcEq[++calcIndex] = '\0';
    }

    if (label[0] != '=') printf("Current equation: %s\n", calcEq);
}

static void calculate() {
    int i;
    
    printf("Calculating.........\n");
}


// Returns 1 if operator
static int is_operator(char x) {
    switch (x) {
        case '+': case '-': case 'x': case '/':
            return 1;
            break;
        default:
            return 0;
    }
}
