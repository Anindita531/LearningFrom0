#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Hello, World! Welcome to Qt GUI!");
    label.resize(400, 200); // width, height
    label.show();

    return app.exec(); // Event loop
}

