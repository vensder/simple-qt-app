#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the main widget (window)
    QWidget window;
    window.setWindowTitle("Simple Qt App");
    window.resize(300, 200);

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // OK button
    QPushButton *okButton = new QPushButton("OK", &window);
    QObject::connect(okButton, &QPushButton::clicked, &app, &QApplication::quit);

    // About button
    QPushButton *aboutButton = new QPushButton("About", &window);
    QObject::connect(aboutButton, &QPushButton::clicked, [&]() {
        QMessageBox::information(&window, "About", "This is a simple Qt app built with CMake.\nLearn more at qt.io!");
    });

    // Add buttons to layout
    layout->addWidget(okButton);
    layout->addWidget(aboutButton);

    window.show();
    return app.exec();
}