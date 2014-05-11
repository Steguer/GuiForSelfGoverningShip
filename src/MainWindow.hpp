#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QtWidgets>
#include "PyScriptConfigurationWindow.hpp"
#include "TabTextEditor.hpp"
#include "PropertiesWindow.hpp"

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
	MainWindow();
	~MainWindow();

public slots:
	void openFile();

private:
	PyScriptConfigurationWindow *m_pyScripConfWid;
	TabTextEditor *m_txtEdit;
	PropertiesWindow *m_propertiesWid;
	QDockWidget *m_pyScriptConfDock;
	QDockWidget *m_propertiesDock;
	QMenu *m_file;
	QAction *m_saveFile;
	QAction *m_newFile;
	QAction *m_openFile;
	QAction *m_closeFile;
};

#endif