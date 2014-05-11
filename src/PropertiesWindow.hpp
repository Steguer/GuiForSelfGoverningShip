#ifndef PROPERTIES_WINDOW_HPP
#define PROPERTIES_WINDOW_HPP

#include <QtWidgets>
#include "WidgetItem.hpp"
#include "Parsser.hpp"

typedef struct PropLine PropLine;
struct PropLine
{
	QLineEdit *editText;
	QLabel *label;
};

class PropertiesWindow: public QScrollArea
{
Q_OBJECT

public:
	PropertiesWindow();
	~PropertiesWindow();

public slots:
	void save();

private:
	QGridLayout *m_gbox;
	QWidget *m_container;
	std::vector<PropLine> m_widgetItemVect;
	
};

#endif