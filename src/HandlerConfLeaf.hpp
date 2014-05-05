#ifndef SIDE_WIND_LEAF_HPP
#define SIDE_WIND_LEAF_HPP

#include <QtWidgets>
#include <iostream>
#include "Data.hpp"
#include "Parsser.hpp"

class HandlerConfLeaf: public QWidget
{
Q_OBJECT

public:
	HandlerConfLeaf();
	HandlerConfLeaf(WindDirection dir);
	~HandlerConfLeaf();	

	QString getScriptNameHelm() const;
	QString getScriptNameSail() const;
	void setScriptNameHelm(QString const& name);
	void setScriptNameSail(QString const& name);

public slots:
	void collectScriptNameHelm();
	void collectScriptNameSail();

private:
	QGridLayout *m_gbox;
	QLabel *m_helmLabel;
	QLabel *m_sailLabel;
	QLineEdit *m_editPyScriptHelmName;
	QLineEdit *m_editPyScriptSailName;
	QPushButton *m_exploreHelmButton;
	QPushButton *m_exploreSailButton;
	QString m_scriptSailName;
	QString m_scriptHelmName;
};

#endif