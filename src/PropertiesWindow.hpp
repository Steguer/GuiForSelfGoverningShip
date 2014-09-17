#ifndef PROPERTIES_WINDOW_HPP
#define PROPERTIES_WINDOW_HPP

#include <QtWidgets>
#include "WidgetItem.hpp"
#include "Parsser.hpp"

typedef struct PropLine PropLine;
struct PropLine
{
	QLineEdit *editText;
	QCheckBox *checkBox;
	QLabel *label;
};

class PropertiesWindow: public QScrollArea
{
Q_OBJECT

public:
	PropertiesWindow();
	~PropertiesWindow();
	void clearData();

public slots:
	void save();
	void loadData();

private:
	QGridLayout *m_gbox;
	QWidget *m_container;
	QVector<PropLine> m_widgetItem;
	
};

#endif