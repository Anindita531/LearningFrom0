#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;                // Create main window
    window.setWindowTitle("Name Input");

    QVBoxLayout *layout = new QVBoxLayout; // Vertical layout

    QLabel *label = new QLabel("Enter your name:"); // Instruction
    QLineEdit *input = new QLineEdit;              // Input field
    QPushButton *button = new QPushButton("Submit"); // Button

    layout->addWidget(label);  // Add label to layout
    layout->addWidget(input);  // Add input to layout
    layout->addWidget(button); // Add button to layout

    window.setLayout(layout);  // Set layout to window
    window.resize(300, 150);
    window.show();

    // Event: button click
    QObject::connect(button, &QPushButton::clicked, [&](){
        QString name = input->text(); // Get text from input
        label->setText("Hello, " + name + "!"); // Update label
    });

    return app.exec();
}
