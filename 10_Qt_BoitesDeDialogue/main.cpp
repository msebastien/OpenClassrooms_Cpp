#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Translation support
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
