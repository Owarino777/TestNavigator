#include <QApplication>
#include "AbilityBrowser.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    AbilityBrowser browser;
    browser.show();
    return app.exec();
} 