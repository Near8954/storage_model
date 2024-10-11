#include <QApplication>
#include <QPushButton>
#include "front/App/App.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    App app;
    app.show();
    return a.exec();
}
