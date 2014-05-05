#ifndef PY_SCRIPT_CONFIGURATION_WINDOW_HPP
#define PY_SCRIPT_CONFIGURATION_WINDOW_HPP

#include <QtWidgets>
#include <json/json.h>
#include "HandlerConfLeaf.hpp"

class PyScriptConfigurationWindow: public QWidget
{
Q_OBJECT

public:
	PyScriptConfigurationWindow();
	~PyScriptConfigurationWindow();

public slots:
	void save();

private:
	QTabWidget *m_tab;
	QVBoxLayout *m_vbox;
	QHBoxLayout *m_hbox;
	QPushButton *m_cancelButton;
	QPushButton *m_okButton;
	HandlerConfLeaf *m_frontWindLeaf;
	HandlerConfLeaf *m_sideWindLeaf;
	HandlerConfLeaf *m_backWindLeaf;	
};

#endif