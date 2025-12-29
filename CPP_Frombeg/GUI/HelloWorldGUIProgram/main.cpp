#include <QApplication>  // 1️⃣ Include QApplication (app controller)
#include <QLabel>        // 2️⃣ Include QLabel widget (for text display)

int main(int argc, char *argv[]) { // 3️⃣ Main function, entry point
    QApplication app(argc, argv);  // 4️⃣ Create application object

    QLabel label("Hello, Qt GUI!"); // 5️⃣ Create a label with text
    label.resize(300, 100);         // 6️⃣ Set window width=300, height=100
    label.show();                   // 7️⃣ Show label on screen

    return app.exec();              // 8️⃣ Start event loop (listen for events)
}
