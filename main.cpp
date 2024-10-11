#include <QApplication>
#include <QPushButton>
#include "App.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    App app;
    app.show();
    return a.exec();
}
