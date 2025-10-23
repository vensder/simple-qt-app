#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "ButtonLogic.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ButtonLogic logic;

    // Create the main widget (window)
    QWidget window;
    window.setWindowTitle("Simple Qt App");
    window.resize(300, 200);

    // Set up layout
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // OK button
    QPushButton *okButton = new QPushButton("OK", &window);
    QObject::connect(okButton, &QPushButton::clicked, [&logic, &app]() {
        logic.incrementClickCount();
        app.quit();
    });

    // About button
    QPushButton *aboutButton = new QPushButton("About", &window);
    QObject::connect(aboutButton, &QPushButton::clicked, [&logic, &window]() {
        QMessageBox::information(&window, "About", QString::fromStdString(logic.getAboutMessage()));
    });

    // Add buttons to layout
    layout->addWidget(okButton);
    layout->addWidget(aboutButton);

    window.show();
    return app.exec();
}