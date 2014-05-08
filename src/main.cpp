#include <QApplication>
#include <QPushButton>
#include "PyScriptConfigurationWindow.hpp"
#include "PropertiesWindow.hpp"
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PyScriptConfigurationWindow w;
    PropertiesWindow pw;
    
    // w.show();
    pw.show();
 
    return app.exec();
}