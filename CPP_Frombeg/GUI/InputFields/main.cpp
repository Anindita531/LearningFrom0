#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Input Example");

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *label = new QLabel("Enter your name:");
    QLineEdit *input = new QLineEdit;
    QPushButton *button = new QPushButton("Submit");

    layout->addWidget(label);
    layout->addWidget(input);
    layout->addWidget(button);

    window.setLayout(layout);
    window.show();

    QObject::connect(button, &QPushButton::clicked, [&](){
        QString name = input->text();
        label->setText("Hello, " + name + "!");
    });

    return app.exec();
}
