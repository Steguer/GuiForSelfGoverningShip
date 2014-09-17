#ifndef PATH_CONFIG_LEAF_HPP
#define PATH_CONFIG_LEAF_HPP

#include <QtWidgets>
#include <json/json.h>
#include "Data.hpp"
#include "Parsser.hpp"

class PathConfigLeaf: public QWidget
{
Q_OBJECT

public:
	PathConfigLeaf();
	~PathConfigLeaf();

	QString getScriptPath();
	void setSciptPath(QString const& path);

public slots:
	void collectScriptPath();

private:
	QGridLayout *m_gbox;
	QLabel *m_scriptPathLabel;
	QLineEdit *m_editPyScriptPath;
	QPushButton *m_exploreScriptPathButton;
	QString m_scriptPath;
};

#endif