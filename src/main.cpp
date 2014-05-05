#include <QApplication>
#include <QPushButton>
#include "PyScriptConfigurationWindow.hpp"
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PyScriptConfigurationWindow w;
    
    w.show();
 
    return app.exec();
}