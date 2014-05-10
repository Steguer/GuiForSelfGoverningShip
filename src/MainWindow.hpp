#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QtWidgets>
#include "PyScriptConfigurationWindow.hpp"
#include "TabTextEditor.hpp"
#include "PropertiesWindow.hpp"

class MainWindow: public QMainWindow
{
public:
	MainWindow();
	~MainWindow();

private:
	PyScriptConfigurationWindow *m_pyScripConfWid;
	TabTextEditor *m_txtEdit;
	PropertiesWindow *m_propertiesWid;
	QDockWidget *m_pyScriptConfDock;
	QDockWidget *m_propertiesDock;
	QMenu *m_file;
	QAction *m_save;
	QAction *m_newFile;
	QAction *m_openFile;
	QAction *m_closeFile;
};

#endif