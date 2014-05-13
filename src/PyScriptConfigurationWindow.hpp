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

	void setEditConfigFilePath(QString const& str);

public slots:
	void save();
	void loadData();

private:
	QTabWidget *m_tab;
	QVBoxLayout *m_vbox;
	QHBoxLayout *m_hbox;
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