#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Click Me!");
    button.resize(200, 100);

    // Set background and text color using stylesheet
    button.setStyleSheet("background-color: green; color: white; font-size: 18px;");

    button.show();
    return app.exec();
}

