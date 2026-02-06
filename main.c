#include <gtk/gtk.h>

static void activate(GApplication *app, gpointer *user_data) {
    GtkWidget *win;
    
    win = gtk_application_window_new(GTK_APPLICATION(app));
    
    // Window Properties
    gtk_window_set_title(GTK_WINDOW(win), "GTK Calculator");
    gtk_window_set_default_size(GTK_WINDOW(win), 600, 800);
    gtk_window_set_resizable(GTK_WINDOW(win), FALSE);
    gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
    
    // Show window
    gtk_window_present(GTK_WINDOW(win));
}

int main(int argc, char* argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.github.kashi618.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
