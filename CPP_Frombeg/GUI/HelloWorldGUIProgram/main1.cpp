#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Click Me!"); // Create button with text
    button.resize(200, 100);         // Set size
    button.show();                   // Show button

    // Connect button click to a function
    QObject::connect(&button, &QPushButton::clicked, [&](){
        QMessageBox::information(nullptr, "Message", "Button Clicked!");
    });

    return app.exec();
}
