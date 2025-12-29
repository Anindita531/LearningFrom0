#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QString>
#include <QChar>
#include <QDebug>

// Simple evaluator for one operation (a op b)
double simpleEval(const QString &expr) {
    QString aStr, bStr;
    QChar op;
    bool opFound = false;

    for(int i=0; i<expr.length(); i++) {
        QChar ch = expr[i];
        if(ch.isDigit() || ch == '.') {
            if(!opFound) aStr += ch;
            else bStr += ch;
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op = ch;
            opFound = true;
        }
    }

    double a = aStr.toDouble();
    double b = bStr.toDouble();
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return b != 0 ? a / b : 0;
    return 0;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt Functional Calculator");
    window.setStyleSheet("background-color: lightgray;");

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Display
    QLineEdit *display = new QLineEdit;
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet("background-color: black; color: lime; font-size: 24px; padding:5px;");
    mainLayout->addWidget(display);

    // Grid for buttons
    QGridLayout *grid = new QGridLayout;
    QStringList buttons = {
        "7","8","9","/",
        "4","5","6","*",
        "1","2","3","-",
        "0",".","C","+",
        "="
    };

    int row = 0, col = 0;
    for(int i = 0; i < buttons.size(); i++) {
        QPushButton *button = new QPushButton(buttons[i]);
        button->setStyleSheet("background-color: orange; color: white; font-size: 18px; font-weight: bold;");
        button->setFixedSize(60, 60);

        // "=" button spans full row
        if(buttons[i] == "=") {
            grid->addWidget(button, row, 0, 1, 4);
        } else {
            grid->addWidget(button, row, col);
        }

        QObject::connect(button, &QPushButton::clicked, [=, &display](){
            QString text = button->text();
            if(text == "C") {
                display->clear();
            } else if(text == "=") {
                QString expr = display->text();
                double result = simpleEval(expr);
                display->setText(QString::number(result));
            } else {
                display->setText(display->text() + text);
            }
        });

        col++;
        if(col > 3) { col = 0; row++; }
    }

    mainLayout->addLayout(grid);
    window.setLayout(mainLayout);
    window.setFixedSize(280, 400);
    window.show();

    return app.exec();
}
