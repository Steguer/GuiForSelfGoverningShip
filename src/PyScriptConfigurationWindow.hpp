#ifndef PY_SCRIPT_CONFIGURATION_WINDOW_HPP
#define PY_SCRIPT_CONFIGURATION_WINDOW_HPP

#include <QtWidgets>
#include <json/json.h>
#include "HandlerConfLeaf.hpp"
#include "PathConfigLeaf.hpp"

class PyScriptConfigurationWindow: public QWidget
{
Q_OBJECT

public:
	PyScriptConfigurationWindow();
	~PyScriptConfigurationWindow();

public slots:
	void save();
	void collectConfigFilePath();

private:
	QTabWidget *m_tab;
	QVBoxLayout *m_vbox;
	QHBoxLayout *m_hbox;
	QHBoxLayout *m_hbox2;
	QPushButton *m_cancelButton;
	QPushButton *m_okButton;
	QPushButton *m_exploreConfigFileButton;
	QLineEdit *m_editConfigFilePath;
	QLabel *m_configFilePathLabel;
	QString m_configFilePath;
	HandlerConfLeaf *m_frontWindLeaf;
	HandlerConfLeaf *m_sideWindLeaf;
	HandlerConfLeaf *m_backWindLeaf;
	PathConfigLeaf *m_pathConfigLeaf;
};

#endif