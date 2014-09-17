#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QtWidgets>
#include "PyScriptConfigurationWindow.hpp"
#include "TabTextEditor.hpp"
#include "PropertiesWindow.hpp"
#include "SendToWindow.hpp"

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
	MainWindow();
	~MainWindow();

public slots:
	void openFile();
	void saveConfigFile();
	void saveAsConfigFile();
	void openConfigFile();
	void runSendWind();

private:
	PyScriptConfigurationWindow *m_pyScripConfWid;
	TabTextEditor *m_txtEdit;
	PropertiesWindow *m_propertiesWid;
	SendToWindow *m_sendConfigToWindow;
	QDockWidget *m_pyScriptConfDock;
	QDockWidget *m_propertiesDock;
	QMenu *m_sciptFile;
	QMenu *m_confFile;
	QMenu *m_file;
	QAction *m_saveFile;
	QAction *m_newFile;
	QAction *m_openFile;
	QAction *m_closeFile;
	QAction *m_saveAsFile;

	QAction *m_saveConfigFile;
	QAction *m_newConfigFile;
	QAction *m_openConfigFile;
	QAction *m_closeConfigFile;
	QAction *m_saveAsConfigFile;

	QAction *m_quit;
	QAction *m_about;
	QAction *m_sendConfigTo;
};

#endif