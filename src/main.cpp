#include <QApplication>
#include <QPushButton>
#include "PyScriptConfigurationWindow.hpp"
#include "PropertiesWindow.hpp"
#include "TextEditor.hpp"
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PyScriptConfigurationWindow w;
    PropertiesWindow pw;
    TextEditor txte;
    
    // w.show();
    // pw.show();

    	txte.show();	
 
    return app.exec();
}