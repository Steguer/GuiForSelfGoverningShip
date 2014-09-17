#include <QApplication>
#include <QPushButton>
#include "PyScriptConfigurationWindow.hpp"
#include "PropertiesWindow.hpp"
#include "TextEditor.hpp"
#include "MainWindow.hpp"
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PyScriptConfigurationWindow w;
    PropertiesWindow pw;
    TextEditor txte;
    MainWindow mw;
    
    //w.show();
    //pw.show();

    //	txte.show();

    mw.show();	
 
    return app.exec();
}