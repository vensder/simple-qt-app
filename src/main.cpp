#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QString>
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
    layout->setSpacing(10); // Add spacing between widgets for better appearance

    // OK button
    QPushButton *okButton = new QPushButton("OK", &window);
    QObject::connect(okButton, &QPushButton::clicked, [&logic, &app]() {
        logic.incrementClickCount(); // Still increments internal count
        app.quit();
    });

    // About button
    QPushButton *aboutButton = new QPushButton("About", &window);
    QLabel *clickLabel = new QLabel("Button clicked 0 time(s)", &window); // Initialize with count
    QObject::connect(aboutButton, &QPushButton::clicked, [&logic, &window, clickLabel]() {
        QMessageBox::information(&window, "About", QString::fromStdString(logic.getAboutMessage()));
        int count = logic.incrementClickCount();
        clickLabel->setText(QString("Button clicked %1 time(s)").arg(count));
    });

    // Add widgets to layout
    layout->addWidget(okButton, 0, Qt::AlignCenter);
    layout->addWidget(aboutButton, 0, Qt::AlignCenter);
    layout->addWidget(clickLabel, 0, Qt::AlignCenter);
    layout->addStretch(); // Stretch at the end to push content up slightly

    window.show();
    return app.exec();
}